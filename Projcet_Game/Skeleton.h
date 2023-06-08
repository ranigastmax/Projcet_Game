#pragma once
#include"Characters.h"
#include <cstdlib>
#include <ctime>
class Skeleton : public Characters
{
public:
	Skeleton();
	void initIntRect();
	void initcharacters();
	bool herodeath();
	void enemymove(sf::Sprite target);
	void animateWalk();
	void animateAttackMele();
	void animateAttackDistance();
	void animateDeath();
	void render(sf::RenderTarget& target);
	void boundsSkeleton(sf::FloatRect);
	float attackspeed(float);
	void hitboxSet();
	void attackMele(Characters* object);
	void update();
	sf::FloatRect enemyFloatRect();
	bool attacked = false;
	
	void smove(sf::Vector2f mo);
private:
	int i = 0;
	int j = 0;
	sf::Vector2f direction;
	sf::RectangleShape hitBox;
	bool blockmove;

	float hpDisplay;

	bool moveRight;
	bool moveLeft;
	bool moveDown;
	bool moveUp;


	float maxHP = 20;	
};

