from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


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
    """Show portfolio of stocks"""
    user_id = session["user_id"]
    index = db.execute("""SELECT symbol, SUM(shares) FROM purchases
                       WHERE user_id=?
                       GROUP BY symbol
                       HAVING SUM(shares) > 0"""
                       , user_id)

    stotal = 0
    for row in index:
        price = float(lookup(row["symbol"])["price"])
        total = price * row["SUM(shares)"]
        row.update({"price": usd(price), "TOTAL": usd(total)})
        stotal += total

    cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]
    stotal += cash
    return render_template("index.html", index=index, cash=usd(cash), stotal=usd(stotal))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":

        symbol = (request.form.get("symbol")).upper()
        shares = request.form.get("shares")

        #data validation
        if not symbol:
            return apology("missing symbol", 400)
        if not shares:
            return apology("missing shares", 400)
        if int(shares) < 1:
            return apology("invalid shares", 400)
        if not lookup(symbol):
            return apology("invalid symbol", 400)

        #check price
        price = float(lookup(symbol)["price"])

        #check cash of the user
        user_id = session["user_id"]
        rows = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
        cash = float(rows[0]["cash"])
        shares = int(shares)
        shares_price = price*shares

        #check if user can buy
        if cash < shares_price:
            return apology("can't afford", 400)

        cash = cash - shares_price
        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash, user_id)
        db.execute("""INSERT INTO purchases (user_id, symbol, shares, price)
                   VALUES (?, ?, ?, ?)""", user_id, symbol, shares, shares_price)

        return redirect("/")
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    user_id = session["user_id"]
    rows = db.execute("SELECT symbol, shares, price, purchase_time FROM purchases WHERE user_id=?", user_id)
    return render_template("history.html", rows=rows)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

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


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        if lookup(symbol):
            lookedup = lookup(symbol)
            name = lookedup["name"]
            price = lookedup["price"]
            symbol = lookedup["symbol"]
            return render_template("quoted.html", name=name, price=price, symbol=symbol)
        return apology("invalid symbol", 400)
    else:
        return render_template("quote.html")

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
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not password:
            return apology("must provide password", 403)

        # Ensure confirmation was submitted
        elif not confirmation:
            return apology("must provide password confirmation", 403)

        # Ensure password and confirmation match
        elif confirmation != password:
            return apology("passwords do not match", 400)

        # Ensure username was not taken
        elif len(rows) == 1:
            return apology("user taken", 400)

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


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    user_id = session["user_id"]

    if request.method == "POST":

        symbol = (request.form.get("symbol")).upper()
        shares = int(request.form.get("shares"))

        #data validation
        if not symbol:
            return apology("missing symbol", 400)
        if not shares:
            return apology("missing shares", 400)
        if shares <= 0:
            return apology("shares must be positive", 400)
        if not lookup(symbol):
            return apology("invalid symbol", 400)

        #check price
        price = float(lookup(symbol)["price"])

        #check shares of the user for that symbol
        rows_0 = db.execute("SELECT SUM(shares) FROM purchases WHERE user_id=? and symbol=? GROUP BY symbol", user_id, symbol)
        shares_user = int(rows_0[0]["SUM(shares)"])

        rows_1 = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
        cash = float(rows_1[0]["cash"])

        #check if user can buy
        if shares_user < shares:
            return apology("too many shares", 400)

        shares_price = price*shares
        cash = cash + shares_price
        shares = -1 * shares
        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash, user_id)
        db.execute("""INSERT INTO purchases (user_id, symbol, shares, price)
                   VALUES (?, ?, ?, ?)""", user_id, symbol, shares, shares_price)

        return redirect("/")
    else:
        symbols = db.execute("SELECT symbol FROM purchases WHERE user_id=? GROUP BY symbol", user_id)
        return render_template("sell.html", symbols=symbols)

