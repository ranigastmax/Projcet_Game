#pragma once

#include<SFML/Window.hpp>
#include<iostream>
#include<vector>
#include<SFML/Graphics.hpp>
#include"Player.h"
#include"Button.h"
#include"Characters.h"
#include"Background.h"
#include"Skeleton.h"
class Game
{
	//class that act as game engine


	//objects
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
	Player* player;
	Button* p1;
	Background* background;
	Background* menuBack1;
	Background* menuBack2;
	std::vector<Skeleton*> enemies;
	Skeleton* skeleton1;
	Skeleton* skeleton2;
	sf::Mouse mouse;
	sf::Clock enemyAttacksSeed;
	int x_player, y_player;

	int level = 0;
	int i = 0;
	bool spawning = false;

	void initializeViriables();
	void initializeWindow();
	void initializeEnemies(int);



public:

	Game();
	virtual ~Game();

	const bool running() const;

	void updateEvents();
	void render();
	void update();


};

