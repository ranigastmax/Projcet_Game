#include "Game.h"

//private



void Game::initializeViriables()
{
	this->window = nullptr;
	this->player = new Player;
	this->background = new Background;
	this->menuBack1 = new Background;
	this->menuBack2 = new Background;
	this->p1 = new Button(150,150,"textures/button.png", "textures/button2.png", "textures/button1.png",5,5);
	this->skeleton1 = new Skeleton;
	//this->skeleton2 = new Skeleton;
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

	/*if (spawning)
	{
		Skeleton* enemy = new Skeleton();
		enemies.push_back(enemy);
	}
	if (i < amount) { spawning = true; }
	else { spawning = false; }
	i++;
	*/
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
				this->player->move();
				this->player->walking = true;
			}
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
			this->player->animateAttackMele();
			break;
		case sf::Event::MouseButtonReleased:
			this->p1->click();
			break;
		}
	}
		this->player->animateWalk();
		this->player->animationattack();
		this->player->bounds(this->background->wallbounds);
		this->skeleton1->boundsSkeleton(this->player->herobounds());
		this->skeleton1->enemymove(this->player->getSprite());
		this->skeleton1->animateAttackMele();
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
		this->player->render(*this->window);
		if (this->level == 0)
		{
			this->initializeEnemies(5);
	this->skeleton1->render(*this->window);
		}
	
	}
	else
	{
	this->menuBack1->backgroundMove(*this->window);
	this->menuBack2->backgroundMove(*this->window);
	this->p1->render(*this->window);
	}
	//this->player->render(*this->window);
	//this->p1->render(*this->window);
	for (auto i : enemies) { i->render(*this->window); }
	this->window->display();
}

void Game::update()
{
	//there is game
	this->player->update();
	this->p1->isMouseOver(*this->window);
	this->updateEvents();


}
