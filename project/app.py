from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, jsonify
from flask_session import Session
from flask_limiter import Limiter
from flask_limiter.util import get_remote_address
from werkzeug.security import check_password_hash, generate_password_hash

from assistants import login_required

# Configure application
app = Flask(__name__)

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

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
# Limit of 3 login attemps per minute
@limiter.limit("3 per minute", key_func=lambda: request.remote.addr, exempt_when=lambda: session.get("login_success", False))
@limiter.limit("30 per day",  key_func=lambda: request.remote.addr, exempt_when=lambda: session.get("login_success", False))
def login():
    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        # Ensure username was submitted
        if not username:
            return "must provide username"

        # Ensure password was submitted
        elif not password:
            return "must provide password"

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", username)

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")

@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        rows = db.execute("SELECT * FROM users WHERE username = ?", username)

        # Ensure username was submitted
        if not username:
            return "must provide username"

        # Ensure password was submitted
        elif not password:
            return "must provide password"

        # Ensure confirmation was submitted
        elif not confirmation:
            return "must provide password confirmation"

        # Ensure password and confirmation match
        elif confirmation != password:
            return "passwords do not match"

        # Ensure username was not taken
        elif len(rows) == 1:
            return "user taken"

        # Generate password hash
        hash = generate_password_hash(password)

        # Save user data
        db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", username, hash)

        # Remember which user has logged in
        rows = db.execute("SELECT * FROM users WHERE username = ?", username)
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")


    else:
        return render_template("register.html")
