SELECT count(name) FROM people WHERE id IN (
    SELECT id FROM movies WHERE year = 2004)
        ORDER BY birth;
