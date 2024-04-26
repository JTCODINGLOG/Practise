SELECT name FROM people WHERE id IN (
    SELECT 
    SELECT id FROM movies WHERE title LIKE '%Toy Story%');
