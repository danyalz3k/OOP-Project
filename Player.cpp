#include "Player.h"
#include <fstream>

// Initialize static member
int Player::playerCount = 0;

Player::Player(const std::string& uname, const std::string& pwd)
    : username(uname), password(pwd) {
    playerCount++;  // Increment player count
}

Player::Player(const Player& other)
    : username(other.username), password(other.password), badges(other.badges) {
    playerCount++;  // Increment player count for the copied player
}

Player::~Player() {
    playerCount--;  // Decrement player count on destruction
}

bool Player::authenticate(const std::string& uname, const std::string& pwd) {
    return (username == uname && password == pwd);
}

void Player::addBadge(const std::string& badge) {
    badges.push_back(badge);
}

void Player::displayBadges() const {
    std::cout << "Badges earned by " << username << ": ";
    for (const auto& badge : badges) {
        std::cout << badge << " ";
    }
    std::cout << std::endl;
}

std::string Player::getUsername() const {
    return username;
}

int Player::getBadgeCount() const {
    return badges.size();
}

int Player::getPlayerCount() {
    return playerCount;
}

// File handling methods
void savePlayerData(const Player& player) {
    std::ofstream file("players.txt", std::ios::app);
    if (file.is_open()) {
        file << player.getUsername() << "," << player.getBadgeCount() << "\n";
        file.close();
    }
}

void loadPlayers(std::vector<Player>& players) {
    std::ifstream file("players.txt");
    if (file.is_open()) {
        std::string uname, pwd;
        int badgeCount;
        while (file >> uname >> badgeCount) {
            Player player(uname, "password");  // Use a placeholder password
            for (int i = 0; i < badgeCount; ++i) {
                player.addBadge("Badge " + std::to_string(i + 1));  // Placeholder badges
            }
            players.push_back(player);
        }
        file.close();
    }
}
