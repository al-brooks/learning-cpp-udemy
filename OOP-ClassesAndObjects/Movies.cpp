#include "Movies.hpp"
#include <iostream>

bool Movies::add_movie(std::string name, std::string rating, int watched) {
    for (const Movie &movie: movies) {
        if (movie.get_name() == name) {
            return false;
        }
    }
    Movie temp{name, rating, watched};
    movies.push_back(temp);
    return true;
}

bool Movies::increment_watched(std::string name) {
    for (Movie &movie: movies) {
        if (movie.get_name() == name) {
            movie.increment_watched();
            return true;
        }
    }
    return false;
}

void Movies::display() const {
    if (movies.size() == 0) {
        std::cout << "\nSorry, there are no movies to display.\n" << std::endl;
    } else {
        std::cout << "\nCurrent Movies:" << std::endl;
        std::cout << "===============================================" << std::endl;
        for (const Movie &movie: movies)
            movie.display();
        std::cout << "===============================================\n" << std::endl;
    }
}
