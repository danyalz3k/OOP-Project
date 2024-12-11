#include "Anagrams.h"
#include <algorithm>
#include <iostream>
#include <random>

void Anagrams::play() {
    std::string word = wordList[rand() % wordList.size()];  // Select a random word
    std::string scrambled = word;

    // Shuffle using modern C++ (std::shuffle)
    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(scrambled.begin(), scrambled.end(), generator);

    std::cout << "Unscramble the word: " << scrambled << std::endl;
    std::string guess;
    std::cin >> guess;

    if (guess == word) {
        std::cout << "Correct!" << std::endl;
    }
    else {
        std::cout << "Wrong! The correct word was " << word << std::endl;
    }
}
