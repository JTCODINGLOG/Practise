SELECT title FROM movies
    JOIN stars ON movies.id = stars.movie_id
    JOIN people ON stars.person_id = people.id
        WHERE id =people.name = 'Bradley Cooper';
