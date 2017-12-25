#pragma once
#include "LList.h"

template <class T>
class HashTable
{
private:
	int hashing(int key);
	void expand(sf::Vector2f);
	void clear();
public:
	HashTable(sf::RenderWindow &, sf::Vector2f);
	~HashTable();
	void draw();
	void remove(int key);
	void insert(pair<int, T>);
private:
	sf::Text Title;
	sf::Font font;
	LList<int>** arr;
	int size, elements;
public:
	sf::RenderWindow* window;
};

