#ifndef SNAKE_H
#define SNAKE_H
#include "state.h"


enum direction { up, down, left, right };
class Snake
{
private:
    
    int grid_height{ 20 }, grid_width{ 20 }, speed{ 1 };

    direction dir;
    std::vector<std::vector<sf::RectangleShape>> _grid;

    int snakeheadposX = 5,snakeheadposY = 5;

    std::vector<std::pair<int, int>> snake_tail;
    std::pair<int, int>foodpos;
    bool isfoodonscreen;

    void init();
    void draw_background(std::unique_ptr<sf::RenderWindow>&);

    void move_snake();
    void increment();
    void random_food();
public:
    Snake(/* args */);
    ~Snake();
    void draw(std::unique_ptr<sf::RenderWindow>&);
    void handle_events(sf::Event);
};



#endif
