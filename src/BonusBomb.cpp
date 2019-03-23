#include "../include/BonusBomb.h"

BonusBomb::BonusBomb(sf::Vector2f pos, float s) : Bonus(pos, s)
{
    texture.loadFromFile("res/bomb.png");
    scale();
}

void BonusBomb::use(std::vector<std::vector<bool>> &statemap)
{
    for (int i = -2; i <= 2; i++)
    {
        for (int j = -2; j <= 2; j++)
        {
            int x = static_cast<int>(location.x + i);
            int y = static_cast<int>(location.y + j);
            if (x > 0 && x < statemap.size()-1 && y > 0 && y < statemap.size()-1)
                statemap[y][x] = false;
        }
    }
}
