-- Keep a log of any SQL queries you execute as you solve the mystery.

/*to know more details about the crime we have search its report
SELECT description FROM crime_scene_reports
WHERE year = 2023 AND month = 7 AND day = 28
AND street = 'Humphrey Street';

now that we know the specific time (10:15am) and that the 3 witnesses where
interviewed the same day, we can have a look into the interviews and maybe later the bakery security logs
(we also know that all of them mentioned the bakery)
SELECT transcript FROM interviews
WHERE year = 2023 AND month = 7 AND day = 28;

Let's check bakery security logs*/
SELECT activity, license_plate FROM bakery_security_logs
WHERE year = 2023 AND month = 7 AND day = 28
AND hour = 10 AND minute

