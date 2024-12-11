#include "Leaderboard.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>  // Include for std::istringstream

void displayLeaderboard(const std::vector<Player>& players) {
    std::vector<Player> sortedPlayers = players;
    // Sort players by badge count
    std::sort(sortedPlayers.begin(), sortedPlayers.end(), [](const Player& a, const Player& b) {
        return a.getBadgeCount() > b.getBadgeCount();
        });

    std::cout << "Leaderboard:" << std::endl;
    for (const auto& player : sortedPlayers) {
        std::cout << player.getUsername() << ": " << player.getBadgeCount() << " badges" << std::endl;
    }
}

void saveLeaderboard(const std::vector<Player>& players) {
    std::ofstream file("leaderboard.txt", std::ios::out);  // Save leaderboard
    if (!file.is_open()) {
        std::cerr << "Error: Could not open leaderboard.txt for writing.\n";
        return;
    }

    for (const auto& player : players) {
        file << player.getUsername() << "," << player.getBadgeCount();  // Save username and badge count
        file << "\n";
    }

    file.close();
}

void loadLeaderboard(std::vector<Player>& players) {
    std::ifstream file("leaderboard.txt");
    if (!file.is_open()) {
        std::cerr << "Error: Could not open leaderboard.txt for reading.\n";
        return;
    }

    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);  // Create stringstream from line
        std::string username;
        int badgeCount;

        // Read username and badge count
        if (getline(iss, username, ',') && (iss >> badgeCount)) {
            std::string badgePart;
            Player player(username, "");  // Create player with a placeholder password

            // Add badges based on badgeCount (temporary badges)
            for (int i = 0; i < badgeCount; ++i) {
                player.addBadge("Badge " + std::to_string(i + 1));  // Add placeholder badges
            }

            players.push_back(player);  // Add player to the list
        }
        else {
            std::cerr << "Error parsing player data: " << line << std::endl;
        }
    }

    file.close();
}
