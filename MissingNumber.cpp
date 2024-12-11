#include "MissingNumber.h"

void MissingNumber::play() {
    int start = rand() % 10 + 1;
    int diff = rand() % 5 + 1;
    int missingIndex = rand() % 5;
    std::vector<int> sequence;

    for (int i = 0; i < 5; ++i) {
        if (i == missingIndex) {
            sequence.push_back(-1);  // Placeholder for missing number
        }
        else {
            sequence.push_back(start + i * diff);
        }
    }

    std::cout << "Find the missing number in the sequence: ";
    for (int num : sequence) {
        if (num == -1) {
            std::cout << "? ";
        }
        else {
            std::cout << num << " ";
        }
    }
    std::cout << std::endl;

    int answer = start + missingIndex * diff;
    int guess;
    std::cin >> guess;

    if (guess == answer) {
        std::cout << "Correct!" << std::endl;
    }
    else {
        std::cout << "Wrong! The correct number was " << answer << std::endl;
    }
}
