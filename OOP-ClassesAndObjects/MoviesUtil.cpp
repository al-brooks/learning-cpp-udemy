#include "MoviesUtil.hpp"

void increment_watched(Movies &movies, std::string name) {
    if (movies.increment_watched(name)) {
        std::cout << name << " was watched again - increment by 1" << std::endl;
    } else {
        std::cout << name << " not found.." << std::endl;
    }
}

void add_movie(Movies &movies, std::string name, std::string rating, int watched) {
    if (movies.add_movie(name, rating, watched)) {
        std::cout << name << " was successfully added" << std::endl;
    } else {
        std::cout << name << " already exists in collection" << std::endl;
    }
}
