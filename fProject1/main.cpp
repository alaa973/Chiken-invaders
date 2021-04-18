#include<SFML\Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Menuu.h"
#include "Menuu2.h"
#include "Menuu3.h"
#include <sstream>


using namespace sf;
using namespace std;

//declarations
int shoottimer = 0, counter = 0, score = 0;
bool ssscore = false, bcounter = false;
RenderWindow window(VideoMode(1300, 720), "Chicken invaders", Style::Titlebar | Style::Close);
CircleShape bullets;
vector <CircleShape> fire;
CircleShape eggs;
vector <CircleShape> egg;
Sprite BackgroundSprite, OpenSprite, OpenFont, rocketsprite, Namesprite, gameoversprie, BackgroundmenuSprite, winsprite;
Texture BackgroundTexture, redChickenTexture, blueChickenTexture, OpenTexture, OpenText, rockettext, Name, gameovertexture
, BackgroundmenuTexture, winTexture, burgerTexture;
Sprite redChickenSprite[2][10], blueChickenSprite[2][10];
Sprite newbluechikensprite[2][10], newredchikensprite[2][10], burgerspriteblue[2][10], burgerspritered[2][10];
SoundBuffer startbuffer, gamebuffer, chickenbuffer, rocketbuffer, winbuffer, losebuffer, eatbuffer;
Sound start(startbuffer), game(gamebuffer), chickensound(chickenbuffer), rocketsound(rocketbuffer), win(winbuffer), lose(losebuffer), eatsound(eatbuffer);

//functions declaration
void PosTextureScale();
void movingChickens();
void closingWindow();
bool opening = false, re;
void gameOpening();
void windowDraw();
void movingRocket();
void movingBullets();
void ChickenEggs();
void loseMenu();
void Win_Lose();
void pauseMenu();


int main()
{
    PosTextureScale();

    start.play();

    while (window.isOpen())
    {

        closingWindow();
        if (!opening)
        {
            gameOpening();

        }

        do
        {
            if (opening)
            {
                movingChickens();
                movingRocket();
                movingBullets();
                ChickenEggs();
                Win_Lose();


                // score 
                Font font;
                font.loadFromFile("Prima.ttf");

                ostringstream sscore;
                sscore << "Score " << score;
                Text lblscore;
                lblscore.setCharacterSize(30);
                lblscore.setPosition(10, 10);
                lblscore.setFont(font);
                lblscore.setString(sscore.str());
                if (ssscore == true)
                {
                    score++;
                    ssscore = false;
                }



                window.clear();
                windowDraw();
                window.draw(lblscore);
                window.display();
            }

            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                pauseMenu();
            }

        } while (re);

    }

    return 0;
}

