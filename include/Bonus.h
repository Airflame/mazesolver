#ifndef BONUS_H
#define BONUS_H
#include <SFML/Graphics.hpp>


class Bonus : public sf::Sprite
{
public:
    Bonus() = default;
    Bonus(sf::Vector2f, float);
    virtual ~Bonus() = default;
    sf::Vector2f getLocation();
    virtual void use(std::vector<std::vector<bool>>&) = 0;

protected:
    void scale();
    sf::Vector2f location;
    sf::Texture texture;
    float size = 1;
};


#endif
