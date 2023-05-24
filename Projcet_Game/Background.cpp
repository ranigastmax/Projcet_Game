#include "Background.h"


void Background::loadTexture(std::string path, sf::Texture& textureName)
{
    if (!textureName.loadFromFile(path)) {
        std::cerr << "Could not load texture" << std::endl;
    }
    this->map.setTexture(map_texture);
}

Background::Background()
{
    this->loadTexture("textures/map.png", this->map_texture);
    this->map.setPosition(0, 0);
    
    left.setSize(sf::Vector2f(1, 625));
    left.setFillColor(sf::Color::Red);
    left.setPosition(30, 0);

    right.setSize(sf::Vector2f(1, 625));
    right.setFillColor(sf::Color::Red);
    right.setPosition(602, 0);

    down.setSize(sf::Vector2f(620, 1));
    down.setFillColor(sf::Color::Red);
    down.setPosition(0, 128);

    up.setSize(sf::Vector2f(620, 1));
    up.setFillColor(sf::Color::Red);
    up.setPosition(0, 597);

    this->backogroundbounds();
}

Background::~Background()
{

}

void Background::render(sf::RenderTarget& target)
{
    target.draw(this->map);
    target.draw(this->left);
    target.draw(this->right);
    target.draw(this->up);
    target.draw(this->down);
}

void Background::backgroundMove(sf::RenderTarget& target)
{
    sf::Vector2f mapPos = map.getPosition();
    int mapWidth = map.getTexture()->getSize().x;
    this->map_texture.setRepeated(true);
    this->map.move(backgroundAnimationSpeed * 0.25, 0);
    if (mapPos.x >= 0) map.setPosition(-mapWidth, mapPos.y);
    target.draw(this->map);
}

void Background::backogroundbounds()
{
    this->wallbounds.emplace_back(left.getGlobalBounds().left, left.getGlobalBounds().top, left.getGlobalBounds().width, left.getGlobalBounds().height);
    this->wallbounds.emplace_back(right.getGlobalBounds().left, right.getGlobalBounds().top, right.getGlobalBounds().width, right.getGlobalBounds().height);
    this->wallbounds.emplace_back(up.getGlobalBounds().left, up.getGlobalBounds().top, up.getGlobalBounds().width, up.getGlobalBounds().height);
    this->wallbounds.emplace_back(down.getGlobalBounds().left, down.getGlobalBounds().top, down.getGlobalBounds().width, down.getGlobalBounds().height);
}


