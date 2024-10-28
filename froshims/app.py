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
    if not sport:
        return render_template("error.html", message="Missing sport")
    if sport not in SPORTS:
        return render_template("error.html", message=""Invalid sport")
                               
    for sport in request.form.getlist("sport"):
        if sport not in SPORTS:
            return render_template("failure.html")

    # This when using dropdown:
    """if not request.form.get("name") or request.form.get("sport") not in SPORTS:
        return render_template("failure.html")
    """
    return render_template("success.html")
