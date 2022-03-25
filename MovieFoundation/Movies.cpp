#include "Movies.hpp"

bool Movies::addMovie(const Movie &source)
{
    if(movieList.size() == 0)
    {
        movieList.push_back(source);
        cout << source.movieName << " added." << endl;
        return true;
    }

    for(size_t i {0}; i < movieList.size(); ++i)
    {
        if(source.movieName == movieList.at(i).movieName)
        {
            cout << "Sorry the movie already exists." << endl;
            return false; 
        }
    }
    movieList.push_back(source);
    cout << source.movieName << " added." << endl;
    return true; 
}

bool Movies::addMovie(string name, size_t rating, size_t movieWatched)
{
    if(movieList.size() == 0)
    {
        movieList.push_back(Movie {name, rating, movieWatched});
        cout << name << " added." << endl;
        return true;
    }

    for(size_t i {0}; i < movieList.size(); ++i)
    {
        if(name == movieList.at(i).movieName)
        {
            cout << "Sorry the movie already exists." << endl;
            return false;
        }
    }
    movieList.push_back(Movie {name, rating, movieWatched});
    cout << name << " added." << endl;
    return true;
}

bool Movies::incrementWatchMovie(const Movie &source)
{
    if(movieList.size() == 0)
    {
        return false;
    }

    for(size_t i {0}; i <= movieList.size(); ++i)
    {
        if(source.movieName == movieList.at(i).movieName)
        {
            ++movieList.at(i).movieRating;
            return true;
        }
    }
    return false;
}

bool Movies::incrementWatchMovie(string name)
{
    for(size_t i {0}; i < movieList.size(); ++i)
    {
        if(movieList.size() != 0 && name == movieList.at(i).movieName)
        {
            ++movieList.at(i).movieRating;
            return true;
        }
    }
    return false;
}

void Movies::displayMovies() const
{
    if(movieList.size() == 0)
    {
        cout << "No movies in the collection. " << endl;
        return;
    }
    else
    {
        // cout << "+" << std::setw(45) << std::setfill('=') << "+" << endl;
        //     cout << "|" << std::setw(30) << std::setfill(' ') << "Movie";
        //     cout << "| " << std::setw(5) << std::setfill(' ') << "Rate"; 
        //     cout << "| " << std::setw(5) << std::setfill(' ') << "W.T." << "|" << endl;
            
        for(size_t i {0}; i < movieList.size(); ++i)
        {
            cout << "+" << std::setw(45) << std::setfill('=') << "+" << endl;
            cout << "|" << std::setw(30) << std::setfill(' ') << movieList.at(i).movieName;
            cout << "| " << std::setw(5) << std::setfill(' ') << movieList.at(i).movieRating; 
            cout << "| " << std::setw(5) << std::setfill(' ') << movieList.at(i).movieWatched << "|" << endl;
        }
        cout << "+" << std::setw(45) << std::setfill('=') << "+" << endl;
    }
}

