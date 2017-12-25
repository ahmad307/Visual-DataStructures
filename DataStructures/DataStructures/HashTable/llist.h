#pragma once
#include <SFML\Graphics.hpp>

using namespace std;

template <class T>
class Nodee
{
public:
	pair<int, T> value;
	sf::Text text;
	sf::RectangleShape rectangle;
	Nodee<T>* next;
	void setPosition(sf::Vector2f);
	Nodee(pair<int, T>, sf::Vector2f, sf::Texture*);
};

template <class T>
class LList
{
public:
	LList(sf::RenderWindow &, sf::Vector2f);
	~LList();
	bool insert(pair <int, T>);
	void draw();
	T getval(int);
	vector<pair<int, T>> getElements();
	bool removeKey(int key);
private:
	void clear();
	void drawArrow(sf::Vector2f, sf::Vector2f);
public:
	sf::Font font;
private:
	Nodee<T>* head,* tail,* light;
	sf::Vector2f position;
	sf::RenderWindow* window;
	int size;
};
