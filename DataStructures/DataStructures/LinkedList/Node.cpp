#include "Node.h"
using namespace std;
 
 
Node::Node(int x,int y)
{
    n = y;
 
    rect.setSize(sf::Vector2f(100, 50));
    rect.setPosition(x*(150)+5, 250);
    rect.setFillColor(sf::Color(78, 93, 108));
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(3);
 
    separator.setSize(sf::Vector2f(5, 50));
    separator.setPosition(x*(150) + 60, 250);
    separator.setFillColor(sf::Color::Black);
 
 
    Line.setSize(sf::Vector2f(60, 5));
    Line.setPosition(x*(150) + 90, 275);
 
    a.setSize(sf::Vector2f(15, 5));
    a.setPosition((x + 1)*(150), 280);
    a.rotate(225);
 
    b.setSize(sf::Vector2f(14, 5));
    b.setPosition((x + 1)*(150), 280);
    b.rotate(135);
 
    sf::Font f;
    f.loadFromFile("arial_font/arial.ttf");
    text.setFont(f);
    text.setString(to_string(y));
    text.setCharacterSize(15);
    text.setStyle(sf::Text::Bold);
    text.setPosition(sf::Vector2f(x * 150 + 10, 260));
}
 
 
Node::~Node()
{
}