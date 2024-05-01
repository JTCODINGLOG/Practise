-- Keep a log of any SQL queries you execute as you solve the mystery.

/*to know more details about the crime we have search its report
SELECT description FROM crime_scene_reports
WHERE year = 2023 AND month = 7 AND day = 28
AND street = 'Humphrey Street';

now that we know the specific time (10:15am) and that the 3 witnesses where
interviewed the same day, we can have a look into the interviews and maybe later the bakery security logs
(we also know that all of them mentioned the bakery)
SELECT name, transcript FROM interviews
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

Let's check phone calls:
SELECT caller, receiver, duration FROM phone_calls
WHERE year = 2023 AND month = 7 AND day = 28 AND
duration < 60;
Results are(caller is thief, receiver is accomplice):
caller,receiver,duration
(130) 555-0289 | (996) 555-8899, 51
(499) 555-9472 | (892) 555-8872, 36
(367) 555-5533 | (375) 555-8161, 45
(499) 555-9472 | (717) 555-1342, 50
(286) 555-6063 | (676) 555-6554, 43
(770) 555-1861 | (725) 555-3243, 49
(031) 555-6622 | (910) 555-3251, 38
(826) 555-1652 | (066) 555-9701, 55
(338) 555-6650 | (704) 555-2131, 54

Let's try to connect caller(phone_calls) and license_plate(bakery_security_logs)
SELECT name, passport_number FROM people WHERE phone_number IN
(SELECT caller FROM phone_calls
WHERE year = 2023 AND month = 7 AND day = 28 AND
duration < 60) AND license_plate IN
(SELECT license_plate FROM bakery_security_logs
WHERE year = 2023 AND month = 7 AND day = 28
AND hour = 10 AND minute BETWEEN 15 AND 25);
Results (no one is the interviewee):
name, passport_number
Sofia, 1695452385
Diana, 3592750733
Kelsey, 8294398571
Bruce, 5773159633

Let's try now to connect the last results to the flights
SELECT id, destination_airport_id FROM flights WHERE origin_airport_id =(
        SELECT id FROM airports WHERE city = 'Fiftyville')
    AND year = 2023 AND month = 7 AND day = 29 ORDER BY hour ASC LIMIT 1;
Results:
flight.id = 36
destination_airport_id = 4

***What city the thief escaped to?
SELECT city FROM airports WHERE id = (
        SELECT destination_airport_id FROM flights WHERE origin_airport_id =(
            SELECT id FROM airports WHERE city = 'Fiftyville')
        AND year = 2023 AND month = 7 AND day = 29 ORDER BY hour ASC LIMIT 1);

Lets try to guess the name (we have to link it with atm transactions):*/

SELECT name, passport_number FROM people WHERE phone_number IN
    (SELECT caller FROM phone_calls WHERE year = 2023 AND month = 7 AND day = 28 AND duration < 60)
    AND license_plate IN
    (SELECT license_plate FROM bakery_security_logs WHERE year = 2023 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25)
    AND passport_number IN
    (SELECT passport_number FROM passengers WHERE flight_id =
        (SELECT id FROM flights WHERE origin_airport_id =
            (SELECT id FROM airports WHERE city = 'Fiftyville')
        AND year = 2023 AND month = 7 AND day = 29 ORDER BY hour ASC LIMIT 1)
    );
















