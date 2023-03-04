#ifndef GAME_H
#define GAME_H
#include "snake.h"





class Game
{
private:
    int _window_height, _window_width, current_state;
    std::unique_ptr<sf::RenderWindow> _game_window;

    std::map<int, std::unique_ptr<State>> states;
    bool _game_running;
    sf::Event _input_event;

    void Handle_events();
    
public:
    Game(/* args */);
    ~Game() = default;

    void Run();

};


#endif