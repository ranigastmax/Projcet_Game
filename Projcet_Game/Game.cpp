#include "Game.h"

//private



void Game::initializeViriables()
{
	this->window = nullptr;
	this->player = new Player;
	this->background = new Background;
	this->menuBack1 = new Background;
	this->menuBack2 = new Background;
	this->p1 = new Button(150, 150, "textures/button.png", "textures/button2.png", "textures/button1.png", 5, 5);
	this->x_player = 0;
	this->y_player = 0;
	if (!door_teture.loadFromFile("textures/OpenDoor.png"))
	{
		std::cout << "nie udalo sie zaladowac drzwi" << std::endl;
	}
	if (!gameOverFONT.loadFromFile("textures/Exquisite Corpse.ttf"))
	{
		std::cout << "nie udalo sie zaladowac font a" << std::endl;
	}
	door->setTexture(door_teture);
	door->setPosition(267, 33);
	door->setColor(sf::Color(255, 255, 255, 0));
	gameOverText.setFont(gameOverFONT);
	gameOverText.setString("GAME OVER");
	gameOverText.setCharacterSize(100);
	gameOverText.setFillColor(sf::Color(125, 7, 7, 0)); 
	gameOverText.setPosition(85,250);

}


void Game::initializeWindow()
{
	this->videoMode.height = 633;
	this->videoMode.width = 632;

	this->window = new sf::RenderWindow(this->videoMode, "projekt");
	this->window->setFramerateLimit(90);

}


void Game::initializeEnemies(int amount)
{

	if (spawning)
	{		
		Skeleton* enemy = new Skeleton();
		enemies.push_back(enemy);		
	}
	if (i < amount) { spawning = true; }
	else { spawning = false; }
	i++;

}


Game::Game()
{
	this->door = new sf::Sprite;
	this->initializeViriables();
	this->initializeWindow();
	srand(time(NULL));
	
}


Game::~Game()
{
	delete this->window;
	delete this->player;
	delete this->p1;
	delete this->background;
}


const bool Game::running() const
{

	return this->window->isOpen();
}
//public 


void Game::updateEvents()
{
	this->player->rect_collision.clear();

	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::W || ev.key.code == sf::Keyboard::S || ev.key.code == sf::Keyboard::A || ev.key.code == sf::Keyboard::D)
			{

				if (!player->herodeath())
				{
					this->player->move();
					this->player->walking = true;
				}
			}
			this->player->weponChange();

			break;
		case sf::Event::KeyReleased:
			if ((ev.key.code == sf::Keyboard::W) || (ev.key.code == sf::Keyboard::S))
			{
				this->player->releasedWS();
			}
			if ((ev.key.code == sf::Keyboard::A) || (ev.key.code == sf::Keyboard::D))
			{
				this->player->releasedAD();
			}
			break;
		case sf::Event::MouseButtonPressed:
			if (!player->herodeath())
			{
				this->player->animateAttackMele();
				this->player->animateAttackDistance();
			}
			break;
		case sf::Event::MouseButtonReleased:
			this->p1->click();
			break;
		case sf::Event::MouseWheelMoved:
			if (!player->herodeath())
			{
				this->player->scrollChange();
			}
			break;

		}
	}
	if (!player->herodeath())
	{

		this->player->animateWalk();
		this->player->animationattack(mouse_position);
		this->player->bounds(this->background->wallbounds);
	}

		
		
	for (auto it = enemies.begin(); it != enemies.end(); ++it)
	{
		auto skeleton = *it;
		if (!player->herodeath())
		{
			skeleton->boundsSkeleton(this->player->herobounds());
			
			skeleton->enemymove(this->player->getSprite());
			skeleton->attackMele(this->player);
			skeleton->update();
			skeleton->enemymove(this->player->getSprite());
			this->player->swordDamage(*skeleton);
			this->player->fireballDamage(*skeleton);
			if (skeleton->herodeath())
			{
				enemies.erase(it);
				break;
			}
		}
	}
	this->player->update();
	detectCollision(enemies);
}
void Game::render()
{
	//visualasions renders the game obj
	this->window->clear();
	//-----------------------------
	if (p1->isClicked())
	{
		this->background->render(*this->window);
		this->player->rendertext(*this->window);
		window->draw(*door);
		this->player->render(*this->window);
		if (this->level == 0)
		{
			this->initializeEnemies(0);	
			if (!isBossAlive)
			{
				this->boss = new Boss;
				isBossAlive = true;
				vectorBoss.emplace_back(boss);
			}
				this->boss->render(*window);
				this->boss->rangeattack();
				this->boss->position(player->herobounds());
		
		}
		if (this->level == 1)
		{
			this->initializeEnemies(4);
			
		}
		if (this->level == 2)
		{
			this->initializeEnemies(6);
		}
		if (this->level == 3)
		{


		}
	}
	else
	{
	this->menuBack1->backgroundMove(*this->window);
	this->menuBack2->backgroundMove(*this->window);
	this->p1->render(*this->window);
	}
	for (auto i : enemies) { i->render(*this->window); }
	if (player->herodeath())
	{
		this->window->draw(gameOverText);
		if (clock.getElapsedTime().asSeconds() < 3)
		{
			float color = clock.getElapsedTime().asSeconds() * 80;
			gameOverText.setFillColor(sf::Color(125, 7, 7, color));
		}
	}
	this->window->display();
}

