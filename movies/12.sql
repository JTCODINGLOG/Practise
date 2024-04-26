SELECT title FROM movies
    JOIN stars ON movies.id = stars.movie_id
    JOIN people ON stars.person_id = people.id
        CASE
            WHEN (SELECT id FROM people WHERE name = 'Bradley Cooper') =
                 (SELECT id FROM people WHERE name = 'Jennifer Lawrence')
