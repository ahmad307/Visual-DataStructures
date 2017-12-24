#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>

class Vector
{
	float valueCorX, valueCorY;
	int n;
	std::map<int, int> myMap;
	sf::Font font;
	std::vector<int> arr;
public:
	Vector(sf::RenderWindow &window, sf::Font chosenFont);

	void drawIndex(sf::RenderWindow &window);
	void markActive(float x, float y, sf::RenderWindow &window);
	void drawVector(sf::RenderWindow &window);
	void Merge(int l, int m, int r);
	void MergeSort(int l, int r, sf::RenderWindow &window);
	void inputHandler();
	bool editingHandler(sf::RenderWindow &window);

	~Vector();
};
