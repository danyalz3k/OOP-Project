#include "OddOneOut.h"
#include <iostream>
#include <fstream>
#include <sstream>

void OddOneOut::play() {
    std::ifstream file("odd_one_out.txt");
    if (!file.is_open()) {
        std::cout << "Could not open the questions file.\n";
        return;
    }

    std::string line, statement, option1, option2, option3, correctOption;
    std::vector<std::string> options;

    std::cout << "Odd One Out Game:\n";

    while (getline(file, line)) {
        std::istringstream iss(line);
        getline(iss, statement, '|');
        getline(iss, option1, '|');
        getline(iss, option2, '|');
        getline(iss, option3, '|');
        getline(iss, correctOption, '|');

        std::cout << statement << "\n";
        std::cout << "1. " << option1 << "\n";
        std::cout << "2. " << option2 << "\n";
        std::cout << "3. " << option3 << "\n";

        int userChoice;
        std::cout << "Enter your choice (1-3): ";
        std::cin >> userChoice;

        std::string userAnswer;
        if (userChoice == 1) userAnswer = option1;
        else if (userChoice == 2) userAnswer = option2;
        else if (userChoice == 3) userAnswer = option3;
        else {
            std::cout << "Invalid choice.\n";
            continue;
        }

        if (userAnswer == correctOption) {
            std::cout << "Correct!\n";
        }
        else {
            std::cout << "Wrong! The correct answer was: " << correctOption << "\n";
        }
    }

    file.close();
}
