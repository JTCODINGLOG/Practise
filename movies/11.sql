SELECT title FROM movies
    JOIN stars ON movies.id = stars.movie_id
    JOIN ratings ON movies.id = ratings.movie_id
