SELECT name FROM people WHERE id IN (
    SELECT id FROM movies WHERE title LIKE '%Toy Story%');
