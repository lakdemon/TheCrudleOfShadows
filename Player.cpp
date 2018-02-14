#include "Player.h"

    Player::Player()
    {
        texture.loadFromFile("Images/Test/Animations/basic_human.png");
        sprite.setTexture(texture);
        textureX=0;
        textureY=0;
        sprite.setTextureRect(sf::IntRect(textureX,textureY,130,192));
        sprite.setScale(0.5,0.5);
        x=450;
        y=300;
        sprite.setPosition(x,y);
        dx=0;
        dy=0;
        speed = 10.5;
        sprite.setOrigin(60,170);
        frameCounter=0;

        animationspeed=7;
        //чем больше тем медленнее;
        
    };

    void Player::update(float timer)
    {
        if(dx!=0)
        {
            frameCounter++;
            if(frameCounter==animationspeed)
            {            
                textureY+=192;
                if(textureY>720)textureY=192;
                    sprite.setTextureRect(sf::IntRect(textureX,textureY,130,192));
                frameCounter=0;
            }
        }
        else
            sprite.setTextureRect(sf::IntRect(textureX,0,130,192));

        x+=dx*speed*1.75*timer;
        y+=dy*speed*timer;
        sprite.setPosition(x,y);
    }

    void Player::changeDirection(char d)
    {
        switch(d)
        {
            case 'f':
                textureX=0;
            break;
            case 'b':
                textureX=260;
            break;
            case 'r':
                textureX=390;
            break;
            case 'l':
                textureX=130;
            break;            
        }
        
        //sprite.setTextureRect(sf::IntRect(textureX,0,130,180));

    }
    
    Player::~Player(){};