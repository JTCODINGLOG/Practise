from flask import redirect, render_template, session
from functools import wraps
from re import match
from dns.resolver import resolve, NoAnswer, NXDOMAIN
import random
import time
from flask_mail import Message



def login_required(f):
    """
    Decorate routes to require login.

    https://flask.palletsprojects.com/en/latest/patterns/viewdecorators/
    """

    @wraps(f)
    def decorated_function(*args, **kwargs):
        if session.get("user_id") is None:
            return redirect("/login")
        return f(*args, **kwargs)

    return decorated_function

def validate_email(email):
    # Validate format with regex pattern
    pattern = r'^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$'
    if not match(pattern, email):
        return False

    # Extract domain
    domain = email.split('@')[-1]

    # Check domain with DNS lookup
    try:
        # Look for MX records of the domain
        mx_records = resolve(domain, 'MX')
        if mx_records:
            return True
    except (NoAnswer, NXDOMAIN, Exception):
        return False

def send_token(mail, ):
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
