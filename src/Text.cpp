#include "../include/Text.h"

Text::Text()
{
    fontsize = 50;
    font.loadFromFile("res/Orbitron-Regular.ttf");
    setFont(font);
    setFillColor(sf::Color::White);
    setCharacterSize(fontsize);
    setOrigin(0,0);
}
