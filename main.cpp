#include "GameObject.h"

int main()
{

    std::vector<GameObject> objects;
    std::vector<GameObject> transcluent_objects;

    objects.push_back(GameObject("Resources/Objects/Level0/1"));
    objects.push_back(GameObject("Resources/Objects/Level0/1"));
    

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