#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<iostream>
class Button
{
public:
	Button(int, int, std::string, std::string, std::string, int, int);
	void isMouseOver(sf::RenderWindow& window);
	sf::Sprite& getSprite();
	void render(sf::RenderTarget& target);
	bool isClicked();

	

private:
	sf::Sprite buttonSprite;
	sf::Vector2i topLeft;
	sf::Vector2f mousePos;
	sf::Texture buttonTextureNotClicked;
	sf::Texture buttonTextureClicked;
	sf::Texture buttonTextureMouseIsOver;
	sf::Event ev;
	bool clicked = false;


};

