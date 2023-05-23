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
	bool atack;
	int j = 0;
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


	void animationattack();
};

