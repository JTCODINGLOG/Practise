from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, jsonify, url_for
from flask_session import Session
from flask_limiter import Limiter
from flask_limiter.util import get_remote_address
from flask_mail import Mail, Message
from werkzeug.security import check_password_hash, generate_password_hash
from assistants import login_required, validate_email
import random
import time



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
app.config['MAIL_USERNAME'] = 'therightworkplace4you@gmail.com'
app.config['MAIL_PASSWORD'] = 'pesg seuj yncj zmqg'

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
        session['action'] = '2fa'
        return redirect(url_for("send", email=email))

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/send", methods=["GET","POST"])
def send():
    if request.method == "POST":
        email = request.form.get("email")
    else:
        email = request.args.get("email")
    # Generate and send a new verification code
    code = f"{random.randint(100000, 999999)}"
    expiration_time = time.time() + 120

    #Send email
    msg = Message("Your Verification Code", sender="therightworkplace4you@gmail.com", recipients=[email])
    msg.body = f"Your verification code is: {code}"
    mail.send(msg)

    #Remember verification code sent
    session["verification_code"] = code
    session["code_expiration"] = expiration_time

    return render_template ("verify.html", email=email)


@app.route("/verify", methods=["GET", "POST"])
def verify():
    submitted_code = request.form.get("verification_code")
    email = request.form.get("email")

    if (submitted_code == session.get("verification_code")) and (time.time() < session.get("code_expiration")):
        # Remove the verification code from session
        session.pop("verification_code", None)
        session.pop("code_expiration", None)
        if session.get('action') == '2fa':
            session.pop("action", None)
            # Create dictionary with user information
            rows = db.execute("SELECT * FROM users WHERE email = ?", email)
            # Remember which user has logged in
            session["user_id"] = rows[0]["id"]
            # Mark login ass successful
            session["login_success"] = True
            return redirect("/")
        # elif session.get('action') == 'reset_password':
        else:
            session.pop("action", None)
            return render_template("reset_password.html", email=email)

    else:
        error = "Wrong or expired code."
        return render_template("verify.html", email=email, error=error)

@app.route("/remember_password", methods=["GET", "POST"])
def remember_password():
    if request.method == "POST":
        step = request.form.get("step")
        email = request.form.get("email")
        rows = db.execute("SELECT * FROM users WHERE email = ?", email)
        if step == "1":
            # Ensure email was submitted
            if not email:
                error = "Must provide email"
                return render_template("/remember_password.html", step=1, error=error)
            if not validate_email(email):
                error = "Must provide a valid email"
                return render_template("/remember_password.html", step=1, error=error)
            # if all is valid and email is in database:
            if len(rows) == 1:
                # define question
                question = rows[0]["question"]
                return render_template("/remember_password.html", step=2, question=question)
            else:
                error = "Invalid email"
                return render_template("/remember_password.html", step=1, error=error)
        if step == "2":
            # check answer
            answer = request.form.get("answer")
            # validate answer
            if not answer:
                error = "Must provide an answer"
                return render_template("/remember_password.html", step=2, question=question)
            elif not check_password_hash(rows[0]["hash_answer"], answer):
                error = "Wrong answer"
                return render_template("/remember_password.html", step=2, error=error, question=question)
            else:
                session['action'] = 'reset_password'
                return redirect(url_for("send", email=email))

    return render_template("remember_password.html", step=1)

@app.route("/reset_password", methods=["GET", "POST"])
def reset_password():
        if request.method == "POST":
            password = request.form.get("password")
            confirmation = request.form.get("confirmation")

        # Ensure password was submitted
            if not password:
                error = "Must provide password"
                return render_template("reset_password.html", error=error)

            # Password validation
            elif len(password) < 8:
                error = "Password must have at least 8 characters"
                return render_template("reset_password.html", error=error)

            elif not any(char.isupper() for char in password):
                error = "Password must have at least one upper case character"
                return render_template("reset_password.html", error=error)

            elif not any(char.islower() for char in password):
                error = "Password must have at least one lower case character"
                return render_template("reset_password.html", error=error)

            elif not any(char.isdigit() for char in password):
                error = "Password must have at least one digit"
                return render_template("reset_password.html", error=error)

            elif not any(char in ['!', '@', '#', '$', '%', '^', '&'] for char in password):
                error = "Password must have at least one of the following special characters !, @, #, $, %, ^, &"
                return render_template("reset_password.html", error=error)

            # Ensure confirmation was submitted
            elif not confirmation:
                error = "Must provide new password confirmation"
                return render_template("reset_password.html", error=error)
            # New password validation
            # Ensure password and confirmation match
            elif confirmation != password:
                error = "New password and password confirmation do not match"
                return render_template("reset_password.html", error=error)

            #changing password
            hash = generate_password_hash(password)
            email = request.form.get("email")
            db.execute("UPDATE users SET hash = ? WHERE email = ?", (hash, email))
            return redirect("/")

        return render_template("reset_password.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        email = request.form.get("email")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        question = request.form.get("question")
        answer = request.form.get("answer")
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

        # Ensure question and answer are submitted
        elif not question or question not in ("first_pet", "best_friend", "favourite_brand", "favourite_color"):
            error = "Must select one of the provided questions"
            return render_template("register.html", error=error)

        elif not answer:
            error = "Must provide an answer to the question"
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

        # Generate answer hash
        hash_answer = generate_password_hash(answer)

        # Save user data
        db.execute("INSERT INTO users (email, hash, question, hash_answer) VALUES(?, ?, ?, ?)", email, hash, question, hash_answer)

        # Remember which user has logged in
        rows = db.execute("SELECT * FROM users WHERE email = ?", email)
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")


    else:
        return render_template("register.html")
