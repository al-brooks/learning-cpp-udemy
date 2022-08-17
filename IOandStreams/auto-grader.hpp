#ifndef auto_grader_hpp
#define auto_grader_hpp

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <unordered_map>

void displayScores(std::string filename);

void displayScores(std::string filename) {
    std::ifstream in_file;
    in_file.open(filename);
    if (!in_file) {
        std::cerr << "Problem opening file" << std::endl;
    }
    std::string answer_key;
    std::string name;
    std::string answers;

    in_file >> answer_key;
    std::unordered_map<int, char> answer_map;
    for (int i = 0; i < answer_key.size(); ++i) {
        char letter = answer_key[i];
        answer_map.insert({i, letter});
    }

    const int total_width{30};
    const int name_width{25};

    std::cout
        << std::setw(name_width) << std::left << "Student"
        << "Score"
    << std::endl;

    std::cout
        << std::setw(total_width)
        << std::setfill('-') << ""
    << std::endl;

    std::cout << std::setfill(' ');

    int sum_scores = 0;
    int num_students = 0;

    while (in_file >> name >> answers) {
        int count_wrong = 0;
        ++num_students;
        for (int i = 0; i < answers.size(); ++i) {
            char solution = answer_map[i];
            if (answers[i] == solution) {
                continue;
            } else {
                ++count_wrong;
            }
        }

        int score = (int) answers.size() - count_wrong;
        sum_scores += score;
        std::cout
            << std::setw(name_width) << std::left << name
            << score << "/" << answers.size()
        << std::endl;
    }

    std::cout
        << std::setw(total_width)
        << std::setfill('-') << ""
    << std::endl;

    std::cout << std::setfill(' ');

    double avg = static_cast<double>(sum_scores) / num_students;

    std::cout
        << std::setw(name_width) << "Average Score:"
        << std::fixed << std::setprecision(2) << avg
    << std::endl;

    std::cout << std::endl;

    in_file.close();
}

#endif /* auto_grader_hpp */
