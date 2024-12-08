#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <iostream>

class Player {
private:
    std::string username;
    std::string password;
    std::vector<std::string> badges;
    static int playerCount;  // Static member

public:
    Player(const std::string& uname, const std::string& pwd); // Constructor
    Player(const Player& other); // Copy constructor
    ~Player(); // Destructor

    bool authenticate(const std::string& uname, const std::string& pwd);
    void addBadge(const std::string& badge);
    void displayBadges() const;
    std::string getUsername() const;
    int getBadgeCount() const;

    static int getPlayerCount(); // Static method to access player count
};


void savePlayerData(const Player& player);  
void loadPlayers(std::vector<Player>& players);  

#endif