#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>
#include <vector>
#include<vector>
#include <cmath>
#include <iostream>
#include <utility> 

#include"SFML/System.hpp"
#include"SFML/Window.hpp"
#include"SFML/Audio.hpp"
#include"SFML/Network.hpp"
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics.hpp>

int const _width{ 600 }, _height{ 600 }, _max_FPS{ 10 };


enum States
{ 
	Menu_State,
	Snake_State,
	Mine_Sweeper
};

class State
{

private:

public:
	virtual ~State() = default;
	virtual void handle_events(sf::Event) = 0;
	virtual void draw(std::unique_ptr<sf::RenderWindow>&) = 0;
};

#endif