from flask import Flask, render_template, request

app = Flask(__name__)

REGISTRANTS = {}

SPORTS = ["Basketball", "Soccer", "Ultimate Frisbee"]

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

@app.route("/register", methods=["POST"])
def register():
    # This is when using checkbox or radio buttons:
    # Validate name
    if not request.form.get("name"):
        return render_template("error.html", message="Missing name")

    # Validate sport
    if not request.form.get("sport"):
        return render_template("error.html", message="Missing sport")
    if request.form.get("sport") not in SPORTS:
        return render_template("error.html", message="Invalid sport")

    # Saving registrant
    REGISTRANTS[request.form.get("name")] = request.form.get("sport")

    # Confirming registration
    return redirect("/registrants")

@app.route("/registrants")
def registrants():
    return render_template("registrants.html", registrants=REGISTRANTS)


