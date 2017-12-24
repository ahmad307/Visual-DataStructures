#pragma once
#include<SFML\Graphics.hpp>
#include<deque>
#include <iostream>
using namespace std;
class queue
{
private:
	deque<string>dq;
	sf::RenderWindow* window;
	sf::Font font;
	sf::RectangleShape side1, side2;
	sf::Text text;
	sf::CircleShape inp;
	int size;
public:
	queue(sf::RenderWindow&);
	void handleInput();
};

