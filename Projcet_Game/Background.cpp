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


