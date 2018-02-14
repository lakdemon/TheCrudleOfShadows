#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Triangle.h"

class GameObject : public sf::Sprite
{
    public:
    bool Transcluent;
    bool Solid;
    bool Usable;
    std::vector<Triangle> transcluentTriangles;
    std::vector<Triangle> solidTriangles;
    std::vector<Triangle> usableTriangles;
    sf::Texture texture;
    sf::Texture solidTexture;
    sf::Texture usableTexture;
    sf::Sprite sprite;

    void update();
    GameObject();
    ~GameObject();
    GameObject(std::string config);
};



#endif


