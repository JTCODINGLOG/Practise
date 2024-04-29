SELECT id FROM people
    JOIN stars ON people.id = stars.person_id
    JOIN movies ON stars.movie_id = movies.id
        WHERE people.name = 'Kevin Bacon' AND people.birth = 1958

SELECT name FROM people WHERE id IN (
    SELECT )

