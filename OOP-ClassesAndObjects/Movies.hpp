// Models a collection of Movie classes in vector

#ifndef Movies_hpp
#define Movies_hpp
#include "Movie.hpp"
#include <vector>
#include <string>

class Movies {
private:
    std::vector<Movie> movies;
public:
    Movies() = default;
    ~Movies() = default;
    
    bool add_movie(std::string name, std::string rating, int watched);
    bool increment_watched(std::string name);
    void display() const;
};

#endif /* Movies_hpp */
