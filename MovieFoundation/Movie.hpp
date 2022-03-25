#pragma once
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Movie {
private:
    string movieName;
    size_t movieRating;
    size_t movieWatched;
    friend class Movies;
public:
    Movie(string movieName, size_t movieRating, size_t movieWatched = 0);
    Movie(const Movie &source);
        
};