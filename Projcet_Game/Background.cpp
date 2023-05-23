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
   
}

Background::~Background()
{

}

void Background::render(sf::RenderTarget& target)
{
    target.draw(this->map);
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


