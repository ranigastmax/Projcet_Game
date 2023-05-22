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

	int x, y;

public:

	//constructors-------------------------------------
	Player();
	~Player();
	//end-constructors---------------------------------


	//public functions----------------------------------
	void move();
	void animateWalk();
	void animateAttackMele();
	void animateAttackDistance();
	void animateDeath();
	
	void releasedAD();
	void releasedWS();
};

