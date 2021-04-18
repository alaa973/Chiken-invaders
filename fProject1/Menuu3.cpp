#include  "Menuu3.h"
using namespace sf;
Menuu3::Menuu3(float width, float hight)
{
	if (!font.loadFromFile("prima.ttf")) {}
	winMenuu[0].setFont(font);
	winMenuu[0].setFont(font);
	winMenuu[0].setFont(font);
	winMenuu[0].setFillColor(Color::Blue);
	winMenuu[0].setString("NEXT LEVEL");
	winMenuu[0].setCharacterSize(40);
	winMenuu[0].setFont(font);
	winMenuu[0].setPosition(Vector2f(width / 2 - 60, hight / (winmenu + 1) * 2.2));

	winMenuu[1].setFont(font);
	winMenuu[1].setFillColor(Color::White);
	winMenuu[1].setString("EXIT");
	winMenuu[1].setCharacterSize(40);
	winMenuu[1].setFont(font);
	winMenuu[1].setPosition(Vector2f(width / 2 - 5, hight / (winmenu + 2) * 3.2));
	winMenuSelected = 0;
}
Menuu3::~Menuu3() {

}
void Menuu3::draw(RenderWindow& window4) {
	for (int i = 0; i < 2; i++) {
		window4.draw(winMenuu[i]);
	}
}
void Menuu3::moveDown() {
	if (winMenuSelected + 1 <= winmenu) {
		winMenuu[winMenuSelected].setFillColor(Color::White);
		winMenuSelected++;
		if (winMenuSelected == 2) {
			winMenuSelected = 0;
		}
		winMenuu[winMenuSelected].setFillColor(Color::Blue);
	}
}
void Menuu3::moveUp() {
	if (winMenuSelected - 1 >= -1) {
		winMenuu[winMenuSelected].setFillColor(Color::White);
		winMenuSelected--;
		if (winMenuSelected == -1) {
			winMenuSelected = 1;
		}
		winMenuu[winMenuSelected].setFillColor(Color::Blue);
	}
}
