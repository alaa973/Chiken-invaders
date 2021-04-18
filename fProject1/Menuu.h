#pragma once 
#include<SFML/Graphics.hpp>
#define pausemenu  2
using namespace sf;

class Menuu
{
public:
	Menuu(float width, float hight);
	void draw(RenderWindow& window2);
	void moveUp();
	void moveDown();
	int pauseMenuPressed() {
		return pauseMenuSelected;
	}
	~Menuu();

private:
	int pauseMenuSelected;
	Font font;
	Text pauseMenuu[pausemenu];

};