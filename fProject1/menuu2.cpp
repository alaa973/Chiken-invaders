#include "Menuu2.h"
using namespace sf;
Menuu2::Menuu2(float width, float hight)
{
	if (!font.loadFromFile("prima.ttf")) {}
	loseMenuu[0].setFont(font);
	loseMenuu[0].setFont(font);
	loseMenuu[0].setFont(font);
	loseMenuu[0].setFillColor(Color::Blue);
	loseMenuu[0].setString("RETRY");
	loseMenuu[0].setCharacterSize(40);
	loseMenuu[0].setFont(font);
	loseMenuu[0].setPosition(Vector2f(width / 2 - 60, hight / (losemenu + 1) * 2.2));

	loseMenuu[1].setFont(font);
	loseMenuu[1].setFillColor(Color::White);
	loseMenuu[1].setString("EXIT");
	loseMenuu[1].setCharacterSize(40);
	loseMenuu[1].setFont(font);
	loseMenuu[1].setPosition(Vector2f(width / 2 - 58, hight / (losemenu + 2) * 3.2));
	loseMenuSelected = 0;
}
Menuu2::~Menuu2() {

}
void Menuu2::draw(RenderWindow& window3) {
	for (int i = 0; i < 2; i++) {
		window3.draw(loseMenuu[i]);
	}
}
void Menuu2::moveDown() {
	if (loseMenuSelected + 1 <= losemenu) {
		loseMenuu[loseMenuSelected].setFillColor(Color::White);
		loseMenuSelected++;
		if (loseMenuSelected == 2) {
			loseMenuSelected = 0;
		}
		loseMenuu[loseMenuSelected].setFillColor(Color::Blue);
	}
}
void Menuu2::moveUp() {
	if (loseMenuSelected - 1 >= -1) {
		loseMenuu[loseMenuSelected].setFillColor(Color::White);
		loseMenuSelected--;
		if (loseMenuSelected == -1) {
			loseMenuSelected = 1;
		}
		loseMenuu[loseMenuSelected].setFillColor(Color::Blue);
	}
}
