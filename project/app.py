from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, jsonify, url_for
from flask_session import Session
from flask_limiter import Limiter
from flask_limiter.util import get_remote_address
from flask_mail import Mail, message
from werkzeug.security import check_password_hash, generate_password_hash
from assistants import login_required, validate_email



# Configure application
app = Flask(__name__)

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configuring email
app.config['MAIL_SERVER'] = 'smtp.gmail.com'
app.config['MAIL_PORT'] = 587
app.config['MAIL_USE_TLS'] = True
app.config['MAIL_USERNAME'] = 'your email'
app.config['MAIL_PASSWORD'] = 'your email password'

mail = Mail(app)


# Configure databse library for SQL
db = SQL("sqlite:///project.db")

# Initialise limiter
limiter = Limiter(
    # Use client's IP address
    get_remote_address,
    app=app,
)

@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

@app.route("/")
@login_required
def index():
    return render_template("main.html")

@app.route("/login", methods=["GET", "POST"])
# Limit fail attemps: 3/min and 30/day, exempting successful logins
@limiter.limit("3 per minute", key_func=lambda: request.remote_addr, exempt_when=lambda: session.get("login_success", False), methods=["POST"])
@limiter.limit("30 per day",  key_func=lambda: request.remote_addr, exempt_when=lambda: session.get("login_success", False), methods=["POST"])
def login():
    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        email = request.form.get("email")
        password = request.form.get("password")
        # Ensure email was submitted
        if not email:
            error = "Must provide email"
            return render_template("login.html", error=error)
        # Ensure that the email format and domain are valid
        elif not validate_email(email):
            error = "Invalid email"
            return render_template("login.html", error=error)

        # Ensure password was submitted
        elif not password:
            error = "Must provide password"
            return render_template("login.html", error=error)

        # Query database for email
        rows = db.execute("SELECT * FROM users WHERE email = ?", email)

        # Ensure email exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], password):
            error = "Invalid email or password"
            return render_template("login.html", error=error)

        #Redirect to email sender
        return redirect(url_for("send", email=email))



    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/send", method=["POST"])
def send():
    email = request.args.get("email")
    # Create code in assistant.py with pyotp and time?
    # Generate and send a new verification code
    code = generate_verification_code()
    send_verification_code(email, new_code)
    # Store the new code in the session
    session["verification_code"] = new_code

    #Send email
    msg = Message("Your Verification Code", sender="your email", recipients=[email])
    msg.body = f"Your verification code is: {code}"
    mail.send(msg)

    #Remember verification code sent
    session["verification_code"] = code
    
    return render_template ("verify.html", email=email)


@app.route("/verify", methods=["GET", "POST"])
def verify():
    submitted_code = request.form.get("verification_code")
    email = request.form.get("email")
    if submitted_code == session.get("verification_code"):
        # Remove the verification code from session
        session.pop("verificaion_code", None)
        # Create dictionary with user information
        rows = db.execute("SELECT * FROM users WHERE email = ?", email)
        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]
        # Mark login ass successful
        session["login_sucess"] = True
        return redirect("/")
    else:
        error = "Please input the right code."
        return render_template("verify.html", email=email, error=error)

@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        email = request.form.get("email")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        rows = db.execute("SELECT * FROM users WHERE email = ?", email)

        # Ensure email was submitted
        if not email:
            error = "Must provide email"
            return render_template("register.html", error=error)

        elif not validate_email(email):
            error = "Must provide a valid email"
            return render_template("register.html", error=error)

        # Ensure password was submitted
        elif not password:
            error = "Must provide password"
            return render_template("register.html", error=error)

        # Password validation
        elif len(password) < 8:
            error = "Password must have at least 8 characters"
            return render_template("register.html", error=error)

        elif not any(char.isupper() for char in password):
            error = "Password must have at least one upper case character"
            return render_template("register.html", error=error)

        elif not any(char.islower() for char in password):
            error = "Password must have at least one lower case character"
            return render_template("register.html", error=error)

        elif not any(char.isdigit() for char in password):
            error = "Password must have at least one digit"
            return render_template("register.html", error=error)

        elif not any(char in ['!', '@', '#', '$', '%', '^', '&'] for char in password):
            error = "Password must have at least one of the following special characters !, @, #, $, %, ^, &"
            return render_template("register.html", error=error)

        # Ensure confirmation was submitted
        elif not confirmation:
            error = "Must provide password confirmation"
            return render_template("register.html", error=error)

        # Ensure password and confirmation match
        elif confirmation != password:
            error = "Confirmation and password do not match"
            return render_template("register.html", error=error)

        # Ensure email was not taken
        elif len(rows) == 1:
            error = "Email is taken. Please, choose a different email"
            return render_template("register.html", error=error)

        # Generate password hash
        hash = generate_password_hash(password)

        # Save user data
        db.execute("INSERT INTO users (email, hash) VALUES(?, ?)", email, hash)

        # Remember which user has logged in
        rows = db.execute("SELECT * FROM users WHERE email = ?", email)
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")


    else:
        return render_template("register.html")
