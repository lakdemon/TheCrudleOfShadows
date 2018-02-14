#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <SFML/Graphics.hpp>


class Triangle
{
    public:
    sf::Vector2f a;
    sf::Vector2f b;
    sf::Vector2f c;

    Triangle();
    Triangle(sf::Vector2f A,sf::Vector2f B, sf::Vector2f C);
    ~Triangle();
    bool inTriangle(sf::Vector2f d);

};


#endif