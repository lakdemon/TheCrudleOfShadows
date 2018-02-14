#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>


class Player
{
    public: 
    sf::Texture texture;
    sf::Sprite sprite;
    float x,y;
    int dx,dy;
    float speed;
    int textureX;
    int textureY;
    int frameCounter;
    int animationspeed;

    Player();
    void update(float timer);
    void changeDirection(char d);
    ~Player();
};

#endif