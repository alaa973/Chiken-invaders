#pragma once 
#include<SFML/Graphics.hpp>
#define winmenu  2
using namespace sf;

class Menuu3
{
public:
	Menuu3(float width, float hight);
	void draw(RenderWindow& window4);
	void moveUp();
	void moveDown();
	int winMenuPressed() {
		return winMenuSelected;
	}
	~Menuu3();

private:
	int winMenuSelected;
	Font font;
	Text winMenuu[winmenu];

};
