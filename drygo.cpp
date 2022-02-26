#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(960, 640), "Drug");//Создание окна
    CircleShape shape(100.f);// Чёрный круг
    shape.setFillColor(Color::Black);
    double tposx = 950;
    double tposy = 0;
    int n = 1;
    int m = 1;
   
    Image samolet;
    samolet.loadFromFile("C:/Users/User/source/repos/ConsoleApplication4/images/discowar.jpg");//Диско шар
   
    Texture samolet_tex;
    samolet_tex.loadFromImage(samolet);

    Sprite s_samolet;
    s_samolet.setTexture(samolet_tex);
    s_samolet.setTextureRect(IntRect(0, 0, 260, 260));

    Image map_image;
    map_image.loadFromFile("C:/Users/User/source/repos/ConsoleApplication4/images/map_pap.jpg");//Задний фон

    Texture map;
    map.loadFromImage(map_image);

    Sprite s_map;
    s_map.setTexture(map);

    Image dryg;
    dryg.loadFromFile("images/dryg.png");
   

    Texture drygtex;
    drygtex.loadFromImage(dryg);

    Sprite drygsprite;
    drygsprite.setTexture(drygtex);
    drygsprite.setTextureRect(IntRect(0, 192, 96, 96));
    drygsprite.setPosition(50, 25);

    float CurrentFrame = 0;

    Clock vremya;// Время для анимации коня
    double posx = 200;
    double posy = 0;
    while (window.isOpen())
    {
        shape.setPosition(tposx, tposy);
        if (tposx < 960) {
            tposx = tposx + 0.1;
            tposy = tposy + 0.01;
        }
        else {
            n++;
            tposx = 960 - n * 10;
            tposy = 0;
        }
        s_samolet.setPosition(posx, posy);
        if ((posx < 960) && (posy < 640)) {
            posx = posx + 0.14;
                posy = posy + 0.14;
        }
        else {
            m++;
            posx = 0 + m * 100;
            posy = 0;
            if (m * 100 > 640)
                m = 0;
        }
    
        float time = vremya.getElapsedTime().asMicroseconds();
        vremya.restart();
        time = time / 600;
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) { 
            CurrentFrame += 0.005 * time;
            if (CurrentFrame > 3) CurrentFrame -= 3; 
            drygsprite.setTextureRect(IntRect(96 * int(CurrentFrame), 96, 96, 96));
            drygsprite.move(-0.1 * time, 0);
    }
      
        if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
            CurrentFrame += 0.005 * time; 
            if (CurrentFrame > 3) CurrentFrame -= 3; 
            drygsprite.setTextureRect(IntRect(96 * int(CurrentFrame), 192, 96, 96));
            drygsprite.move(0.1 * time, 0);
    }
        if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
            CurrentFrame += 0.005 * time; 
            if (CurrentFrame > 3) CurrentFrame -= 3; 
            drygsprite.setTextureRect(IntRect(96 * int(CurrentFrame), 288, 96, 96)); 
            drygsprite.move(0, -0.1 * time);
        }
        if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) {
            CurrentFrame += 0.005 * time;
            if (CurrentFrame > 3) CurrentFrame -= 3; 
            drygsprite.setTextureRect(IntRect(96 * int(CurrentFrame), 0, 96, 96)); 
            drygsprite.move(0, 0.1 * time);
        }


        window.clear();

        s_map.setPosition(0, 0);
        s_map.setTextureRect(IntRect(0, 0, 960, 640));
       
        window.draw(s_map);
        window.draw(s_samolet);
        window.draw(shape);
        window.draw(drygsprite);
        window.display();
    }

    return 0;
}
