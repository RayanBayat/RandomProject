#ifndef MENU_H
#define MENU_H
#include "state.h"

class Menu : public State
{
private:


public:
	Menu();
	~Menu();
	void draw(std::unique_ptr<sf::RenderWindow>&);
	void handle_events(sf::Event);
};


#endif // MENU_H



