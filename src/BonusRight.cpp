#include "../include/BonusRight.h"

BonusRight::BonusRight(sf::Vector2f pos, float s) : Bonus(pos, s)
{
    texture.loadFromFile("res/right.png");
    scale();
}

void BonusRight::use(std::vector<std::vector<bool>> &statemap)
{
    int x = static_cast<int>(location.x);
    int y = static_cast<int>(location.y);
    while (statemap[y][x+1] == false)
        x++;
    for (int i = 1; i <= 5; i++)
    {
        if (x+i < statemap.size()-1)
            statemap[y][x+i] = false;
    }
}