void PosTextureScale()
{
    //bullets
    bullets.setFillColor(Color::Red);
    bullets.setRadius(5.f);

    //Enemy Eggs
    eggs.setFillColor(Color::White);
    eggs.setRadius(5.5f);

    //background
    BackgroundSprite.setScale(1.7, 1);
    OpenText.loadFromFile("enter2.png");
    OpenFont.setTexture(OpenText);
    OpenFont.setPosition(150, -200);
    OpenFont.setScale(.9, .9);
    Name.loadFromFile("k.png");
    BackgroundTexture.loadFromFile("back.png");
    BackgroundSprite.setTexture(BackgroundTexture);
    OpenTexture.loadFromFile("p.jpg");
    OpenSprite.setScale(1.5, 1);
    OpenSprite.setTexture(OpenTexture);
    Namesprite.setTexture(Name);
    Namesprite.setScale(.7, .7);
    Namesprite.setPosition(100, 300);

    //sound
    startbuffer.loadFromFile("start.wav");
    gamebuffer.loadFromFile("game.wav");
    chickenbuffer.loadFromFile("chickensound.wav");
    rocketbuffer.loadFromFile("rocket.wav");
    winbuffer.loadFromFile("win.wav");
    losebuffer.loadFromFile("lose.wav");
    eatbuffer.loadFromFile("eatsound.wav");

    //rocket
    rockettext.loadFromFile("rocket.png");
    rocketsprite.setScale(.09, .08);
    rocketsprite.setPosition(750, 810);
    rocketsprite.setTexture(rockettext);

    //chickens
    redChickenTexture.loadFromFile("redchicken.png");
    blueChickenTexture.loadFromFile("bluechicken.png");

    //gameIcon
    Image icon;
    icon.loadFromFile("iconn.png");
    window.setIcon(76, 82, icon.getPixelsPtr());

    //gameover
    gameovertexture.loadFromFile("gameoverrr.jpg");
    gameoversprie.setTexture(gameovertexture);
    gameoversprie.setScale(1.4, 0.4);
    //pause 
    BackgroundmenuTexture.loadFromFile("back.png");
    BackgroundmenuSprite.setTexture(BackgroundmenuTexture);

    //win
    winTexture.loadFromFile("winn.jpg");
    winsprite.setTexture(winTexture);
    winsprite.setScale(1.7, 1.8);

    //burger
    burgerTexture.loadFromFile("burger.png");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 10; j++)
        {
            burgerspritered[i][j].setTexture(burgerTexture);
            burgerspritered[i][j].setScale(0.05, 0.05);
            burgerspritered[i][j].setPosition(1500, 1500);
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 10; j++)
        {
            burgerspriteblue[i][j].setTexture(burgerTexture);
            burgerspriteblue[i][j].setScale(0.05, 0.05);
            burgerspriteblue[i][j].setPosition(1500, 1500);
        }
    }
    float x, y = 50;    //red chicken position

    for (int i = 0; i < 2; i++)
    {
        x = 255;

        for (int j = 0; j < 10; j++)
        {
            redChickenSprite[i][j].setTexture(redChickenTexture);
            redChickenSprite[i][j].setPosition(x, y);
            x += 100;
            redChickenSprite[i][j].setScale(0.2, 0.2);
        }
        y += 100;
    }

    x, y, y = 250;  //blue chicken position

    for (int i = 0; i < 2; i++)
    {
        x = 255;

        for (int j = 0; j < 10; j++)
        {
            blueChickenSprite[i][j].setTexture(blueChickenTexture);
            blueChickenSprite[i][j].setPosition(x, y);
            x += 100;
            blueChickenSprite[i][j].setScale(0.15, 0.15);
        }

        y += 100;
    }

}

void closingWindow()
{
    Event evnt;

    while (window.pollEvent(evnt))
    {
        if (evnt.type == evnt.Closed)
            window.close();
    }
}

void gameOpening()
{

    if (!opening)
    {
        window.draw(OpenSprite);
        window.draw(OpenFont);
        window.draw(Namesprite);
        window.display();
    }
    if (Keyboard::isKeyPressed(Keyboard::Enter))
    {
        opening = true;
        window.clear();
        start.stop();
        game.play();
        return;
    }
}

void windowDraw()
{
    // backgroud
    window.draw(BackgroundSprite);

    //chicken
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            window.draw(redChickenSprite[i][j]);
            window.draw(blueChickenSprite[i][j]);
        }
    }

    //rocket
    window.draw(rocketsprite);

    //bullets
    for (size_t i = 0; i < fire.size(); i++)
    {
        window.draw(fire[i]);
    }
    //Eggs
    for (size_t i = 1; i < egg.size(); i++)
    {
        window.draw(egg[i]);
    }
    //burger
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 10; j++) {

            window.draw(burgerspritered[i][j]);
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 10; j++) {

            window.draw(burgerspriteblue[i][j]);
        }
    }
}

bool rightt = true;
void movingChickens()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (redChickenSprite[i][j].getPosition().x <= 1400 && rightt)
            {
                redChickenSprite[i][j].move(0.4, 0);
                blueChickenSprite[i][j].move(0.4, 0);
            }

            if (redChickenSprite[i][j].getPosition().x >= 1400)
                rightt = false;

            if (redChickenSprite[i][j].getPosition().x > 10)
            {
                redChickenSprite[i][j].move(-0.2, 0);
                blueChickenSprite[i][j].move(-0.2, 0);
            }

            if (redChickenSprite[i][j].getPosition().x <= 10)
                rightt = true;
        }
    }
}

