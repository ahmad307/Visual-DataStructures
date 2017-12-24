#pragma once
#include<vector>
#include "Node.h"
#include<SFML\Graphics.hpp>
 
using namespace std;
class LinkedList
{
    sf::Font f;
    vector<Node> list;
    sf::RectangleShape nullRect;
    sf::Text Textnull;
    sf::Text TextHead;
    sf::Text title;
    sf::RectangleShape head;
    sf::RectangleShape heada;
    sf::RectangleShape headb;
    sf::RenderWindow *window;
    void Insert();
    void Append();
    void Delete();
    void drawList();
 
public:
    LinkedList(sf::RenderWindow& window);
    void Drawinitial();
    bool startWork();
    ~LinkedList();
};