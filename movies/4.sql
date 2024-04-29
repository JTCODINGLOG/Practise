SELECT COUNT(title) FROM movie WHERE id IN (
    movie_id FROM ratings WHERE rating = 10.0);
