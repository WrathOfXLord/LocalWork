#pragma once
#include "Movie.hpp"
#include <vector>
#include <iomanip>

class Movies {
private:
    std::vector<Movie> movieList;
    friend class Movie;
public:
    bool addMovie(const Movie &source);
    bool addMovie(string name, size_t rating, size_t movieWatched = 0);
    bool incrementWatchMovie(const Movie &source);
    bool incrementWatchMovie(string name);
    void displayMovies() const;

};