#include "../include/BonusDown.h"

BonusDown::BonusDown(sf::Vector2f pos, float s) : Bonus(pos, s)
{
    texture.loadFromFile("res/down.png");
    scale();
}

void BonusDown::use(std::vector<std::vector<bool>> &statemap)
{
    int x = static_cast<int>(location.x);
    int y = static_cast<int>(location.y);
    while (statemap[y+1][x] == false)
    {
        y++;
        if (y >= statemap.size()-1)
            break;
    }
    for (int i = 1; i <= 5; i++)
    {
        if (y+i < statemap.size()-1)
            statemap[y+i][x] = false;
    }
}