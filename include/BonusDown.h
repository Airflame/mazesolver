#ifndef BONUSDOWN_H
#define BONUSDOWN_H
#include "Bonus.h"


class BonusDown : public Bonus
{
public:
    BonusDown() = default;
    BonusDown(sf::Vector2f, float);
    void use(std::vector<std::vector<bool>>&) override;
};


#endif
