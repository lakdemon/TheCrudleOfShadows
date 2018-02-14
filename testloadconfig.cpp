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

    Triangle(){};
    Triangle(sf::Vector2f A,sf::Vector2f B, sf::Vector2f C){
        a=A;
        b=B;
        c=C;
    };
    ~Triangle(){};
    bool inTriangle(sf::Vector2f d){
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
    };

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

    void update(){};
    GameObject(){};
    ~GameObject(){};
    GameObject(sf::String config){    

        std::fstream file(config);
        std::string str;

        //считываем данные о прозрачности
        getline(file,str);
        if(str.find("true")!=std::string::npos)
        {
            Transcluent=true;
            std::cout << "\nobject has transcluent" << std::endl;
            getline(file,str);
            float x1,x2,x3,y1,y2,y3;
            int i=0;
            while(str.find("}")==std::string::npos)
            {
                file >> str;
                x1=stof(str);
                
                file >> str;
                y1=stof(str);

                file >> str;
                x2=stof(str);
                
                file >> str;
                y2=stof(str);

                file >> str;
                x3=stof(str);
                
                file >> str;
                y3=stof(str);

                std::cout <<x1<<" "<<y1<<" " << x2<<" "<<y2<<" "<< x3<<" "<<y3<<" "<< std::endl;
                transcluentTriangles.push_back(Triangle(sf::Vector2f(x1,y1),sf::Vector2f(x2,y2),sf::Vector2f(x3,y3)));

                file >> str;

            }
        }
        else
        {
            std::cout << "\nobject has not transcluent" << std::endl;
            Transcluent=false;
            getline(file,str);
            getline(file,str);
        }

        
        file.close();
        
        /*std::fstream file(config);
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

        if(texture.loadFromFile("Resources/Textures/1.png")!=false)
            this->setTexture(texture);
         else
            std::cout << "texture can't be load" << std::endl;

        file.close();    */   
    };
};


int main()
{

    std::vector<GameObject> objects;
    std::vector<GameObject> transcluent_objects;

    objects.push_back(GameObject("Resources/Objects/Level0/1"));
    objects.push_back(GameObject("Resources/Objects/Level0/1"));
    

    sf::RenderWindow window(sf::VideoMode(900, 600), "The Crudlle of shadows");


    while(window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

        }

        //player.update();

        //#################################   ПРОВЕРКА ОБЪЕКТОВ  #############################################
        
        for(auto it : objects){
            it.update();
            if(it.Transcluent==true)
            {
                //transcluent objects add it
                //objects erase it
            }
        }

        for(auto it : objects){
            it.update();
            if(it.Transcluent==false)
            {
                //objects add it
                //transcluent objects erase it
            }
        }



        //############################################################################################
        //#################################   ОТРИСОВКА  #############################################

        // очищаем экран и закрашивает цветом
        window.clear(sf::Color(20,20,20));
      
        // прорисовываем все объекты
        for(auto it : objects)
            window.draw(it);
        
        // отрисовываем персонажа
        //window.draw(player);

        // отрисовываем полупрозрачные объекты
        for(auto it : transcluent_objects)
            window.draw(it);
        
        // отображаем всё на экране
        window.display();

        //############################################################################################
    }


}