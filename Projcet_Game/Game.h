#pragma once

#include<SFML/Window.hpp>
#include<iostream>
#include<vector>
#include<SFML/Graphics.hpp>
#include"Player.h"
class Game
{
	//class that act as game engine


	//objects
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
	Player* player;








	void initializeViriables();
	void initializeWindow();



public:

	Game();
	virtual ~Game();

	const bool running() const;

	void updateEvents();
	void render();
	void update();

};

