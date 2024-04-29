SELECT COUNT(title) FROM movies
    JOIN stars ON movies.id = stars.movie_id
    JOIN people ON stars.person_id = people.id
        WHERE people.name IN ('Bradley Cooper', 'Jennifer Lawrence')
        GROUP BY title;
