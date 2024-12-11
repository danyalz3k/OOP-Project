#ifndef MATHCHALLENGE_H
#define MATHCHALLENGE_H

#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

class MathChallenge : public Game {
public:
    MathChallenge() : Game("Math Challenge") {}  // Set title via base class constructor
    void play() override;  // Override the play function
};

#endif
