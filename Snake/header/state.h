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

#include"SFML/System.hpp"
#include"SFML/Window.hpp"
#include"SFML/Audio.hpp"
#include"SFML/Network.hpp"
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics.hpp>
int const _width{ 600 }, _height{ 600 }, _max_FPS{ 10 };

//int grid_height{ 20 }, grid_width{ 20 }, speed{ 1 };

class state
{

private:

public:
	virtual ~state() = default;
	virtual void handle_events() = 0;
	virtual void draw() = 0;
};

#endif