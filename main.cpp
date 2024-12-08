#include <iostream>
#include <vector>
#include "Player.h"
#include "MathChallenge.h"
#include "Anagrams.h"
#include "MissingNumber.h"
#include "Leaderboard.h"

int main() {
    std::vector<Player> players;
    Player* currentPlayer = nullptr;

    // Load players from file
    loadPlayers(players);

    while (true) {
        std::cout << "1. Sign Up\n2. Sign In\n3. Play Game\n4. View Badges\n5. View Leaderboard\n6. View Total Players\n7. Exit\n";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::string uname, pwd;
            std::cout << "Enter username: ";
            std::cin >> uname;
            std::cout << "Enter password: ";
            std::cin >> pwd;
            players.emplace_back(uname, pwd);
            savePlayerData(players.back());  // Save new player to file
            std::cout << "Sign-up successful!\n";
        } else if (choice == 2) {
            std::string uname, pwd;
            std::cout << "Enter username: ";
            std::cin >> uname;
            std::cout << "Enter password: ";
            std::cin >> pwd;

            for (auto& player : players) {
                if (player.authenticate(uname, pwd)) {
                    currentPlayer = &player;
                    std::cout << "Sign-in successful!\n";
                    break;
                }
            }
            if (!currentPlayer) {
                std::cout << "Invalid credentials!\n";
            }
        } else if (choice == 3) {
            if (!currentPlayer) {
                std::cout << "Sign in first!\n";
                continue;
            }

            int gameChoice = rand() % 3;  // Randomly select a game
            if (gameChoice == 0) {
                MathChallenge mathGame;
                mathGame.play();
                currentPlayer->addBadge("Math Badge");
            } else if (gameChoice == 1) {
                Anagrams anagramGame;
                anagramGame.play();
                currentPlayer->addBadge("Anagrams Badge");
            } else if (gameChoice == 2) {
                MissingNumber missingGame;
                missingGame.play();
                currentPlayer->addBadge("Missing Number Badge");
            }
        } else if (choice == 4) {
            if (currentPlayer) {
                currentPlayer->displayBadges();
            } else {
                std::cout << "Sign in first!\n";
            }
        } else if (choice == 5) {
            displayLeaderboard(players);
        } else if (choice == 6) {
            std::cout << "Total Players: " << Player::getPlayerCount() << "\n";
        } else if (choice == 7) {
            break;
        } else {
            std::cout << "Invalid option. Try again.\n";
        }
    }
    return 0;
}
