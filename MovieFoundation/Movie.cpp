#include "Movie.hpp"

Movie::Movie(string movieName, size_t movieRating, size_t movieWatched)
: movieName {movieName}, movieRating {movieRating}, movieWatched {movieWatched}
{

}

Movie::Movie(const Movie &source)
: Movie {source.movieName, source.movieRating, source.movieWatched}
{

}
