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

	this->initializeViriables();
	this->initializeWindow();
	this->x_player = 0;
	this->y_player = 0;
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
		for (auto skeleton : enemies)
		{
			skeleton->boundsSkeleton(this->player->herobounds());
			skeleton->enemymove(this->player->getSprite());
			skeleton->attackMele(this->player);
			//this->skeleton1->animateAttackMele();
		}
		for (auto i : enemies) { i->enemymove(this->player->getSprite()); }
		this->player->update();

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
		this->player->render(*this->window);
		if (this->level == 0)
		{
			this->initializeEnemies(1);
			
		}
	
	}
	else
	{
	this->menuBack1->backgroundMove(*this->window);
	this->menuBack2->backgroundMove(*this->window);
	this->p1->render(*this->window);
	}
	for (auto i : enemies) { i->render(*this->window); }
	this->window->display();
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
		this->player->getBounds(enemiesBounds, background->wallbounds);
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
	
}
