#include "../include/Text.h"

Text::Text()
{
    fontsize = 30;
    font.loadFromFile("res/Orbitron-Regular.ttf");
    setFont(font);
    setFillColor(sf::Color::White);
    setCharacterSize(static_cast<unsigned int>(fontsize));
    setOrigin(0,0);
}
