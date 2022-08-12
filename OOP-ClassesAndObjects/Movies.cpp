#include "Movies.hpp"
#include <iostream>

// Move Constructor
Movies::Movies(Movies &&source)
: movies{source.movies} {
    source.movies = nullptr;
}

bool Movies::add_movie(std::string name, std::string rating, int watched) {
    for (const Movie &movie: *movies) {
        if (movie.get_name() == name) {
            return false;
        }
    }
    Movie temp{name, rating, watched};
    movies->push_back(temp);
    return true;
}

bool Movies::increment_watched(std::string name) {
    for (Movie &movie: *movies) {
        if (movie.get_name() == name) {
            movie.increment_watched();
            return true;
        }
    }
    return false;
}


