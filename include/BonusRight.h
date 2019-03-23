#ifndef BONUSRIGHT_H
#define BONUSRIGHT_H
#include "Bonus.h"


class BonusRight : public Bonus
{
public:
    BonusRight() = default;
    BonusRight(sf::Vector2f, float);
    void use(std::vector<std::vector<bool>>&) override;
};


#endif