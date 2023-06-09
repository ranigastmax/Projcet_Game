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
	laser1 = nullptr;
	laser2 = nullptr;
	this->loadTexture("textures/HpChange.png", hp_texture);
	HP.setTexture(hp_texture);
	HP.setPosition(130, 550);
	HP.setScale(4, 0.5);
	if (!font.loadFromFile("textures/Augusta.ttf"))
	{
		std::cout << "nie udalo sie zaladowac font a" << std::endl;
	}
	text.setFont(font);
	text.setString("STONE GOLEM");
	text.scale(0.8, 0.8);
	text.setPosition(230, 555);
	maxHP = 50;
	hp = 50;
}


bool Boss::laserAttack(sf::FloatRect target, std::vector<sf::FloatRect>& walls, sf::RenderWindow& window)
{
	if (!isBossDead)
	{
		if (!isShootingOne)
		{
			if (i == 6)
			{
				laser1 = new Laser(hero.getGlobalBounds(), sf::Vector2f(target.left, target.top));
			}
			isShootingOne = true;
			isShootingTwo = false;
		}
		if (!isShootingTwo)
		{
			if (i == 6)
			{
				laser2 = new Laser(hero.getGlobalBounds(), sf::Vector2f(target.left, target.top));
			}
			isShootingTwo = true;
			isShootingOne = false;
		}

		if (laser1 != nullptr)
		{
			laser1->movef();
			if (laser1->collisionPlayer(target))
			{
				std::cout << "strzelam" << std::endl;
				delete this->laser1;
				laser1 = nullptr;
				std::cout << "usuwam1" << std::endl;
				return true;
			}
			if (laser1->collisionWalls(walls))
			{
				delete this->laser1;
				laser1 = nullptr;
			}
		}
		if (laser2 != nullptr)
		{
			laser2->movef();
			if (laser2->collisionPlayer(target))
			{
				delete this->laser2;
				laser2 = nullptr;
				std::cout << "usuwam2" << std::endl;
				return true;

			}
			if (laser2->collisionWalls(walls))
			{
				delete this->laser2;
				laser2 = nullptr;
			}
		}
		bossHP();
		return false;
	}
}



void Boss::position(sf::FloatRect player)
{
	if (!isBossDead)
	{
		if (i == 11 && clock2.getElapsedTime().asSeconds() > 2.6)
		{
			clock2.restart();
			int minX = 25;
			int minY = 400;
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
}


void Boss::rangeattack()
{
	if (!isBossDead)
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
	distanceAttackRIGHT.emplace_back(632,327,34,43); // tu siê teleportuj

	death_down.emplace_back(627,730,44,50);
	death_down.emplace_back(25,834,47,59);
	death_down.emplace_back(126, 834,46, 59);
	death_down.emplace_back(227, 834,45, 59);
	death_down.emplace_back(327, 834,45, 59);
	
}

void Boss::initcharacters()
{

}

void Boss::render(sf::RenderWindow& window)
{
	if(this->laser1 != nullptr)
	{
		window.draw(laser1->getSprite());
	}
	if (this->laser2 != nullptr)
	{
		window.draw(laser2->getSprite());
	}
	window.draw(this->hero);
	window.draw(this->HP);
	window.draw(this->text);

}



void* Boss::getPointer1()
{
	return this->laser1;
}

void* Boss::getPointer2()
{
	return this->laser2;
}

void Boss::bossHP()
{
	if (clock.getElapsedTime().asSeconds() < 3&& isBossDead)
	{
		float color = clock.getElapsedTime().asSeconds() * 80;
		text.setFillColor(sf::Color(255, 255, 255, color));
	}
	if (!isBossDead)
	{
		float hpDisplay = (this->hp / this->maxHP) * 92;
		this->HP.setTextureRect(sf::IntRect(0, 0, hpDisplay, 18));
		if (this->hp <= 0)
		{
			this->HP.setTextureRect(sf::IntRect(0, 0, 0, 18));
			isBossDead = true;
			i = 0;
				text.setPosition(85, 250);
				text.setCharacterSize(65);
				text.setFillColor(sf::Color(255, 255, 255, 255));
				text.setPosition(85, 250);
				text.setString("CONGRATULATIONS!!");
		}
	}
}

void Boss::bossDeath()
{

	if (i != 5&& isBossDead)
	{
		if (clock.getElapsedTime().asSeconds() > 0.7)
		{
			this->hero.setTextureRect(death_down[i]);
			i++;
			delete laser1;
			delete laser2;
			laser1 = nullptr;
			laser2 = nullptr;
			clock.restart();
		}
	}

}

sf::FloatRect Boss::bossGetbounds()
{
	return sf::FloatRect(this->hero.getGlobalBounds().left,
		this->hero.getGlobalBounds().top,
		this->hero.getGlobalBounds().width,
		this->hero.getGlobalBounds().height);
}



