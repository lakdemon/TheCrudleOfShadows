#include <iostream>
#include <functional>
#include <vector>

class Player
{
    public:
    Player(){};
    ~Player(){};
    std::vector<int> inventory;
};

class Usable
{   
    public:
    Usable(int code){keycode=code;};
    ~Usable(){};
    int keycode;
    std::function<void()> activate;
};


class Door
{
    public:
    bool opened;
    Door(){opened=false;};
    ~Door(){};

};

void addToInventory(Player *p, int code)
{
    p->inventory.push_back(code);
}

void changeState(Door *door)
{
    if(door->opened==false)
        door->opened=true;
    else
        door->opened=false;
}

int main()
{
    std::cout << "hi" << std::endl;

    Player player;
    Door door;
    Usable potion(1);
    Usable sword(2);
    Usable door_knob(243);

    potion.activate=std::bind(addToInventory,&player,potion.keycode);
    sword.activate=std::bind(addToInventory,&player,sword.keycode);
    door_knob.activate=std::bind(changeState,&door);
    
    sword.activate();
    potion.activate();

    for(auto it=player.inventory.begin();it!=player.inventory.end();it++)
        std::cout << *it << std::endl;
    
    std::cout << door.opened << std::endl;
    door_knob.activate();
     std::cout << door.opened << std::endl;

     std::cout << "bye" << std::endl;
    return 1;
}