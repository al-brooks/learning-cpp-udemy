//Assignment: In this assignment, you will display a Letter Pyramid given a
//string of characters. This assignment will allow you to practice using
//loops, nested loops and std::string.

#ifndef LetterPyramid_hpp
#define LetterPyramid_hpp
#include <iostream>
#include <string>

class LetterPyramid {
public:
    void displayPyramid() {
        std::string input{};
        std::cout << "Enter in the letters you want as a pyramid - no spaces: " << std::endl;
        std::getline(std::cin, input);
        
        size_t mid_point = input.length() - 1;
        size_t end_point = mid_point * 2;
        size_t output_start {0};
        size_t output_end {0};
        size_t letter_index{0};
        char letter{};

        for(size_t i{0}; i < input.length(); ++i) {
            letter_index = 0;
            letter = input[i];
            output_start = mid_point - i;
            output_end = mid_point + i;
            for(size_t j{0}; j < output_start; ++j)
                std::cout << " ";
            while(letter_index < i)
                std::cout << input[letter_index++];
            std::cout << letter;
            while(letter_index > 0)
                std::cout << input[--letter_index];
            for(size_t k{output_end}; k < end_point; ++k)
                std::cout << " ";
            std::cout << std::endl;
        }
    }
};


#endif /* LetterPyramid_hpp */
