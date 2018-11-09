#include "../include/Tile.h"

Tile::Tile(float d)
        : RectangleShape(sf::Vector2f(d, d))
{
    setState(1);
}

void Tile::setState(int arg)
{
    switch (arg)
    {
        case 0:
            setFillColor(sf::Color(155, 89, 182));
            break;

        case 1:
            setFillColor(sf::Color(25, 42, 86));
            break;

        case 2:
            setFillColor(sf::Color(231, 76, 60));
            break;
    }
}
