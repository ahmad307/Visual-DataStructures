#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include <iostream>
#include <math.h>

using namespace std;

template <class T>
class node
{
private:

public:
	T value;
	sf::Text text;
	sf::CircleShape Circle;
	node<T>* right, *left;
private:

public:
	node(T value, sf::Texture * nodeTexture, float radius);
	sf::Vector2f getposition();
	void Reposition(sf::Vector2f);
};

template <class T>
class BST
{
private:
	node<T>* getParent(node<T>*);
	void drawNodes(node<T>*);
	void drawArrow(float x1, float y1, float x2, float y2);
	int getheight(node<T>*);
	void preOrder(node<T>*);
	void inOrder(node<T>*);
	void postOrder(node<T>*);
	void getVector(node<T>*);
	void waiting(float);
	void DivideAndConquer(int, int);
public:
	BST(sf::RenderWindow &, sf::View &);
	~BST();
	void insert(T value);
	void draw();
	void HandleInput();
	void clear(node<T>* current);
	void traverse();
	void Balance();
private:
	sf::Vector2f newpos[8][2];
	sf::Text title, post_order, in_order, pre_order;
	sf::RenderWindow* window;
	sf::View* view;
	node<T>* light;
	node<T>* root;
	sf::Font font;
	vector<T> MyNodes;
public:
};

