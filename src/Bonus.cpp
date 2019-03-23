#include "../include/Bonus.h"

Bonus::Bonus(sf::Vector2f pos, float s)
{
    location = pos;
    size = s;
    setPosition(location.x*size, location.y*size);
}

sf::Vector2f Bonus::getLocation()
{
    return location;
}

void Bonus::scale()
{
    setTexture(texture);
    float currsize = getLocalBounds().height;
    setScale(size/currsize, size/currsize);
}
