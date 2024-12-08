#ifndef ANAGRAMS_H
#define ANAGRAMS_H

#include "Game.h"
#include <vector>
#include <string>

class Anagrams : public Game {
private:
    std::vector<std::string> wordList = {"apple", "banana", "orange", "grape"};
public:
    Anagrams() : Game("Anagrams") {}  // Constructor to set the title
    void play() override;             // Override play method
};

#endif
