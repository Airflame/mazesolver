#ifndef GRID_H
#define GRID_H
#include "Tile.h"
#include <vector>
#include <iostream>


class Grid
{
    public:
        Grid();
        void setSize(int);
        void draw(sf::RenderWindow*);
        void setState(std::vector<std::vector<bool>>&,std::vector<std::vector<bool>>&);

    private:
        std::vector<std::vector<Tile>> tiles;
};

#endif
