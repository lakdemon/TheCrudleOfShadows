#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include <functional>

/*██████████▀▀▀▀▀▀▀▀▀▀▀▀▀██████████
  █████▀▀░░░░░░░░░░░░░░░░░░░▀▀█████
  ███▀░░░░░░░░░░░░░░░░░░░░░░░░░▀███
  ██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██
  █░░░░░░▄▄▄▄▄▄░░░░░░░░▄▄▄▄▄▄░░░░░█
  █░░░▄██▀░░░▀██░░░░░░██▀░░░▀██▄░░█
  █░░░██▄░░▀░░▄█░░░░░░█▄░░▀░░▄██░░█
  ██░░░▀▀█▄▄▄██░░░██░░░██▄▄▄█▀▀░░██
  ███░░░░░░▄▄▀░░░████░░░▀▄▄░░░░░███
  ██░░░░░█▄░░░░░░▀▀▀▀░░░░░░░█▄░░░██
  ██░░░▀▀█░█▀▄▄▄▄▄▄▄▄▄▄▄▄▄▀██▀▀░░██
  ███░░░░░▀█▄░░█░░█░░░█░░█▄▀░░░░███
  ████▄░░░░░░▀▀█▄▄█▄▄▄█▄▀▀░░░░▄████
  ███████▄▄▄░░░░░░░░░░░░░▄▄▄███████
  ███████████▄▄▄▄▄▄▄▄▄▄▄███████████
*/

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

    Player()
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

    void update(float timer)
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

    void changeDirection(char d)
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
    
    ~Player(){};
};

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
    GameObject(){};
    ~GameObject(){};
    GameObject(sf::String config){

        
    };
};


class Transcluent
{
    public:
    bool is_transcluent;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Texture alpha;
    Triangle first;
    Triangle second;
    Triangle third;
    Triangle fourth;

    Transcluent(float x1,float x2,float y1,float y2){

        is_transcluent=false;
        texture.loadFromFile("Images/Test/Objects/1.png");
        alpha.loadFromFile("Images/Test/Objects/1t.png");
        sprite.setTexture(texture);
        sprite.setPosition(0,0);

        first.a.x=64;  first.a.y=136;
        first.b.x=204; first.b.y=239;
        first.c.x=63;  first.c.y=303;

        second.a.x=64;  second.a.y=136;
        second.b.x=204; second.b.y=71;
        second.c.x=204;  second.c.y=239;

        first.a.x=204;  first.a.y=71;
        first.b.x=335; first.b.y=136;
        first.c.x=204;  first.c.y=239;

        second.a.x=204;  second.a.y=71;
        second.b.x=335; second.b.y=136;
        second.c.x=335;  second.c.y=303;

    };
    //64,136
    //204,239
    //64,303
    ~Transcluent(){};
};


class Usable
{
public:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Texture textureLight;
    Triangle t1,t2;
    bool reacheble;

    Usable(){
        texture.loadFromFile("Images/Trash/potion.png");
        textureLight.loadFromFile("Images/Trash/potionlight.png");
        sprite.setTexture(texture);
        sprite.setPosition(400,400);
        reacheble=false;

    };
    ~Usable(){};


    std::function<void()> activate;
    template<typename... Args>
    void assign(Args... args)
    {
        activate = std::bind(args...);
    }
};


//#########################################################################

int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 600), "The Crudlle of shadows");
    //window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    Triangle triangle1(sf::Vector2f(64,136),sf::Vector2f(204, 239),sf::Vector2f(63, 303));
    Triangle triangle2(sf::Vector2f(64,136),sf::Vector2f(204, 71),sf::Vector2f(204, 239));
    Triangle triangle3(sf::Vector2f(204,71),sf::Vector2f(335, 136),sf::Vector2f(204, 239));
    Triangle triangle4(sf::Vector2f(204,239),sf::Vector2f(335, 136),sf::Vector2f(336, 303));

    Triangle solidtriangle1(sf::Vector2f(64,303),sf::Vector2f(335, 303),sf::Vector2f(204, 376));
    Triangle solidtriangle2(sf::Vector2f(64,303),sf::Vector2f(335, 303),sf::Vector2f(204, 239));

    Triangle usabletriangle1(sf::Vector2f(49+400,94+400),sf::Vector2f(17+400, 75+400),sf::Vector2f(50+400, 56+400));
    Triangle usabletriangle2(sf::Vector2f(49+400,94+400),sf::Vector2f(50+400, 56+400),sf::Vector2f(82+400, 75+400));
