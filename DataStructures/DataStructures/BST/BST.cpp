#include "BST.h"

template<class T>
node<T>::node(T value, sf::Texture * nodeTexture, float radius)
{
	this->value = value;
	left = right = nullptr;

	Circle.setTexture(nodeTexture);
	Circle.setRadius(radius);
	Circle.setFillColor(sf::Color(43, 62, 80));
	Circle.setOutlineColor(sf::Color::Black);
	Circle.setOutlineThickness(7.0f);

	text.setString(to_string(value));
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Bold);
}

template<class T>
sf::Vector2f node<T>::getposition()
{
	return Circle.getPosition();
}

template<class T>
void node<T>::Reposition(sf::Vector2f newPos)
{
	Circle.setPosition(newPos);
	text.setPosition(sf::Vector2f(newPos.x + Circle.getRadius() * 3 / 4, newPos.y + Circle.getRadius() / 2));
}

template<class T>
node<T>* BST<T>::getParent(node<T>* search)
{
	node<T>* temp = root;
	while (true)
	{
		if (search->value > temp->value)
		{
			if (temp->right == search)
				return temp;
			temp = temp->right;
		}
		else if (search->value < temp->value)
		{
			if (temp->left == search)
				return temp;
			temp = temp->left;
		}
		else
		{
			return nullptr;
		}
	}
}

template<class T>
void BST<T>::drawNodes(node<T>* current)
{
	if (current == nullptr)
		return;
	if (current == light)
	{
		sf::CircleShape circle = current->Circle;
		circle.setFillColor(sf::Color::Yellow);
		view->setCenter(current->Circle.getPosition());
		window->draw(circle);
		window->setView(*view);

		sf::Text text = current->text;
		text.setFont(font);
		text.setFillColor(sf::Color::Red);
		window->draw(text);
	}
	else
	{
		window->draw(current->Circle);
		sf::Text text = current->text;
		text.setFont(font);
		window->draw(text);
	}


	int height = getheight(current) - 1;
	if (current->right != nullptr)
	{
		current->right->Reposition(current->Circle.getPosition() + newpos[height][1]);
		drawArrow(current->Circle.getPosition().x + 2 * current->Circle.getRadius(), current->Circle.getPosition().y + 2 * current->Circle.getRadius(),
			current->right->Circle.getPosition().x, current->right->Circle.getPosition().y);
		drawNodes(current->right);
	}
	if (current->left != nullptr)
	{
		current->left->Reposition(current->Circle.getPosition() + newpos[height][0]);
		drawArrow(current->Circle.getPosition().x, current->Circle.getPosition().y + 2 * current->Circle.getRadius(),
			current->left->Circle.getPosition().x + 2 * current->left->Circle.getRadius(), current->left->Circle.getPosition().y);
		drawNodes(current->left);
	}
}

template<class T>
void BST<T>::drawArrow(float x1, float y1, float x2, float y2)
{
	sf::RectangleShape Line;
	Line.setSize(sf::Vector2f(sqrt(pow(x1 - x2, 2) + pow(y2 - y1, 2)), 10.0f));
	Line.setPosition(sf::Vector2f(x1, y1));
	Line.setFillColor(sf::Color::Black);
	float slope = (y2 - y1) / (x2 - x1);
	float PI = 3.14159265;
	if (slope > 0)
		Line.setRotation((atan(slope) * 180) / PI);
	else if (slope < 0)
		Line.setRotation(-(180 - (atan(slope) * 180) / PI));
	window->draw(Line);
}

template<class T>
int BST<T>::getheight(node<T>* current)
{
	if (current == nullptr)
		return 0;
	return (1 + max(getheight(current->left), getheight(current->right)));
}

template<class T>
void BST<T>::preOrder(node<T>* curr)
{
	if (curr == nullptr)
		return;
	pre_order.setString(pre_order.getString() + " " + to_string(curr->value));
	light = curr;
	waiting(1.0f);
	preOrder(curr->left);
	preOrder(curr->right);
}

template<class T>
void BST<T>::inOrder(node<T>* curr)
{
	if (curr == nullptr)
		return;
	inOrder(curr->left);
	in_order.setString(in_order.getString() + " " + to_string(curr->value));
	light = curr;
	waiting(1.0f);
	inOrder(curr->right);
}

template<class T>
void BST<T>::postOrder(node<T>* curr)
{
	if (curr == nullptr)
		return;
	postOrder(curr->left);
	postOrder(curr->right);
	post_order.setString(post_order.getString() + " " + to_string(curr->value));
	light = curr;
	waiting(1.0f);
}

