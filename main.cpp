#include "GameObject.h"
#include <iostream>
#include <fstream>
#include <string>

class Level
{
    public:
    std::vector<GameObject> objects;
    std::vector<GameObject> transcluent_objects;

    Level(){};
    
    Level(std::string str)
    {
        loadFromFile(str);
    }

    ~Level()
    {
        if(!objects.empty())                objects.clear();
        if(!transcluent_objects.empty())    transcluent_objects.clear();
    };
    
    void loadFromFile(std::string name)
    {
        if(!objects.empty())                objects.clear();
        if(!transcluent_objects.empty())    transcluent_objects.clear();

        std::string Path = "Resources/Objects/" + name; 
        
        std::cout << "openning level config: " << Path+"/0" << std::endl;
        std::fstream file(Path+"/0");
        if(file.is_open())
            std::cout << "file opened" << std::endl;
        std::string objectName;

        while(getline(file,objectName))
        {            
            std::cout << "reading object config file: " << Path+"/"+objectName << std::endl; 
            objects.push_back(GameObject(Path+"/"+objectName));
        }

        std::cout << "file closed" << std::endl;
        file.close();


    };
};

int main()
{

    //std::vector<GameObject> objects;
    //std::vector<GameObject> transcluent_objects;

    //objects.push_back(GameObject("Resources/Objects/Level0/1"));
    //objects.push_back(GameObject("Resources/Objects/Level0/2"));
    
    Level level("test_level");

    sf::RenderWindow window(sf::VideoMode(900, 600), "The Crudlle of shadows");
    window.setFramerateLimit(60);


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
        
        /*
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
    */

        //############################################################################################
        //#################################   ОТРИСОВКА  #############################################

        // очищаем экран и закрашивает цветом
        window.clear(sf::Color(20,20,20));
      
        // прорисовываем все объекты
        for(auto it : level.objects)
            window.draw(it);
        
        // отрисовываем персонажа
        //window.draw(player);

        // отрисовываем полупрозрачные объекты
        for(auto it : level.transcluent_objects)
            window.draw(it);
        
        // отображаем всё на экране
        window.display();

        //############################################################################################
    }


}