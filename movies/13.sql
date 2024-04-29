SELECT id FROM people
    JOIN stars ON people.id = stars.person_id
    JOIN movies ON stars.movie_id = movies.id
        WHERE people.name = 'Kevin Bacon' AND people.birth = 1958

SELECT person_id FROM stars WHERE 
SELECT movie_id FROM stars WHERE person_id IN(
    SELECT id FROM people WHERE people.name = 'Kevin Bacon' AND people.birth = 1958)