void movingRocket()
{
    if (Keyboard::isKeyPressed(Keyboard::Right) && rocketsprite.getPosition().x < 1400)
    {
        rocketsprite.move(2.2f, 0);
    }

    if (Keyboard::isKeyPressed(Keyboard::Left) && rocketsprite.getPosition().x > 10)
    {
        rocketsprite.move(-2.2f, 0);
    }

    if (Keyboard::isKeyPressed(Keyboard::Up) && rocketsprite.getPosition().y >= 70)
    {
        rocketsprite.move(0, -2.2f);
    }

    if (Keyboard::isKeyPressed(Keyboard::Down) && rocketsprite.getPosition().y < 810)
    {
        rocketsprite.move(0, 2.2f);
    }
}

void  movingBullets()
{

    if (shoottimer < 100)   //area between two bullets
        shoottimer++;

    if (Keyboard::isKeyPressed(Keyboard::Space) && shoottimer >= 100)
    {
        bullets.setPosition(rocketsprite.getPosition().x + 37, rocketsprite.getPosition().y - 7);
        fire.push_back(CircleShape(bullets));
        shoottimer = 0;
        rocketsound.play();
    }

    for (size_t i = 0; i < fire.size(); i++)
    {
        fire[i].move(0.f, -2.2f);

        if (fire[i].getPosition().y < 0)
            fire.erase(fire.begin() + i);
    }

    // collision

    for (size_t i = 0; i < fire.size(); i++)
    {
        for (size_t k = 0; k < 2; k++)
        {
            for (size_t j = 0; j < 10; j++)
            {
                if (fire[i].getGlobalBounds().intersects(blueChickenSprite[k][j].getGlobalBounds()))
                {
                    chickensound.play();
                    newbluechikensprite[k][j] = blueChickenSprite[k][j];
                    blueChickenSprite[k][j].setPosition(1000, 1000);
                    fire[i].setPosition(1500, 1500);
                    ssscore = true;
                    bcounter = true;
                    burgerspriteblue[k][j].setPosition(newbluechikensprite[k][j].getPosition().x,
                        newbluechikensprite[k][j].getPosition().y);
                    burgerspriteblue[k][j].move(0.f, 0.2f);


                }

                burgerspriteblue[k][j].move(0.f, 0.2f);

                //collision between the rocket and burger
                if (burgerspriteblue[k][j].getGlobalBounds().intersects(rocketsprite.getGlobalBounds()))
                {
                    burgerspriteblue[k][j].setPosition(1600, 1600);
                    eatsound.play();

                }

            }

            for (size_t j = 0; j < 10; j++)
            {
                if (fire[i].getGlobalBounds().intersects(redChickenSprite[k][j].getGlobalBounds()))
                {
                    chickensound.play();
                    newredchikensprite[k][j] = redChickenSprite[k][j];
                    redChickenSprite[k][j].setPosition(1000, 1000);
                    fire[i].setPosition(1500, 1500);
                    ssscore = true;
                    bcounter = true;
                    burgerspritered[k][j].setPosition(newredchikensprite[k][j].getPosition().x,
                        newredchikensprite[k][j].getPosition().y);
                    burgerspritered[k][j].move(0.f, 0.2f);

                }
                burgerspritered[k][j].move(0.f, 0.2f);

                if (burgerspritered[k][j].getGlobalBounds().intersects(rocketsprite.getGlobalBounds()))
                {
                    burgerspritered[k][j].setPosition(1600, 1600);
                    eatsound.play();

                }
            }

        }

    }
}



void ChickenEggs()
{
    srand((unsigned int)time(NULL));

    int a, b;

    //BlueChicken Eggs
    if (shoottimer < 350)
        shoottimer++;

    if (shoottimer >= 350)
    {

        b = rand() % 10;
        a = rand() % 2;
        eggs.setPosition(blueChickenSprite[a][b].getPosition().x + 37, blueChickenSprite[a][b].getPosition().y + 60);
        egg.push_back(CircleShape(eggs));
        shoottimer = 0;
    }

    //RedChicken Eggs
    if (shoottimer < 350)
        shoottimer++;

    if (shoottimer >= 350)
    {
        b = rand() % 10;
        a = rand() % 2;
        eggs.setPosition(redChickenSprite[a][b].getPosition().x + 37, redChickenSprite[a][b].getPosition().y + 60);
        egg.push_back(CircleShape(eggs));
        shoottimer = 0;
    }

    for (size_t i = 0; i < egg.size(); i++)
    {
        egg[i].move(0.f, 1.0f);

        if (egg[i].getPosition().y < 0)
            egg.erase(egg.begin());
    }
}

