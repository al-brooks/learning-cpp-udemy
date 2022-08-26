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
    std::cout << std::endl;
    std::cout << "D - Display Playlist" << std::endl;
    std::cout << "F - Play First Song" << std::endl;
    std::cout << "N - Play Next Song" << std::endl;
    std::cout << "P = Play Previous Song" << std::endl;
    std::cout << "A = Add and play new Song at current spot" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

// Implement these functions:

void play_current(const Song &current_song) {
    // This function should display
    // Playing: followed by the song that is playing
    std::cout
        << "Playing: " << current_song.get_name()
        << " by: " << current_song.get_artist()
    << std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    // This function should display the current playlist
    // and then the current song playing.
    std::cout << "\nYour Playlist: " << std::endl;
    std::cout << std::endl;
    int count{0};
    for (const Song &song: playlist) {
        ++count;
        std::cout
            << count << ". "
            << song.get_name()
            << " by " << song.get_artist()
            << " (rating: " << song.get_rating() << ")"
        << std::endl;
    }
    std::cout << std::endl;
    play_current(current_song);
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
    
    std::cout
        << "\n------------------------------------------------"
    << std::endl;
    std::cout << "Please review menu below for additional options:" << std::endl;
    std::cout
        << "------------------------------------------------"
    << std::endl;


    char choice{};
    do {
        display_menu();
        std::cin >> choice;
        std::tolower(choice);
        std::cout << std::endl;
        if (choice == 'd') {
            display_playlist(playlist, *current_song);
        } else if (choice == 'f') {
            current_song = playlist.begin();
            play_current(*current_song);
        } else if (choice == 'n') {
            ++current_song;
            if (current_song == playlist.end()) {
                std::cout << "At end of playlist - let's restart" << std::endl;
                current_song = playlist.begin();
            }
            play_current(*current_song);
        } else if (choice == 'p') {
            if (current_song == playlist.begin()) {
                std::cout << "Sorry, there is no previous song" << std::endl;
                continue;
            } else {
                --current_song;
                play_current(*current_song);
            }
        } else if (choice == 'a') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::string name;
            std::cout << "Insert Song Name: ";
            std::getline(std::cin, name);
            
            std::string artist;
            std::cout << "\nInsert Artist Name: ";
            std::getline(std::cin, artist);

            int rating;
            std::cout << "\nInsert Song Rating: ";
            std::cin >> rating;

            current_song = playlist.insert(current_song, Song{name, artist, rating});
            std::cout << "\nSong: has been added" << std::endl;
            play_current(*current_song);
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (choice != 'q');
    

    std::cout << "Thanks for listening!" << std::endl;
}

#endif /* ListChallenge_hpp */
