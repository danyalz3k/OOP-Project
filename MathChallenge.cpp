
#include "MathChallenge.h"

void MathChallenge::play() {
    srand(time(0));
    int a = rand() % 10 + 1;
    int b = rand() % 10 + 1;
    int answer;
    std::cout << "Solve: " << a << " + " << b << " = ";
    std::cin >> answer;

    if (answer == a + b) {
        std::cout << "Correct!" << std::endl;
    } else {
        std::cout << "Wrong! The correct answer is " << a + b << std::endl;
    }
}
