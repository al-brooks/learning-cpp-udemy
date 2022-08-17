#ifndef CopyRomeoAndJuliet_hpp
#define CopyRomeoAndJuliet_hpp
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

class CopyRomeoAndJuliet {
public:
    void copy_file(std::string file_name) {
        std::ifstream in_file{file_name};
        std::ofstream out_file("new-romeo-juliet.txt");
        if (!in_file) {
            std::cerr << "An Error Occurred Reading the Input File" << std::endl;
        }
        if (!out_file) {
            std::cerr << "An Error Occurred Creating the Output File" << std::endl;
        }
        
        int line_count = 0;
        std::string line;
        while (std::getline(in_file, line)) {
            ++line_count;
            if (line.length() > 0) {
                out_file << std::setw(8) << std::left << line_count << line << std::endl;
            } else {
                out_file << std::setw(5) << std::setfill(' ') << line << std::endl;
            }
        }
        
        std::cout << "File Copied" << std::endl;
        in_file.close();
        out_file.close();
    }
};

#endif /* CopyRomeoAndJuliet_hpp */
