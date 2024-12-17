from flask import redirect, render_template, session
from functools import wraps
from re import match
from dns.resolver import resolve, NoAnswer, NXDOMAIN


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

# Levenshtein distance function without len=0 condition
def check_similar(s1, s2, threshold=4):
    if len(s1) < len(s2):
        s1, s2 = s2, s1

    previous_row = range(len(s2) + 1)
    for i, c1 in enumerate(s1):
        current_row = [i + 1]
        for j, c2 in enumerate(s2):
            insertions = previous_row[j + 1] + 1
            deletions = current_row[j] + 1
            substitutions = previous_row[j] + (c1 != c2)
            current_row.append(min(insertions, deletions, substitutions))
        previous_row = current_row

    distance = previous_row[-1]
    if distance > threshold:
        return True
    return False

