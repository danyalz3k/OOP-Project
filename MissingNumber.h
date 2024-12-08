// MissingNumber.h
#ifndef MISSINGNUMBER_H
#define MISSINGNUMBER_H

#include "Game.h"
#include <iostream>
#include <vector>

class MissingNumber : public Game {
public:
    MissingNumber() : Game("Missing Number") {}
    void play() override;
};

#endif

