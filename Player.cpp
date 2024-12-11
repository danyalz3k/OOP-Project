#include "Player.h"
#include <fstream>
#include <sstream>
#include <iostream>

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

std::string Player::getPassword() const {
    return password;
}

std::vector<std::string> Player::getBadges() const {
    return badges;
}

int Player::getBadgeCount() const {
    return badges.size();
}

int Player::getPlayerCount() {
    return playerCount;
}

// File handling methods
void savePlayerData(const std::vector<Player>& players) {
    std::ofstream file("userdata.txt", std::ios::out);  // Open file in overwrite mode
    if (!file.is_open()) {
        std::cerr << "Error: Could not open userdata.txt for writing.\n";
        return;
    }

    for (const auto& player : players) {
        file << player.getUsername() << "," << player.getPassword();  // Save username and password
        for (const auto& badge : player.getBadges()) {
            file << "|" << badge;  // Save badges separated by '|'
        }
        file << "\n";
    }

    file.close();
}


void loadPlayers(std::vector<Player>& players) {
    std::ifstream file("userdata.txt");
    if (!file.is_open()) {
        std::cerr << "Error: Could not open userdata.txt for reading.\n";
        return;
    }

    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string username, password, badgesPart;
        int badgeCount;

        getline(iss, username, ',');       // Read username
        getline(iss, password, ',');       // Read password
        Player player(username, password); // Create a player with the password

        while (getline(iss, badgesPart, '|')) {
            if (!badgesPart.empty()) {
                player.addBadge(badgesPart);  // Add badges
            }
        }

        players.push_back(player);  // Add player to the list
    }

    file.close();
}