/*
    if(glm::gtx::intersect::intersectLineTriangle 	(sf::Vector2f(64,136),
		genType const &  	dir,
		genType const &  	vert0,
		genType const &  	vert1,
		genType const &  	vert2,
		genType &  	position 
	) 	)
*/

    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(200,200));
    shape.setFillColor(sf::Color::Green);

    sf::CircleShape circle(3);
    sf::CircleShape circle2(3);
   
    Player player;
    sf::Clock clock;
    float time;

    Transcluent trasncluents(100,100,200,200);
    trasncluents.sprite.setPosition(0,0);

    Usable potion;

   
    sf::View camera(sf::FloatRect(200, 200, 900, 600));
    camera.setCenter(player.x,player.y);
    window.setView(camera);

    sf::Sprite grid;
    sf::Texture tex;
    tex.loadFromFile("Isometric-Paper-04.png");
    grid.setTexture(tex);
    

    while (window.isOpen())
    {
        time = clock.getElapsedTime().asMilliseconds();
        clock.restart();
        time/=80;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::KeyReleased){
                if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::D)
                {player.dx=0;player.dy=0;}}

        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            { player.dx=1;  player.dy=-1; player.changeDirection('f');}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            { player.dx=-1; player.dy=1;  player.changeDirection('b');}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            { player.dx=-1; player.dy=-1; player.changeDirection('l');}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            { player.dx=1;  player.dy=1;  player.changeDirection('r');}

        shape.rotate(1);
        player.update(time);

        if(solidtriangle1.inTriangle(player.sprite.getPosition()) ||
        solidtriangle2.inTriangle(player.sprite.getPosition()) )
        {
            //player.sprite.move(-player.dx*player.speed*1.75*time,-player.dy*player.speed*time);
            player.dy*=-1;
            player.dx*=-1;
            player.update(time);
        }

        circle.setPosition(player.sprite.getPosition().x-5,player.sprite.getPosition().y-5);
        circle2.setPosition(player.sprite.getPosition().x-2+20,player.sprite.getPosition().y-2+10);


       // if(trasncluents.first.inTriangle(player.sprite.getPosition()))//||trasncluents.second.inTriangle(player.sprite.getPosition()))//||trasncluents.third.inTriangle(player.sprite.getPosition())||trasncluents.fourth.inTriangle(player.sprite.getPosition()))
       //     trasncluents.sprite.setTexture(trasncluents.alpha);
        //else
        //trasncluents.sprite.setTexture(trasncluents.texture);
         //std::cout << player.sprite.getPosition().x<<" " <<player.sprite.getPosition().y<<std::endl;

        if(usabletriangle1.inTriangle(circle2.getPosition()) ||
        usabletriangle2.inTriangle(circle2.getPosition()) ){
            potion.sprite.setTexture(potion.textureLight);
            potion.reacheble==true;
        }
        else
            potion.sprite.setTexture(potion.texture);

        if(triangle1.inTriangle(player.sprite.getPosition()) ||
        triangle2.inTriangle(player.sprite.getPosition()) ||
        triangle3.inTriangle(player.sprite.getPosition()) ||
        triangle4.inTriangle(player.sprite.getPosition())){
            trasncluents.sprite.setTexture(trasncluents.alpha);
            trasncluents.is_transcluent=true;
        }
        else{
            trasncluents.sprite.setTexture(trasncluents.texture);
            trasncluents.is_transcluent=false;
        }


        
        camera.setCenter(player.x,player.y);
        window.setView(camera);
        window.clear(sf::Color(20,20,20));
        window.draw(grid);
        //window.draw(shape);
        if(trasncluents.is_transcluent==false) window.draw(trasncluents.sprite);
        window.draw(player.sprite);
         window.draw(circle);
         window.draw(circle2);
        if(trasncluents.is_transcluent==true) window.draw(trasncluents.sprite);
        
       
        //window.draw(triangle1.convex);
         //window.draw(triangle2.convex);
          //window.draw(triangle3.convex);
          // window.draw(triangle4.convex);
          window.draw(potion.sprite);
        window.display();
    }

    return 0;
}

