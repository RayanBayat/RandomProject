#include "game.h"
#include <utility> 


std::string _game_name{ "Snake" };
bool _Vsync{ true };

void Game::Handle_events()
{
    while (_game_window->pollEvent(_input_event))
    {
        if (_input_event.type == sf::Event::Closed)
        {
            _game_window->close();
            _game_running = false;
        }
        this->states.at(current_state)->handle_events(_input_event);
                                                                                                       }

}


Game::Game()
    :_window_height{ _height }, _window_width{ _width },
    _game_window(std::make_unique<sf::RenderWindow>(sf::VideoMode(_window_width, _window_height), _game_name, sf::Style::Close)),
    _game_running{ true }, _input_event{}, states{}, current_state{ Snake_State }
{
    _game_window->setFramerateLimit(_max_FPS);
    _game_window->setVerticalSyncEnabled(_Vsync);


    states.insert(std::pair<int, std::unique_ptr<State>>({ Snake_State,std::make_unique<Snake>() }));
    //insert states in the map
    
}

void Game::Run()
{
    while (_game_running)
    {
        Handle_events();
        _game_window->clear();

        states.at(current_state)->draw(_game_window);


        Handle_events();
            


        _game_window->display();
    }

}
