#include "GameObject.h"
#include <string>
#include <fstream>
#include <iostream>


void GameObject::update(){};

GameObject::GameObject(){};

GameObject::~GameObject(){};

GameObject::GameObject(std::string config)
{
    std::cout << "=========================" << std::endl;
    std::fstream file(config);
    std::string str;
    std::cout << "file " << config << " opened" << std::endl;

    //считываем данные о прозрачности
    getline(file,str);
    std::cout << str;
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
    
    //считываем данные о твердости
    getline(file,str);
    getline(file,str);
    std::cout << "\n" << str;
    if(str.find("true")!=std::string::npos)
    {
            Solid=true;
            std::cout << "\nobject has solid" << std::endl;
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
                solidTriangles.push_back(Triangle(sf::Vector2f(x1,y1),sf::Vector2f(x2,y2),sf::Vector2f(x3,y3)));

                file >> str;

            }
    }
    else
    {
        std::cout << "\nobject has not solid" << std::endl;
        Solid=false;
        getline(file,str);
        getline(file,str);
    }

    //считываем данные об использовании
    getline(file,str);
    getline(file,str);
    std::cout << "\n"  << str;
    if(str.find("true")!=std::string::npos)
    {
            Usable=true;
            std::cout << "\nobject has usable" << std::endl;
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
                usableTriangles.push_back(Triangle(sf::Vector2f(x1,y1),sf::Vector2f(x2,y2),sf::Vector2f(x3,y3)));

                file >> str;

            }
    }
    else
    {
        std::cout << "\nobject has not usable" << std::endl;
        Usable=false;
        getline(file,str);
        getline(file,str);
    }
    
    //подгрузка текстур
    file >> str;
    if(Transcluent)
    {
        file >> str;
        texture.loadFromFile(str);
        this->setTexture(texture);
    }
    else file >> str;

    file >> str;
    if(Solid)
    {
        file >> str;
        solidTexture.loadFromFile(str);
    }
    else file >> str;

    file >> str;
    if(Usable)
    {
        file >> str;
        usableTexture.loadFromFile(str);
    }
    else file >> str;
    
    float x1,y1;
    file >> str;
    file >> str;
    x1=stof(str);
    file >> str;
    file >> str;
    y1=stof(str);
    setPosition(sf::Vector2f(x1,y1));

        
        file.close();
        std::cout << "file closed\n" << std::endl;
        std::cout << "=========================" << std::endl;
};