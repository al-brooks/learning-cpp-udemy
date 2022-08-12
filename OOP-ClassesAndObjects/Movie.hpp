#ifndef Movie_hpp
#define Movie_hpp
#include <string>

class Movie {
private:
    std::string name;
    std::string rating; // G, PG, etc.
    int watched; // count times movie has been watched.
public:
    Movie(std::string name, std::string rating, int watched);
    Movie(const Movie &source); // Copy Constructor
    ~Movie() = default;
    
    void set_name(std::string name) { this->name = name; }
    std::string get_name() const { return name; }
    
    void set_rating(std::string rating) { this->rating = rating; }
    std::string get_rating() const { return rating; }
    
    void set_watched(int watched) { this->watched = watched; }
    int get_watched() { return watched; }
    void increment_watched() { ++watched; }
    
    void display() const;
};

#endif /* Movie_hpp */
