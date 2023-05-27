#pragma once
#include<SFML/Window.hpp>
#include<iostream>
#include<vector>
#include<SFML/Graphics.hpp>
#include"Characters.h"

class Player : public Characters
{

	void initcharacters();
	void initIntRect();
	float targetY, targetX;
	float x, y;
	bool movingLeft;
	bool movingRight;
	bool movingUp;
	bool movingDown;
	bool attack;
	bool  blockLeft;
	bool  blockRight;
	bool  blockUp;
	bool  blockDown;
	int j = 0;
	int heroDown;
	int	heroTop;
	int	heroLeft;
	int	heroRight;
	bool scroll;
	sf::Font font;
	sf::Text text;
	sf::Texture sword_texture;
	sf::Texture fire_sword_texture;
	sf::Sprite sword;
	sf::ConvexShape swordHitBox;
public:

	//constructors-------------------------------------
	Player();
	~Player();
	//end-constructors---------------------------------

	bool walking;

	//public functions----------------------------------
	void move();
	void animateWalk();
	void animateAttackMele();
	void animateAttackDistance();
	void animateDeath();
	void update();
	void releasedAD();
	void releasedWS();
	sf::FloatRect herobounds();
	sf::Sprite getSprite();

	void rendertext(sf::RenderTarget& target);
	void scrollChange();
	void bounds(std::vector<sf::FloatRect>);
	void animationattack();
};

