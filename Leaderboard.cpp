#include "Leaderboard.h"
#include <iostream>
#include <algorithm>

void displayLeaderboard(const std::vector<Player>& players) {
    std::vector<Player> sortedPlayers = players;
    std::sort(sortedPlayers.begin(), sortedPlayers.end(), [](const Player& a, const Player& b) {
        return a.getBadgeCount() > b.getBadgeCount();
    });

    std::cout << "Leaderboard:" << std::endl;
    for (const auto& player : sortedPlayers) {
        std::cout << player.getUsername() << ": " << player.getBadgeCount() << " badges" << std::endl;
    }
}
