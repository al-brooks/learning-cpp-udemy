#include "Movies.hpp"
#include "MoviesUtil.hpp"
#include <iostream>

int main() {
    Movies movie_list;
    movie_list.display();
    
    add_movie(movie_list, "The Matrix", "R", 15);
    add_movie(movie_list, "Spiderman: Into the Spider-verse", "PG", 4);
    add_movie(movie_list, "My Cousin Vinny", "R", 6);
    add_movie(movie_list, "Legally Blonde", "R", 2);
    
    movie_list.display();
    
    increment_watched(movie_list, "My Cousin Vinny");
    increment_watched(movie_list, "Legally Blonde");
    
    increment_watched(movie_list, "Mulan");
    
    movie_list.display();
    
    std::cout << std::endl;
    return 0;
}
