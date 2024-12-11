#include <iostream>
#include <vector>
#include "Player.h"
#include "MathChallenge.h"
#include "Anagrams.h"
#include "MissingNumber.h"
#include "Leaderboard.h"
#include "OddOneOut.h"
#include "Hangman.h"

int main() {
    std::vector<Player> players;
    Player* currentPlayer = nullptr;

    // Load players from file
    loadPlayers(players);
    loadLeaderboard(players);  // Load leaderboard

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
            savePlayerData(players);  // Save all players to file
            std::cout << "Sign-up successful!\n";
        }
        else if (choice == 2) {
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
        }
        else if (choice == 3) {
            if (!currentPlayer) {
                std::cout << "Sign in first!\n";
                continue;
            }

            int gameChoice = rand() % 5;  // Randomly select a game (adjusted to include Hangman)
            if (gameChoice == 0) {
                MathChallenge mathGame;
                mathGame.play();
                currentPlayer->addBadge("Math Badge");
            }
            else if (gameChoice == 1) {
                Anagrams anagramGame;
                anagramGame.play();
                currentPlayer->addBadge("Anagrams Badge");
            }
            else if (gameChoice == 2) {
                MissingNumber missingGame;
                missingGame.play();
                currentPlayer->addBadge("Missing Number Badge");
            }
            else if (gameChoice == 3) {
                OddOneOut oddGame;
                oddGame.play();
                currentPlayer->addBadge("Odd One Out Badge");
            }
            else if (gameChoice == 4) {
                Hangman hangmanGame;
                hangmanGame.play();
                currentPlayer->addBadge("Hangman Badge");
            }

            // Save leaderboard after badge update
            saveLeaderboard(players);
        }
        else if (choice == 4) {
            if (currentPlayer) {
                currentPlayer->displayBadges();
            }
            else {
                std::cout << "Sign in first!\n";
            }
        }
        else if (choice == 5) {
            displayLeaderboard(players);  // Display the leaderboard
        }
        else if (choice == 6) {
            std::cout << "Total Players: " << Player::getPlayerCount() << "\n";
        }
        else if (choice == 7) {
            break;
        }
        else {
            std::cout << "Invalid option. Try again.\n";
        }
    }

    // Save player data and leaderboard before exiting
    savePlayerData(players);  // Save all players' data, not just one player
    saveLeaderboard(players);

    return 0;
}
