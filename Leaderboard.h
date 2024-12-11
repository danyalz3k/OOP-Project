#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <vector>
#include "Player.h"

// Function to display the leaderboard
void displayLeaderboard(const std::vector<Player>& players);
void saveLeaderboard(const std::vector<Player>& players);
void loadLeaderboard(std::vector<Player>& players);

#endif
