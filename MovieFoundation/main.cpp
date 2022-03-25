#include "Movies.hpp"

using namespace std;

int main()
{
    Movies newCollection;
    newCollection.addMovie("The Dark Knight", 5, 0);
    newCollection.addMovie("Star Wars The Old Republic", 4);
    newCollection.addMovie(Movie {"The Dark Knight", 5, 0});
    newCollection.addMovie("The Dark Knight", 5, 0);
    newCollection.displayMovies();

    return 0;
}