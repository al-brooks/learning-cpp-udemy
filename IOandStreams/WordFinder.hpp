#ifndef WordFinder_hpp
#define WordFinder_hpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// 1. user enters word
// 2. read text file
// 3. increment count each time word shows up
// 4. return value

class WordFinder {
public:
    std::string get_input() {
        std::string input;
        std::cout << "Please enter the word you'd like to search for: ";
        std::cin >> input;
        
        return input;
    }
    
    std::vector<int> get_count(std::fstream &file, std::string input) {
        int total = 0;
        int count = 0;
        std::string word;
        while (file >> word) {
            if (word.find(input) != std::string::npos)
                ++count;
            ++total;
        }
        return {total, count};
    }
    
    void search_file(std::string filename) {
        std::fstream in_file;
        in_file.open(filename);
        if (!in_file) {
            std::cerr << "Problem Opening File...Goodbye" << std::endl;
        }
        
        std::string input = get_input();
        std::vector<int> counts = get_count(in_file, input);
        
        std::cout
            << "Searching through " << counts[0] << " words....\n"
            << "The word '" << input << "' was found "
            << counts[1] << " times.\n"
            << "Goodbye."
        << std::endl;
        
        std::cout << std::endl;
        in_file.close();
    }
};

#endif /* WordFinder_hpp */
