from cs50 import SQL
from flask import Flask, redirect, render_template, request

app = Flask(__name__)

db = SQL("sqlite:///froshims.db")

SPORTS = ["Basketball", "Soccer", "Ultimate Frisbee"]

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

@app.route("/deregister", methods=["POST"])
def deregister():

    # Forget registant
    id = request.form.get("id")
    if id:
        db.execute("DELETE FROM registrants where id = ?", id)
    return redirect("/registrants")

@app.route("/register", methods=["POST"])
def register():
    name = request.form.get("name")
    sport = request.form.get("sport")
    # Validate name
    if not name:
        return render_template("error.html", message="Missing name")

    # Validate sport

    if not sport:
        return render_template("error.html", message="Missing sport")
    if sport not in SPORTS:
        return render_template("error.html", message="Invalid sport")

    # Saving registrant
    db.execute("INSERT INTO registrants (name, sport) VALUES(?, ?)", name, sport )

    # Confirm registration
    return redirect("/registrants")

@app.route("/registrants")
def registrants():
    registrants = db.execute("SELECT * FROM registrant)
    return render_template("registrants.html", registrants=registrants)


