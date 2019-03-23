#ifndef BONUSUP_H
#define BONUSUP_H
#include "Bonus.h"


class BonusUp : public Bonus
{
public:
    BonusUp() = default;
    BonusUp(sf::Vector2f, float);
    void use(std::vector<std::vector<bool>>&) override;
};


#endif
