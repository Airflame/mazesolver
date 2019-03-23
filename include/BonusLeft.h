#ifndef BONUSLEFT_H
#define BONUSLEFT_H
#include "Bonus.h"


class BonusLeft : public Bonus
{
public:
    BonusLeft() = default;
    BonusLeft(sf::Vector2f, float);
    void use(std::vector<std::vector<bool>>&) override;
};


#endif
