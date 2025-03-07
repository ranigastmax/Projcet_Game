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
#include"Boss.h"
#include"Upgrades.h"
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
	std::vector<sf::FloatRect> enemiesBounds;
	std::vector<sf::FloatRect> bossBounds;
	sf::Mouse mouse;
	sf::Clock enemyAttacksSeed;
	int x_player, y_player;
	sf::Vector2f mouse_position;
	sf::Font gameOverFONT;
	sf::Text gameOverText;
	sf::Clock clock;
	sf::Clock clock2;
	sf::Sprite blood;
	sf::Texture blood_teture;
	Boss* boss;
	std::vector<Boss*> vectorBoss;
	int level = 0;
	int i = 0;
	bool spawning = false;
	bool doorIsOpen;
	bool GameStart;
	sf::Texture door_teture;
	sf::Sprite *door;
	void doorAnimation();
	void initializeViriables();
	void initializeWindow();
	void initializeEnemies(int);
	void detectCollision(std::vector<Skeleton*>& enemies);

	bool isUpgradeson = false;
	std::vector<Upgrades*> UpgradesButtons;
	int temp=0;
	bool isBossAlive = false;

public:

	Game();
	virtual ~Game();

	const bool running() const;

	void updateEvents();
	void render();
	void update();




};

