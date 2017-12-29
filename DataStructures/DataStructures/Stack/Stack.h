#include <iostream>
#include <vector>
#include <stack>
#include <SFML/Graphics.hpp>

using namespace std;



class Fonts{

public:
	sf::Font elementsFont;
	sf::Font titleFont, sizeFont, TopFont;
	Fonts();
	sf::Text Set_titleFont(float windowX);
	sf::Text Set_elementsFont(string value);
	sf::Text Set_sizeFont(int size);
	sf::Text Set_topFont(string n);

};

class StackElement{
public:
	sf::RectangleShape rec;
	sf::Text text;
	string value;
	Fonts f;
	StackElement();
	StackElement(string val, int counter);
};

class  Borders
{
public:
	// borderX .. static height =4 .. static width=192 .. static x=358 y=4956
	sf::RectangleShape borderX;
	sf::RectangleShape borderY1;
	sf::RectangleShape borderY2;
	Borders(int size);
};

class StackFunctions{
public:
	sf::RenderWindow *StackWindow;
	StackFunctions(sf::RenderWindow &wind);
	stack <StackElement> mystack;
	vector<StackElement>v;
	Fonts d;
	sf::Text title = d.Set_titleFont(500);
private:
	float y = 1;
public:
	void push(string n);	
	void pop(); 
	void DrawForStack();
	void Delay();
	void CheckBalance(); 
	void clear();

};


