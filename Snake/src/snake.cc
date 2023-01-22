#include "snake.h"
int grid_height{ 20 }, grid_width{ 20 }, speed{ 1 };

void Snake::init()
{
	sf::RectangleShape rectangle(sf::Vector2f(10, 10));
	rectangle.setSize(sf::Vector2f(10.f, 10.f));

	sf::RectangleShape rectangle_odd(sf::Vector2f(10, 10));
	rectangle_odd.setSize(sf::Vector2f(10.f, 10.f));
	rectangle_odd.setFillColor(sf::Color::Magenta);

	sf::RectangleShape rectangle_even(sf::Vector2f(10, 10));
	rectangle_even.setSize(sf::Vector2f(10.f, 10.f));
	rectangle_even.setFillColor(sf::Color::Green);


	for (int i = 0; i < grid_height; i++)
	{
		for (int j = 0; j < grid_width; j++)
		{
			if (i + j & 1)
			{
				_grid[i][j] = rectangle_odd;

			}
			else
			{
				_grid[i][j] = rectangle_even;
			}

		}
	}
	
	snake_tail[0].first = snakeheadposX; snake_tail[0].second = snakeheadposY;
	snake_tail[1].first = snakeheadposX; snake_tail[1].second = snakeheadposY-1;
	snake_tail[2].first = snakeheadposX; snake_tail[2].second = snakeheadposY-2;

}

void Snake::draw_background(std::unique_ptr<sf::RenderWindow>& window)
{

	float window_width = { static_cast<float>(window->getSize().x) };
	float window_height = { static_cast<float>(window->getSize().y) };


	for (int i = 0; i < grid_height; i++)
	{
		for (int j = 0; j < grid_width; j++)
		{
			_grid[i][j].setFillColor(sf::Color::Black);
			_grid[i][j].setOutlineThickness(5.f);
			_grid[i][j].setOutlineColor(sf::Color::Black);
			_grid[i][j].setSize(sf::Vector2f((window_width / grid_width), (window_height / grid_height)));
			_grid[i][j].setPosition(static_cast<float>((j) * (window_width / grid_width)), static_cast<float>((i)) * (window_height / grid_height));


			for (int f = 0; f < snake_tail.size(); f++)
			{
				if (j == snake_tail[f].first && i == snake_tail[f].second)
				{

					_grid[i][j].setFillColor(sf::Color::Green);

					
				}
			}
			if (j == foodpos.first && i == foodpos.second)
			{
				_grid[i][j].setFillColor(sf::Color::Red);
			}
			window->draw(_grid[i][j]);
		}
	}
}

void Snake::random_food()
{
	std::vector<std::pair<int, int>>::iterator it;
	do
	{
		foodpos.first = rand() % grid_width; foodpos.second = rand() % grid_height;
		it = std::find(snake_tail.begin(), snake_tail.end(), foodpos);

	} while (it != snake_tail.end());
	isfoodonscreen = true;
}


void Snake::move_snake()
{
	std::pair<int, int> oldpos = snake_tail[0];
	if (oldpos == foodpos)
	{
		increment();
		isfoodonscreen = false;
		foodpos.first = -1; foodpos.second = -1;

	}
	switch (dir)
	{
	case up:
		snakeheadposY--;
		if (snakeheadposY < 0)
		{
			snakeheadposY = grid_height;
		}
		break;
	case down:
		snakeheadposY++;
		if (snakeheadposY >= grid_height)
		{
			snakeheadposY = 0;
		}
		break;
	case left:
		snakeheadposX--;
		if (snakeheadposX < 0)
		{
			snakeheadposX = grid_width;
		}
		break;
	case right:
		snakeheadposX++;
		if (snakeheadposX>= grid_width)
		{
			snakeheadposX = 0;
		}
		break;
	default:
		break;
	}
	
	for (int i = 0; i < snake_tail.size(); i++)
	{
		
		if (i==0)
		{
			snake_tail[i].first = snakeheadposX; snake_tail[i].second = snakeheadposY;
		}
		else
		{
			std::pair<int, int> localoldpos = snake_tail[i];
			snake_tail[i] = oldpos;
			oldpos = localoldpos;
		}
		
	}
	

	
}

void Snake::increment()
{
	std::pair<int, int> oldpos(0, 0);
	snake_tail.push_back(oldpos);
}

Snake::Snake()
	:_grid(grid_width, std::vector<sf::RectangleShape>(grid_height)),
	dir{ down }, snake_tail(3), isfoodonscreen{ false }
{
	srand(time(0));
	init();


}

Snake::~Snake()
{}
void Snake::draw(std::unique_ptr<sf::RenderWindow>& window)
{
	if (!isfoodonscreen)
	{
		random_food();
	}
	move_snake();
	draw_background(window);





	//std::cout << "x  " << _grid[0][1].getPosition().x << std::endl;
	//std::cout << "y  " << _grid[0][1].getPosition().y + _grid[0][1].getSize().y << std::endl;

}

void Snake::handle_events(sf::Event event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		dir = down;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		dir = right;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		dir = left;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		dir = up;
	}
}
