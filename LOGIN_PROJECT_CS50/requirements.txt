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
