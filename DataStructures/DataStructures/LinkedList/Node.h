#pragma once
#include<SFML\Graphics.hpp>
class Node
{
public:
 
    int n;
    sf::RectangleShape rect;
    sf::RectangleShape Line;
    sf::RectangleShape a;
    sf::RectangleShape b;
    sf::RectangleShape separator;
    sf::Text text;
 
    Node(int pos,int val);
    ~Node();
};