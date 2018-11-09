#ifndef TIMER_H
#define TIMER_H
#include <math.h>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>


class Text : public sf::Text
{
public:
    Text();

private:
    int fontsize;
    sf::Font font;
};

#endif
