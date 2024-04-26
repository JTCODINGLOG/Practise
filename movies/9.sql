SELECT name FROM people WHERE id = (
    SELECT id FROM movies WHERE year = 2004)
        ORDER BY birth;
