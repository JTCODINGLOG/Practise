# The Right Workplace: Authentication and Passwords
#### Video Demo:  <https://youtu.be/Uo6oVyz1zMs>
#### Description:

This project comes from joining what we learnt in cs50 week 9 content and some aspects discussed in the week 10 lecture. Therefore, my idea was to implement some aspects related to security in a Flask application. The application focus on login, registration and passwords and I tried to deploy some solutions that enhance security when accessing the website.

When loading the application running "flask run" the first screen is a login page. When we try to login, if we are not successful, there is a new limit of attempts. The limit stablished is 3 attempts per minute and 30 per day. To implement the limiter we used @limiter.limit

from cs50 import SQL
from flask import Flask, flash, redirect, session, render_template, request, session, url_for
from flask_session import Session
from flask_limiter import Limiter
from flask_limiter.util import get_remote_address
from flask_mail import Mail, Message
from werkzeug.security import check_password_hash, generate_password_hash
from functools import wraps
from re import match
from dns.resolver import resolve, NoAnswer, NXDOMAIN
