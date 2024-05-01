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

Let's check bakery security logs
SELECT activity, license_plate FROM bakery_security_logs
WHERE year = 2023 AND month = 7 AND day = 28
AND hour = 10 AND minute BETWEEN 15 AND 25;
It gives me 8 license_plates:
activity:exit
license_plate: 5P2BI95, 94KL13X, 6P58WS2, 4328GD8
            G412CB7, L93JTIZ, 322W7JE, 0NTHK55

Let's check atm transactions
SELECT account_number, amount FROM atm_transactions
WHERE year = 2023 AND month = 7 AND day = 28 AND
atm_location = 'Leggett Street' AND transaction_type = 'withdraw';
Results are: account_number,amount
            28500762,48
            28296815,20
            76054385,60
            49610011,50
            16153065,80
            25506511,20
            81061156,30
            26013199,35






