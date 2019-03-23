#include "../include/BonusUp.h"

BonusUp::BonusUp(sf::Vector2f pos, float s) : Bonus(pos, s)
{
    texture.loadFromFile("res/up.png");
    scale();
}

void BonusUp::use(std::vector<std::vector<bool>> &statemap)
{
    int x = static_cast<int>(location.x);
    int y = static_cast<int>(location.y);
    while (statemap[y-1][x] == false)
    {
        y--;
        if (y <= 1)
            break;
    }
    for (int i = 1; i <= 5; i++)
    {
        if (y-i > 0)
            statemap[y-i][x] = false;
    }
}