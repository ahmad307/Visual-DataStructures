#include "LinkedList.h"
#include<iostream>
 
using namespace std;
 
 
void LinkedList::Insert()
{
    int index, val;
    do
    {
        cout << "Enter the place you want to insert in and then the value\n";
        cin >> index >> val;
    } while (index<0 || index > list.size());
    Node temp(list.size(), val);
    list.insert(list.begin() + index, temp);
}
 
void LinkedList::Append()
{
    cout << "Enter the node value: ";
    int n;
    cin >> n;
 
    Node N(list.size(), n);
    list.push_back(N);
}
 
void LinkedList::Delete()
{
    int index;
    do 
    {
        cout << "Enter index to be removed\n";
        cin >> index;
    } while (index<0 || index > list.size() - 1);
 
    list.erase(list.begin() + index);
}
 
void LinkedList::drawList()
{
    window->clear(sf::Color(43, 62, 80));
    for (int i = 0; i < list.size(); i++)
    {
        Node temp(i, list[i].n);
        list[i] = temp;
        window->draw(list[i].rect);
        window->draw(list[i].Line);
        list[i].text.setFont(f);
        window->draw(list[i].text);
        window->draw(list[i].a);
        window->draw(list[i].b);
        window->draw(list[i].separator);
    }
    nullRect.setPosition(list.size()*(150) + 5, 250);
    Textnull.setPosition(list.size() * 150 + 10, 260);
    window->draw(nullRect);
    window->draw(Textnull);
    window->draw(title);
    window->draw(head);
    window->draw(heada);
    window->draw(headb);
    window->draw(TextHead);
    window->display();
}
 
LinkedList::LinkedList(sf::RenderWindow& Window)
{
    f.loadFromFile("arial_font/arial.ttf");
    window = &Window;
 
    nullRect.setFillColor(sf::Color(217, 83, 79));
    nullRect.setSize(sf::Vector2f(50, 50));
    nullRect.setPosition(list.size()*(150), 250);
 
    Textnull.setString("NULL");
    Textnull.setFont(f);
    Textnull.setCharacterSize(15);
    Textnull.setStyle(sf::Text::Bold);
    Textnull.setPosition(list.size() * 150 + 10, 260);
 
    TextHead.setString("Head");
    TextHead.setFont(f);
    TextHead.setCharacterSize(25);
    TextHead.setFillColor(sf::Color::White);
    TextHead.setPosition(sf::Vector2f(0, 160));
    TextHead.setStyle(sf::Text::Bold);
 
    title.setString("Linked List");
    title.setFont(f);
    title.setCharacterSize(40);
    title.setPosition(sf::Vector2f((window->getSize().x / 2) - 60, 2));
    title.setStyle(sf::Text::Bold | sf::Text::Underlined);
   
    head.setSize(sf::Vector2f(5, 50));
    head.setPosition(15, 190);
 
    heada.setSize(sf::Vector2f(15, 5));
    heada.setPosition(15, 240);
    heada.rotate(-135);
 
    headb.setSize(sf::Vector2f(20, 5));
    headb.setPosition(15, 240);
    headb.rotate(-45);
 
 
}
 
void LinkedList::Drawinitial()
{
    window->clear(sf::Color(43, 62, 80));
 
    window->draw(nullRect);
    window->draw(Textnull);
    window->draw(title);
    window->draw(head);
    window->draw(heada);
    window->draw(headb);
    window->draw(TextHead);
 
    window->display();
}

bool LinkedList::startWork()
{
    cout << endl;
 
    cout << "Press [1] To add a new node\nPress [2] To remove a node\nPress [3] To insert value\nPress [4] To exit\n";
    int choice;
    cin >> choice;
 
    if (choice == 1)
    {
        Append();
    }
    else if (choice == 2)
    {
        Delete();
    }
    else if (choice == 3)
    {
        Insert();
    }
    else if (choice == 4)
    {
        return false;
    }
 
    drawList();
        return true;
 
}
 
 
LinkedList::~LinkedList()
{
}