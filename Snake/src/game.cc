#include "game.h"
int const _width{ 600 }, _height{ 600 }, _max_FPS{ 10 };
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
        this->snake.handle_events(_input_event);
                                                                                                       }

}


Game::Game()
    :_window_height{ _height }, _window_width{ _width },
    _game_window(std::make_unique<sf::RenderWindow>(sf::VideoMode(_window_width, _window_height), _game_name)),
    _game_running{ true }, _input_event{}
{
    _game_window->setFramerateLimit(_max_FPS);
    _game_window->setVerticalSyncEnabled(_Vsync);
}

void Game::Run()
{
    while (_game_running)
    {
        Handle_events();
        _game_window->clear();
        snake.draw((_game_window));

        Handle_events();
            


        _game_window->display();
    }

}
