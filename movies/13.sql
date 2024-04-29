/*FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE people.name != 'Kevin Bacon'
AND movies.id IN (
    SELECT movie_id
    FROM stars
    WHERE person_id = (
        SELECT id
        FROM people
        WHERE name = 'Kevin Bacon' AND birth = 1958
    )
)*/


SELECT COUNT(name) FROM people WHERE id IN (
    SELECT person_id FROM stars WHERE movie_id IN(
        SELECT movie_id FROM stars WHERE person_id IN(
            SELECT id FROM people WHERE people.name = 'Kevin Bacon' AND people.birth = 1958)))
 AND name NOT LIKE 'Kevin Bacon';

