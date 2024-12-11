#ifndef ODD_ONE_OUT_H
#define ODD_ONE_OUT_H

#include "Game.h"
#include <string>
#include <vector>

class OddOneOut : public Game {
public:
    OddOneOut() : Game("Odd One Out") {}
    void play() override;
};

#endif
