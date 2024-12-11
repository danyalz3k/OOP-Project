#include "Hangman.h"

Hangman::Hangman(string name) : Game(name), gameWon(false) {}

void Hangman::play() {
    gameWon = false;

    // Gameplay Rules
    cout << "Welcome to Hangman!" << endl;
    cout << "Guess the word letter by letter. You have 6 incorrect guesses.\n\n";

    // Available word list
    string words[] = {
        "elephant", "giraffe", "kangaroo", "dolphin", "flamingo",
        "pineapple", "avocado", "blueberry", "cinnamon", "croissant"
    };

    int size = sizeof(words) / sizeof(words[0]);

    srand(time(0));
    string randomWord = words[rand() % size];

    // Ensure lowercase for consistency
    std::transform(randomWord.begin(), randomWord.end(), randomWord.begin(), ::tolower);

    int IncorrectGuesses = 0;
    string guessedRN(randomWord.length(), '_');
    string guessedLetters;

    do {
        cout << hangman_state[IncorrectGuesses] << endl;
        cout << "Word: ";
        for (char c : guessedRN) {
            cout << c << " ";
        }
        cout << "\n\n";

        char guess;
        cout << "Enter your guess: ";
        cin >> guess;

        // Validate input
        if (!isalpha(guess)) {
            cout << "Invalid input! Please enter a single letter.\n";
            continue;
        }

        guess = tolower(guess);  // Normalize input to lowercase

        if (guessedLetters.find(guess) != string::npos) {
            cout << "You've already guessed that letter.\n";
            continue;
        }

        guessedLetters += guess;
        bool isWrong = true;

        for (size_t i = 0; i < randomWord.length(); ++i) {
            if (guess == randomWord[i]) {
                guessedRN[i] = guess;
                isWrong = false;
            }
        }

        if (isWrong) {
            IncorrectGuesses++;
        }

        if (IncorrectGuesses == 6) {
            cout << hangman_state[IncorrectGuesses] << endl;
            cout << "You lost! The word was: " << randomWord << "\n";
            return;
        }
    } while (guessedRN != randomWord);

    cout << "Congratulations! You guessed the word: " << randomWord << "\n";
    gameWon = true;
}
