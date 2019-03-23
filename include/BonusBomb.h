#ifndef BONUSBOMB_H
#define BONUSBOMB_H
#include "Bonus.h"


class BonusBomb : public Bonus
{
public:
    BonusBomb() = default;
    BonusBomb(sf::Vector2f, float);
    void use(std::vector<std::vector<bool>>&) override;
};


#endif
