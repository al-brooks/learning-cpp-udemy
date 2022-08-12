#ifndef MoviesUtil_hpp
#define MoviesUtil_hpp

#include "Movies.hpp"
#include <iostream>

void increment_watched(Movies &movies, std::string name);
void add_movie(Movies &movies, std::string name, std::string rating, int watched);

#endif /* MoviesUtil_hpp */