void Game::doorAnimation()
{
	if (clock2.getElapsedTime().asSeconds() < 0.5&&vectorBoss.empty())
	{
		door->setColor(sf::Color(255, 255, 255, clock2.getElapsedTime().asSeconds() * 150));
		
		doorIsOpen = false;
	}
	if (clock2.getElapsedTime().asSeconds() >= 0.5)
	{
		if(vectorBoss.empty())
		{
			doorIsOpen = true;
		}
		clock2.restart();
	}
}
void Game::update()
{
	if (player->herodeath())
	{
		player->animateDeath();

	}
	//there is game
	if (!player->herodeath())
	{
		clock.restart();
		this->player->getBounds(enemiesBounds, background->wallbounds);
		if (isBossAlive) 
		{
			this->boss->laserAttack(this->player->getSprite().getGlobalBounds(), background->wallbounds, *this->window);
			if (boss->laserAttack(this->player->getSprite().getGlobalBounds(), background->wallbounds, *this->window))
			{
				player->adjustHp(-5);
			}
		}

	}
	this->player->update();
	this->p1->isMouseOver(*this->window);
	this->updateEvents();
	mouse_position = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
	enemiesBounds.clear();
	for (auto skeleton : enemies)
	{
		
		enemiesBounds.push_back(skeleton->enemyFloatRect());
	}

	if (enemies.empty()&& p1->isClicked())
	{
		doorAnimation();
		//std::cout << level << std::endl;
	}
	else
	{
		clock2.restart();
	}
	if (doorIsOpen&& door->getGlobalBounds().intersects(player->herobounds()))
	{
		this->player->newlevel();
		level++;
		door->setColor(sf::Color(255, 255, 255, 0));
		doorIsOpen = false;
		i = 0;
	}
}

void Game::detectCollision(std::vector<Skeleton*>& enemies) {
	for (int i = 0; i < enemies.size(); i++) {
		for (int j = i + 1; j < enemies.size(); j++) {
			sf::FloatRect enemyBoundsA = enemies[i]->enemyFloatRect();
			sf::FloatRect enemyBoundsB = enemies[j]->enemyFloatRect();

			if (enemyBoundsA.intersects(enemyBoundsB)) {
				float centerX_A = enemyBoundsA.left + enemyBoundsA.width / 2;
				float centerY_A = enemyBoundsA.top + enemyBoundsA.height / 2;
				float centerX_B = enemyBoundsB.left + enemyBoundsB.width / 2;
				float centerY_B = enemyBoundsB.top + enemyBoundsB.height / 2;

				float distanceX = centerX_A - centerX_B;
				float distanceY = centerY_A - centerY_B;
				float distance = std::sqrt(distanceX * distanceX + distanceY * distanceY);

				float l = (enemyBoundsA.width + enemyBoundsB.width) / 2 - distance;
				float pushX = l * distanceX / distance;
				float pushY = l * distanceY / distance;

				enemies[i]->smove(sf::Vector2f(pushX / 2, pushY / 2));
				enemies[j]->smove(sf::Vector2f(-pushX / 2, -pushY / 2));
				
			}
		}
	}
}