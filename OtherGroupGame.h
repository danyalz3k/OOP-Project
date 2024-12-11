#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include <vector>
#include <iostream>

const int WIDTH = 30;
const int HEIGHT = 20;

class Point {
public:
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

class Snake {
private:
    std::vector<Point> body;
    char direction; // Current direction: 'W', 'A', 'S', 'D'
    bool alive;

public:
    Snake(int startX, int startY);

    bool isAlive();
    void setDirection(char newDirection);
    void move(Point& food, bool& foodEaten);
    void draw();
    std::vector<Point> getBody();
};

class Game {
private:
    Snake snake;
    Point food;
    bool foodEaten;
    int score;

public:
    Game();

    void generateFood();
    void draw();
    void handleInput();
    void update();
    bool isGameOver();
};

#endif // SNAKEGAME_H
