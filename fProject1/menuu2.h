#pragma once 
#include<SFML/Graphics.hpp>
#define losemenu  2
using namespace sf;

class Menuu2
{
public:
	Menuu2(float width, float hight);
	void draw(RenderWindow& window3);
	void moveUp();
	void moveDown();
	int loseMenuPressed() {
		return loseMenuSelected;
	}
	~Menuu2();

private:
	int loseMenuSelected;
	Font font;
	Text loseMenuu[losemenu];

};
