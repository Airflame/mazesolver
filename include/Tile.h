#ifndef TILE_H
#define TILE_H
#include <SFML/Graphics.hpp>


class Tile : public sf::RectangleShape
{
    public:
        Tile() = default;
        Tile(float);
        void setState(int);
};

#endif