void loseMenu() {

    RenderWindow window3(VideoMode(1500, 900), "lose", Style::None);
    Menuu2 menu2(1500, 900);

    while (window3.isOpen())
    {

        Event event2;

        while (window3.pollEvent(event2))
        {
            if (event2.type == event2.Closed)
                window3.close();

            if (event2.type == Event::KeyReleased)
            {
                if (event2.key.code == Keyboard::Up)
                {
                    menu2.moveUp();
                    break;
                }

                if (event2.key.code == Keyboard::Down)
                {
                    menu2.moveDown();
                    break;
                }

                if (event2.key.code == ::Keyboard::Return)
                {
                    if (menu2.loseMenuPressed() == 0)
                    {
                        lose.stop();
                        window.clear();
                        fire.clear();
                        egg.clear();
                        PosTextureScale();
                        window3.close();
                        game.play();
                        re = 1;
                        return;
                    }

                    if (menu2.loseMenuPressed() == 1)
                    {
                        window3.close();
                        window.close();
                        re = 0;
                    }
                }
            }
        }
        window3.clear();
        window3.draw(gameoversprie);
        menu2.draw(window3);
        window3.display();
    }
}

void WinMenu() {

    RenderWindow window4(VideoMode(1500, 900), "win", Style::None);
    Menuu3 menu3(1500, 900);

    while (window4.isOpen())
    {

        Event event3;

        while (window4.pollEvent(event3))
        {
            if (event3.type == event3.Closed)
                window4.close();

            if (event3.type == Event::KeyReleased)
            {
                if (event3.key.code == Keyboard::Up)
                {
                    menu3.moveUp();
                    break;
                }

                if (event3.key.code == Keyboard::Down)
                {
                    menu3.moveDown();
                    break;
                }

                if (event3.key.code == ::Keyboard::Return)
                {
                    if (menu3.winMenuPressed() == 0)
                    {
                        cout << "next level" << endl;
                    }

                    if (menu3.winMenuPressed() == 1)
                    {
                        window4.close();
                        window.close();

                    }
                }
            }
        }
        window4.clear();
        window4.draw(winsprite);
        menu3.draw(window4);
        window4.display();
    }
}







void Win_Lose()
{
    //Lose
    for (size_t i = 0; i < egg.size(); i++)
    {

        if (egg[i].getGlobalBounds().intersects(rocketsprite.getGlobalBounds()))
        {
            window.clear();
            game.stop();
            lose.play();
            window.display();
            loseMenu();
        }

        for (size_t k = 0; k < 2; k++)
        {
            for (size_t j = 0; j < 10; j++)
            {
                if (rocketsprite.getGlobalBounds().intersects(blueChickenSprite[k][j].getGlobalBounds()))
                {
                    window.clear();
                    game.stop();
                    lose.play();
                    window.display();
                    loseMenu();
                    return;
                }
                if (rocketsprite.getGlobalBounds().intersects(redChickenSprite[k][j].getGlobalBounds()))
                {
                    window.clear();
                    game.stop();
                    lose.play();
                    window.display();
                    loseMenu();
                    return;
                }
            }
        }

    }

    //Win

    if (bcounter == true) {
        counter++;
        bcounter = false;

    }

    if (counter == 40) {
        window.clear();
        game.stop();
        win.play();
        window.display();
        WinMenu();
        counter--;
    }
}


void pauseMenu()
{
    RenderWindow window2(VideoMode(400, 150), "paused", Style::None);
    Menuu menu(400, 150);
    while (window2.isOpen())
    {
        Event event;

        while (window2.pollEvent(event))
        {
            if (event.type == event.Closed)
                window2.close();

            if (event.type == Event::KeyReleased)
            {
                if (event.key.code == Keyboard::Up)
                {
                    menu.moveUp();
                    break;
                }

                if (event.key.code == Keyboard::Down)
                {
                    menu.moveDown();
                    break;
                }

                if (event.key.code == ::Keyboard::Return)
                {
                    if (menu.pauseMenuPressed() == 0)
                    {
                        window2.close();
                    }
                    if (menu.pauseMenuPressed() == 1)
                    {
                        window2.close();
                        window.close();
                        re = 0;

                    }
                }
            }
        }

        window2.clear();
        window2.draw(BackgroundmenuSprite);
        menu.draw(window2);
        window2.display();
    }

}