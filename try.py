#!/usr/bin/python3
import os
import smtplib
from email.mime.text import MIMEText

def send_email(subject, body, to_email):
    sender_email = "try9747@gmail.com"
    sender_password = "lgprdsyzaukrwetw"
    message = MIMEText(body)
    message["Subject"] = subject
    message["From"] = sender_email
    message["To"] = to_email
    with smtplib.SMTP("smtp.gmail.com", 587) as server:
        server.starttls()
        server.login(sender_email, sender_password)
        server.sendmail(sender_email, to_email, message.as_string())
subject = "School project"
script_directory = os.path.dirname(os.path.realpath(__file__))
text_file_path = os.path.join(script_directory, "emailfile.txt")

with open(text_file_path, "r") as file:
    line = file.readline()
    body = file.read()

recipient_email = line

send_email(subject, body, recipient_email)
