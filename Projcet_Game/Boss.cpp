#include "Boss.h"

Boss::Boss()
{
	this->loadTexture("textures/Boss.png", walk_right_texture);
	hero.setPosition(150, 150);
	hero.setTexture(walk_right_texture);
	hero.setTextureRect(sf::IntRect(25, 624, 48, 46));
	maxHP = 200;
	hero.scale(2.5, 2.5);
	initIntRect();

	
}

void Boss::laserAttack( sf::Vector2f target)
{
	if (!isShootingOne)
	{
		if (i == 6)
		{
			laser1 = new Laser(hero.getGlobalBounds(), target);

		}
		isShootingOne = true;
	}
	if (!isShootingTwo)
	{
		if (i == 6)
		{
			laser2 = new Laser(hero.getGlobalBounds(), target);

		}
		isShootingTwo = true;
	}

	laser1->movef();
	laser2->movef();
	laser1->collision(target,);


}
void Boss::getBounds(sf::FloatRect& target, std::vector<sf::FloatRect>& wall_bounds)
{
	if (fireball_fly)
	{
		fireball->movef();
		fireball->animate();
		if (fireball->collision(target, wall_bounds) && fireballHit)
		{

			delete this->fireball;
			std::cout << "usuwam" << std::endl;
			fireball_fly = false;
			fireballHit = false;

		}
	}
}
void Boss::position(sf::FloatRect player)
{
	if (i==11&& clock2.getElapsedTime().asSeconds()>2.6)
	{
		clock2.restart();
		int minX = 25;
		int minY = 200;
		int maxX = 450;
		int maxY = 500;
		int NewX = std::rand() % ((maxX - minX + 1) + minX);
		int NewY = std::rand() % ((maxY - minY + 1) + minY);
		hero.setPosition(NewX, NewY);
		if (NewX > player.left)
		{
			hero.setScale(-2.5, 2.5);
		}
		else
		{
			hero.setScale(2.5, 2.5);
		}
		animationUp = false;
	}
}



void Boss::rangeattack()
{
	if (!animationUp)
	{
		if (clock.getElapsedTime().asSeconds() > 0.2)
		{
			this->hero.setTextureRect(distanceAttackRIGHT[i]);
			i--;
			if (i == 0) { animationUp = true; }
			clock.restart();
		}
	}
	else
	{

		if (clock.getElapsedTime().asSeconds() > 0.2)
		{
			this->hero.setTextureRect(distanceAttackRIGHT[i]);
			i++;
			if (i == 11) { animationUp = false; }
			clock.restart();
		}
	}
}

void Boss::initIntRect()
{
	distanceAttackRIGHT.emplace_back(25,224,48,46);
	distanceAttackRIGHT.emplace_back(125,224,51,46);
	distanceAttackRIGHT.emplace_back(225,224,57,46);
	distanceAttackRIGHT.emplace_back(325,224,66,46);
	distanceAttackRIGHT.emplace_back(425,224,66,46);
	distanceAttackRIGHT.emplace_back(525,224,68,46);
	distanceAttackRIGHT.emplace_back(625,224,68,46); //tu atakuj
	distanceAttackRIGHT.emplace_back(824,224,49,46);
	distanceAttackRIGHT.emplace_back(25,324,48,46);
	distanceAttackRIGHT.emplace_back(229,326,40,44);
	distanceAttackRIGHT.emplace_back(432,327,34,43);
	distanceAttackRIGHT.emplace_back(632,327,34,43); // tu si� teleportuj

	death_down.emplace_back(627,730,44,50);
	death_down.emplace_back(25,834,47,59);
	death_down.emplace_back(126, 834,46, 59);
	death_down.emplace_back(227, 834,45, 59);
	death_down.emplace_back(327, 834,45, 59);
	
}

void Boss::initcharacters()
{

}



