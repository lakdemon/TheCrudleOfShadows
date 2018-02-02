#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

class Triangle
{
    public:
    sf::Vector2f a;
    sf::Vector2f b;
    sf::Vector2f c;
    sf::ConvexShape convex;

    Triangle(){};
    Triangle(sf::Vector2f A,sf::Vector2f B, sf::Vector2f C){
    a=A; b=B; c=C;
    convex.setPointCount(3);
    convex.setPoint(0,a);
    convex.setPoint(1,b);
    convex.setPoint(2,c);};
    ~Triangle(){};
    

    
    bool inTriangle(sf::Vector2f d)
    {
        float m;
        float lambda;
        float Bx, By, Cx, Cy, Dx, Dy;
        Bx = b.x - a.x; By = b.y - a.y;
        Cx = c.x - a.x; Cy = c.y - a.y;
        Dx = d.x - a.x; Dy = d.y - a.y;
        m = (Dx*By - Bx*Dy) / (Cx*By - Bx*Cy);
        if( (m >= 0) && (m <= 1) )
        {
            lambda = (Dx - m*Cx) / Bx;
            if( (lambda >= 0) and ((m + lambda) <= 1) )
            return true;
        }
        return false;
    }

};


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
    sf::Sprite sprite;


    GameObject(){};
    ~GameObject(){};
    GameObject(sf::String config){
        std::fstream file(config);
        std::string str;
        size_t pos;

            getline(file,str);
            if(str.find("true")!=std::string::npos)
            {
                Transcluent=true;
                getline(file,str);
                int x1,x2,x3,y1,y2,y3;
                while(str!="}")
                {
                    file >> str;
                }
            }
            else
            {
                Transcluent=false;
                getline(file,str);
                getline(file,str);
            }
            getline(file,str);
            if(str.find("true")!=std::string::npos)
                Solid=true;
            else
                Solid=false;
            getline(file,str);
            if(str.find("true")!=std::string::npos)
                Usable=true;
            else
                Usable=false;

            if(texture.loadFromFile("Resources/Textures/1.png")!=NULL)
                this->setTexture(texture);
            else
                std::cout << "texture can't be load" << std::endl;

    file.close();       
    };
};


int main()
{
    GameObject obj("Resources/Objects/Level0/1");

    if(obj.Transcluent)
    std::cout << "Object is Transcluent"<<std::endl;
        if(obj.Solid)
    std::cout << "Object is Solid"<<std::endl;
        if(obj.Usable)
    std::cout << "Object is Usable"<<std::endl;

    sf::RenderWindow window(sf::VideoMode(900, 600), "The Crudlle of shadows");


    while(window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

        }


        window.clear(sf::Color(20,20,20));
        window.draw(obj);
        window.display();
    }


}