template<class T>
BST<T>::BST(sf::RenderWindow & window, sf::View & view)
{
	this->window = &window;

	newpos[0][0] = sf::Vector2f(0.0f, 0.0f), newpos[0][1] = sf::Vector2f(0.0f, 0.0f);
	newpos[1][0] = sf::Vector2f(-200.0f, 300.0f), newpos[1][1] = sf::Vector2f(200.0f, 300.0f);
	newpos[2][0] = sf::Vector2f(-300.0f, 250.0f), newpos[2][1] = sf::Vector2f(300.0f, 250.0f);
	newpos[3][0] = sf::Vector2f(-600.0f, 300.0f), newpos[3][1] = sf::Vector2f(600.0f, 300.0f);
	newpos[4][0] = sf::Vector2f(-1200.0f, 400.0f), newpos[4][1] = sf::Vector2f(1200.0f, 400.0f);
	newpos[5][0] = sf::Vector2f(-2400.0f, 800.0f), newpos[5][1] = sf::Vector2f(2400.0f, 800.0f);
	newpos[6][0] = sf::Vector2f(-4800.0f, 1600.0f), newpos[6][1] = sf::Vector2f(4800.0f, 1600.0f);
	newpos[7][0] = sf::Vector2f(-9600.0f, 3200.0f), newpos[7][1] = sf::Vector2f(9600.0f, 3200.0f);

	this->view = &view;

	font.loadFromFile("arial_font/arial.ttf");
	title.setString("Binary Search Tree");
	title.setStyle(sf::Text::Bold | sf::Text::Underlined);
	title.setFont(font);
	title.setColor(sf::Color::Black);
	title.setCharacterSize(45);
	title.setPosition(sf::Vector2f(-150.0f, -100.0f));

	pre_order.setString("preOrder: ");
	pre_order.setStyle(sf::Text::Bold);
	pre_order.setFont(font);
	pre_order.setColor(sf::Color::Black);
	pre_order.setCharacterSize(45);
	pre_order.setPosition(sf::Vector2f(300.0f, -100.0f));

	post_order.setString("postOrder: ");
	post_order.setStyle(sf::Text::Bold);
	post_order.setFont(font);
	post_order.setColor(sf::Color::Black);
	post_order.setCharacterSize(45);
	post_order.setPosition(sf::Vector2f(300.0f, -200.0f));

	in_order.setString("inOrder: ");
	in_order.setStyle(sf::Text::Bold);
	in_order.setFont(font);
	in_order.setColor(sf::Color::Black);
	in_order.setCharacterSize(45);
	in_order.setPosition(sf::Vector2f(300.0f, -300.0f));

	root = light = nullptr;
}

template<class T>
BST<T>::~BST()
{
	clear(root);
}

template<class T>
void BST<T>::insert(T value)
{
	if (root == nullptr)
	{
		root = new node<T>(value, nullptr, 50.0f);
		root->Reposition(sf::Vector2f(0.0f, 0.0f));
		light = root;
		return;
	}
	node<T>* temp = root;
	while (true)
	{
		if (value > temp->value)
		{
			if (temp->right == nullptr)
			{
				temp->right = new node<T>(value, nullptr, 50.0f);
				break;
			}
			temp = temp->right;
		}
		else if (value < temp->value)
		{
			if (temp->left == nullptr)
			{
				temp->left = new node<T>(value, nullptr, 50.0f);
				break;
			}
			temp = temp->left;
		}
		else
		{
			return;
		}
	}
}

template<class T>
void BST<T>::draw()
{
	window->draw(title);
	window->draw(pre_order);
	window->draw(in_order);
	window->draw(post_order);
	drawNodes(root);
}

template<class T>
void BST<T>::HandleInput()
{
	if (root != nullptr && sf::Keyboard::isKeyPressed(sf::Keyboard::A) && light->left != nullptr)
	{
		light = light->left;
	}
	if (root != nullptr && sf::Keyboard::isKeyPressed(sf::Keyboard::D) && light->right != nullptr)
	{
		light = light->right;
	}
	if (root != nullptr && sf::Keyboard::isKeyPressed(sf::Keyboard::W) && getParent(light) != nullptr)
	{
		light = getParent(light);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
	{
		cout << "Enter the number of entries: ";
		int size; cin >> size;
		for (int i = 0; i < size; i++)
		{
			T value;
			cout << "Enter value: ";
			cin >> value;
			insert(value);
		}
		cout << "*****************\n";
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
	{
		traverse();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3))
	{
		Balance();
	}
}

template<class T>
void BST<T>::clear(node<T>* current)
{
	if (current == nullptr)
		return;
	clear(current->right);
	clear(current->left);
	delete current;
}

template<class T>
void BST<T>::traverse()
{
	pre_order.setString("preOrder: ");
	in_order.setString("inOrder: ");
	post_order.setString("postOrder: ");
	preOrder(root);
	light = root;
	waiting(3.0f);

	postOrder(root);
	light = root;
	waiting(3.0f);

	inOrder(root);
	light = root;
}

template<class T>
void BST<T>::Balance()
{
	MyNodes.clear();
	getVector(root);
	clear(root);
	root = nullptr;
	sort(MyNodes.begin(), MyNodes.end());
	DivideAndConquer(0, MyNodes.size() - 1);
}

template<class T>
void BST<T>::getVector(node<T>* current)
{
	if (current == nullptr)
		return;
	MyNodes.push_back(current->value);
	getVector(current->left);
	getVector(current->right);
}

template<class T>
void BST<T>::waiting(float time)
{
	sf::Clock clock;
	while (clock.getElapsedTime().asSeconds() <= time)
	{
		window->clear(sf::Color::White);
		draw();
		window->display();
	}
}

template<class T>
void BST<T>::DivideAndConquer(int start, int End)
{
	if (start > End)
		return;
	int midd = (start + End) / 2;
	insert(MyNodes[midd]);
	DivideAndConquer(start, midd - 1);
	DivideAndConquer(midd + 1, End);
}
