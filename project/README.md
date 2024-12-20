# The Right Workplace: Authentication and Passwords
#### Video Demo:  <https://youtu.be/Uo6oVyz1zMs>
#### Description:

This project comes from joining what we learnt in cs50 week 9 content and some aspects discussed in the week 10 lecture. Therefore, my idea was to implement some aspects related to security in a Flask application. The application has been focused on login, registration and passwords and I tried to deploy some solutions that enhance security when accessing this personal information.

When loading the application running "flask run" the first screen is a login page:
-When we try to login, if we are not successful, there is a new limit of attempts. The limit established is 3 attempts per minute and 30 per day. To implement the limiter, I used the library flask_limiter, and I have used the user's IP to identify him/her. Also, it is stablished an exemption when the login is successful and when POST requests are received, that way I ensure that the user can access the content when logging in on the third attempt and prevents login tries by error, without writing anything in user and password input boxes.
-In case of not passing the data validation, it is not rendered a different screen, like it was happening in week 9, but the error is printed in the same screen so the user has a chance of knowing what is wrong and try again. Depending on the error, the message that is printed is different and the user is provided with two links depending on the situation:
    a - for any error a link that sends the user to the "register" screen.
    b - if the error is regarding an empty or invalid password the user will see also a link to "remember password"
-If the user sends the correct information, he/she will be redirected to a second screen where the user has to authenticate his identity writing a code sent to the email provided as username. I have used flask_mail for this functionality. I had to configure an email that I previously created and to jump gmail security I had to provide an application password that identifies and allows the program to use that email. I have also imported random and time to generate a random 6 digits passcode that will expire in 2 minutes.
*As I planned to send codes for other functionalities of the program I tried to avoid redundancy.  I created a route to send the email and another one to verify:
    a - send behaves in a similar way independently of the executer.
    b - verify behaves in a different way depending on if the email was sent just to authenticate in the login, to reset password or to delete the account. I could do this using session more extensively, always ensuring I delete any information I store in there.

For the registration, the user has to input an email as username, and it has data validation, apart from checking if the user already exists, a new validation to check email structure and domain is implemented. Regarding the password, the user has to input at least 8 characters, with upper and lower case, a number and include special characters. The user finally has to choose a security question between 4 options and an answer for that security question. If all is correct, a hash is generated for the password and the answer(using werzeug.security) and the 4 inputs are stores in the database "users" that now has 4 attributes.

For the option of "remember password" the user is requested to write the right email and answer the question, then the user has to pass the 2nd step authentication inputting the right code sent to his email. A thing I would and probably will change is that once the user pass all the steps and writes a new email and new email confirmation, probably it is better to redirect the user to the home page and not the login, even being less secure, it probably provides a better experience as it is very annoying to input again username, password and a code after all that process.

The option of "changing password" was easier as, knowing that the user had already logged in I just asked to write again the password and to write the new password. To make it more secure I could have added the 2nd step authentication but at that point, for some reason, I decided that it was not necessary. When inputting the new password, I added a function in my helpers file, assistant.py, that applied the Levenshtein distance principle. In this function I applied this to get the string metric that measures the difference between the two passwords, and then I compare it to the default threshold of 3. That means that I need to edit one of the passwords 3 times to be the same as the other password. This is quite moderated, and if we want to ensure that the user inputs a really different password we can always increase the threshold.

Other functions that can be executed once the user is logged in are:
-Delete/remove account, that clears the data from "users" table after requesting user's password and 2nd step authentication. Then, session is cleared and the user is redirected to the registration page.
-Log out redirects user to the login page previously clearing session.


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
