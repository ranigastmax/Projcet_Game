#include "Game.h"

//private



void Game::initializeViriables()
{
	this->window = nullptr;
	this->player = new Player;
	this->p1 = new Button(200,200,"textures/button.png", "textures/button2.png", "textures/button1.png",5,5);
}
void Game::initializeWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;

	this->window = new sf::RenderWindow(this->videoMode, "projekt");
	this->window->setFramerateLimit(90);



}


Game::Game()
{

	this->initializeViriables();
	this->initializeWindow();


}


Game::~Game()
{
	delete this->window;
	delete this->player;
	delete this->p1;
}



const bool Game::running() const
{

	return this->window->isOpen();
}
//public



void Game::updateEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			this->player->animateWalk();
			break;
		case sf::Event::KeyReleased:
			this->player->animateBreath();
			break;
		case sf::Event::MouseButtonPressed:
			this->player->animateAttackMele();
			break;
		case sf::Event::MouseButtonReleased:
			this->p1->click();
			break;
		}
		
	}
}


void Game::render()
{
	//visualasions renders the game obj
	this->window->clear();
	//-----------------------------

	if (p1->isClicked())
	{
	this->player->render(*this->window);
	}
	else
	{
	this->p1->render(*this->window);
	}
	//this->player->render(*this->window);
	//this->p1->render(*this->window);

	this->window->display();
}

void Game::update()
{
	//there is game
	this->player->update();
	this->p1->isMouseOver(*this->window);
	this->updateEvents();


}
