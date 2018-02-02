#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <iostream>

class GameObject : public sf::Sprite
{
    public:
    bool Transcluent;
    bool Solid;
    bool Usable;

    GameObject(){};
    ~GameObject(){};
    GameObject(sf::String config){
        std::fstream file(config);
        std::string str;
        size_t pos;
        //for(auto i=0;i<3;i++)
        //{
            getline(file,str);
            if(str.find("true")!=std::string::npos)
                Transcluent=true;
            else
                Transcluent=false;
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
        //}
        
        //while(getline(file, str))
        //{
        //    pos = str.find("true");
        //      
        //}

    file.close();       
    };
};


int main()
{
    GameObject obj("/Resources/Objects/Level0/1");

    if(obj.Transcluent)
    std::cout << "Object is Transcluent"<<std::endl;
        if(obj.Solid)
    std::cout << "Object is Solid"<<std::endl;
        if(obj.Usable)
    std::cout << "Object is Usable"<<std::endl;


}