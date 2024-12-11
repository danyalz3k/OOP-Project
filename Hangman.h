#pragma once
#include "Game.h"
using namespace std;
#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <cctype>
#include <algorithm>

class Hangman : public Game {
public:
    void play();
    Hangman(string = "Hangman");
    bool checkWin() {
        return gameWon;
    }

private:
    bool gameWon;
    string hangman_state[7] = {
        R"(
                          +---+
                          |   |
                              |
                              |
                              |
                              |
                        =========
                        )",

        R"(
                          +---+
                          |   |
                          O   |
                              |
                              |
                              |
                        =========
                        )",

        R"(
                          +---+
                          |   |
                          O   |
                          |   |
                              |
                              |
                        =========
                        )",

        R"(
                          +---+
                          |   |
                          O   |
                         /|   |
                              |
                              |
                        =========
                        )",

        R"(
                          +---+
                          |   |
                          O   |
                         /|\  |
                              |
                              |
                        =========
                        )",

        R"(
                          +---+
                          |   |
                          O   |
                         /|\  |
                         /    |
                              |
                        =========
                        )",

        R"(
                          +---+
                          |   |
                          O   |
                         /|\  |
                         / \  |
                              |
                        =========
                        )"
    };
};
