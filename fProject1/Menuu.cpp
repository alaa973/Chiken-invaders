#include "Menuu.h"
using namespace sf;
Menuu::Menuu(float width, float hight)
{
	if (!font.loadFromFile("prima.ttf")) {}
	pauseMenuu[0].setFont(font);
	pauseMenuu[0].setFont(font);
	pauseMenuu[0].setFont(font);
	pauseMenuu[0].setFillColor(Color::Blue);
	pauseMenuu[0].setString("Resume game");
	pauseMenuu[0].setCharacterSize(20);
	pauseMenuu[0].setFont(font);
	pauseMenuu[0].setPosition(Vector2f(width / 2 - 56, hight / (pausemenu + 1)));

	pauseMenuu[1].setFont(font);
	pauseMenuu[1].setFillColor(Color::White);
	pauseMenuu[1].setString("Quit game");
	pauseMenuu[1].setCharacterSize(20);
	pauseMenuu[1].setFont(font);
	pauseMenuu[1].setPosition(Vector2f(width / 2 - 56, hight / (pausemenu + 2) * 2.5));
	pauseMenuSelected = 0;
}
Menuu::~Menuu() {

}
void Menuu::draw(RenderWindow& window2) {
	for (int i = 0; i < 2; i++) {
		window2.draw(pauseMenuu[i]);
	}
}
void Menuu::moveDown() {
	if (pauseMenuSelected + 1 <= pausemenu) {
		pauseMenuu[pauseMenuSelected].setFillColor(Color::White);
		pauseMenuSelected++;
		if (pauseMenuSelected == 2) {
			pauseMenuSelected = 0;
		}
		pauseMenuu[pauseMenuSelected].setFillColor(Color::Blue);
	}
}
void Menuu::moveUp() {
	if (pauseMenuSelected - 1 >= -1) {
		pauseMenuu[pauseMenuSelected].setFillColor(Color::White);
		pauseMenuSelected--;
		if (pauseMenuSelected == -1) {
			pauseMenuSelected = 1;
		}
		pauseMenuu[pauseMenuSelected].setFillColor(Color::Blue);
	}
}
