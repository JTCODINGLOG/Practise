# The Right Workplace: Authentication and Passwords
#### Video Demo:  <https://youtu.be/Uo6oVyz1zMs>
#### Description:

This project comes from joining what we learnt in cs50 week 9 content and some aspects discussed in the week 10 lecture. Therefore, my idea was to implement some aspects related to security in a Flask application. The application has been focused on login, registration and passwords and I tried to deploy some solutions that enhance security when accessing this personal information.

When loading the application running "flask run" the first screen is a login page:
-When we try to login, if we are not successful, there is a new limit of attempts. The limit stablished is 3 attempts per minute and 30 per day. To implement the limiter I used the library flask_limiter, and I have used the user's IP to identify him/her. Also, it is stablished an exemption when the login is successful and when POST requests are received, that way I ensure that the user can access the content when logging in on the third attemp and prevents login tries by error, without writing anything in user and password input boxes.
-In case of not passing the data validation, it is not rendered a different screen like it was happening in week 9, but the error is printed in the same screen so the user has a chance of knowing what is wrong and try again. Depending on the error, the message that is printed is different and also the user is provided with two links depending on the situation:
    a - for any error a link that send the user to the "register" screen.
    b - if the error is regarding an empty or invalid password the user will see also a link to "remember password"
-If the user sends the correct information, he/she will be redirected to a second screen where the user has to authenticate his identity writing a code sent to the email provided as username. I have used flask_mail for this functionality. I had to configure an email that I previously created and to jump gmail security I had to provide an application password that identifies and allows the program to use that email. I have also imported random and time to generate a random 6 digit passcode that will expire in 2 minutes.
*As I planned to send codes for another functionalities of the program I tried to avoid redundancy.  I created a route to send the email and another one to verify:
    a - send behaves in a similar way independently of the executer.
    b - verify behaves in a different way depending if the email was sent just to authenticate in the login, to reset password or to delete the account. I could do this using session more extensively, always ensuring I delete any information I store in there.



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
