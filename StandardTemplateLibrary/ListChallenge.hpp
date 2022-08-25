// STL Section Challenge 2 - List
#ifndef ListChallenge_hpp
#define ListChallenge_hpp

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits> // clear cin buffer

class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
    : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const { return name; }
    std::string get_artist() const { return artist; }
    int get_rating() const { return rating; }
    bool operator<(const Song &rhs) const {
        return this->name < rhs.name;
    }
    bool operator==(const Song &rhs) const {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
    os  << std::setw(20) << std::left << s.name
        << std::setw(30) << std::left << s.artist
        << std::setw(2) << std::left << s.rating;
     
    return os;
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next Song" << std::endl;
    std::cout << "P = Play Previous Song" << std::endl;
    std::cout << "A = Add and play new Song at current spot" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

// Implement these functions:

void play_current(const std::list<Song> &playlist, const Song &current_song) {
    // This function should display
    // Playing: followed by the song that is playing
    std::cout << "Playing: " << current_song.get_name() << std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    // This function should display the current playlist
    // and then the current song playing.
    std::list<Song>::const_iterator curr = playlist.begin();
    std::cout << "Your Playlist: " << std::endl;
    std::cout << "---------------------------------" << std::endl;
    while (curr != playlist.end()) {
        std::cout
            << "|Song: " << (*curr).get_name()
            << "|Artist: " << (*curr).get_artist()
            << "|Rating: " << (*curr).get_rating()
            << "\n"
        << std::endl;
        ++curr;
    }
    std::cout << "---------------------------------" << std::endl;

    std::cout << "Currently Listening to: " << std::endl;
    std::cout
        << "|Song: " << current_song.get_name()
        << "|Artist: " << current_song.get_artist()
        << "|Rating: " << current_song.get_rating()
        << "\n"
    << std::endl;
}

// test solution
void list_challenge() {
    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}
    };
    
    std::list<Song>::iterator current_song = playlist.begin();
    
    std::cout << "Welcome to your Music Player App" << std::endl;
    display_playlist(playlist, *current_song);
    
    std::cout << "\n----------------------------------------------" << std::endl;
    std::cout << "Please review menu below for additional options:" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    
    char choice{};
    do {
        display_menu();
        std::cin >> choice;
        std::tolower(choice);
        if (choice == 'f') {
            current_song = playlist.begin();
            play_current(playlist, *current_song);
        } else if (choice == 'n') {
            ++current_song;
            play_current(playlist, *current_song);
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (choice != 'q');
    

    std::cout << "Thanks for listening!" << std::endl;
}

#endif /* ListChallenge_hpp */
