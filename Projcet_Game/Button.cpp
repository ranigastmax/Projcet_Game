#include "Button.h"

Button::Button()
{
}

Button::Button(int top, int left, std::string pathNotClicked, std::string pathClicked, std::string pathMouseIsOver, int scalex, int scaley)
{	
	this->buttonTextureMouseIsOver.loadFromFile(pathMouseIsOver);
	this->buttonTextureNotClicked.loadFromFile(pathNotClicked);
	this->buttonTextureClicked.loadFromFile(pathClicked);
	this->buttonSprite.setTexture(buttonTextureNotClicked);
	this->buttonSprite.setPosition(top,left);
	this->buttonSprite.setScale(scalex,scaley);
}

void Button::isMouseOver(sf::RenderWindow& window)
{
	mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	if (this->buttonSprite.getGlobalBounds().contains(mousePos))
	{
		this->buttonSprite.setTexture(buttonTextureMouseIsOver);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttonSprite.setTexture(buttonTextureClicked);
			click();
		}
	}
	else { this->buttonSprite.setTexture(buttonTextureNotClicked); }
}

void Button::click()
{
		clicked = true;
}



sf::Sprite &Button::getSprite()
{
	return this->buttonSprite;
}

void Button::render(sf::RenderTarget& target)
{
	target.draw(this->buttonSprite);
}

bool Button::isClicked()
{
	return clicked;
}
