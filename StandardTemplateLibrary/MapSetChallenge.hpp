// STL Challenge 3 - Maps & Sets
#ifndef MapSetChallenge_hpp
#define MapSetChallenge_hpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <map>
#include <set>
#include <string>
#include <iomanip>

// Part 1 - Display word and count from:
// std::map<std::string, int>

void display_words(const std::map<std::string, int> &words) {
    std::cout
        << std::setw(12) << std::left << "\nWord"
        << std::setw(7) << std::right << "Count"
    << std::endl;
    std::cout << "================================" << std::endl;
    for (auto pair: words) {
        std::cout
            << std::setw(12) << std::left << pair.first
            << std::setw(7) << std::right << pair.second
        << std::endl;
    }
}

// Part 2 - Display word and occurences from:
// std::map<std::string, std::set<int>>

void display_words(const std::map<std::string, std::set<int>> &words) {
    std::cout
        << std::setw(12) << std::left << "\nWord"
        << "Occurrences"
    << std::endl;
    std::cout << "================================" << std::endl;
    for (auto pair: words) {
        std::cout
        << std::setw(12) << std::left << pair.first << std::left << "[ ";
        for (auto i: pair.second)
            std::cout << i << " ";
        std::cout << "]" << std::endl;
    }
}

std::string clean_string(const std::string &s) {
    std::string result;
    for (char c: s) {
        if (c == '.' || c == ',' || c == ';' || c == ':') {
            continue;
        } else {
            result += c;
        }
    }
    return result;
}

// process file and build map of words and the number of occurrences
void part1() {
    std::map<std::string, int> words;
    std::string line;
    std::string word;
    std::ifstream in_file{"words.txt"};
    if (in_file) {
        while (std::getline(in_file, line)) {
            // use string stream to read words from lines
            // string stream will skip over spaces as well
            std::stringstream ss(line);
            while (ss >> word) {
                word = clean_string(word);
                words[word]++;
            }
        }
        
        in_file.close();
        display_words(words);
    } else {
        std::cerr << "Error opening input file" << std::endl;
    }
}

// process file and build map of words and set of line numbers where
// word appears
void part2() {
    std::map<std::string, std::set<int>> words;
    std::string line;
    std::string word;
    std::ifstream in_file{"words.txt"};
    if (in_file) {
        int line_num = 0;
        while (std::getline(in_file, line)) {
            ++line_num;
            std::stringstream ss(line);
            while (ss >> word) {
                word = clean_string(word);
                words[word].insert(line_num);
            }
        }
        
        in_file.close();
        display_words(words);
    } else {
        std::cerr << "Error opening input file" << std::endl;
    }
}

void map_set_challenge() {
//    part1();
    part2();
}

#endif /* MapSetChallenge_hpp */
