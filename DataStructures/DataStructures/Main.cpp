#include <SFML\Graphics.hpp>

#include"BST\BST.cpp"
#include"LinkedList\LinkedList.h"
#include"Queue\Queue.h"
#include"Stack\Stack.h"
#include"Vector\Vector.h"
#include"HashTable\HashTable.cpp"

static const float View_Width = 1920, View_Height = 1080;

int length = 1800, height = 720;
//Creating display window
sf::RenderWindow window(sf::VideoMode(length, height), "Visual Data-Structures", sf::Style::Close | sf::Style::Resize);

void createVector();
void createLinkedList();
void createQueue();
void createBst();
void createHashTable();
void Resize(sf::RenderWindow* window, sf::View* view);

int main()
{
	
	sf::RenderWindow window(sf::VideoMode(View_Width, View_Height), "DataStructue Visualizer", sf::Style::Default);
	sf::Font font;
	font.loadFromFile("arial_font/arial.ttf");

	sf::Text text1;
	text1.setString("1- Binary Search Tree");
	text1.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text1.setFont(font);
	text1.setColor(sf::Color::Black);
	text1.setCharacterSize(45);
	text1.setPosition(sf::Vector2f(50, 50));

	sf::Text text2;
	text2.setString("2- Hash Tables");
	text2.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text2.setFont(font);
	text2.setColor(sf::Color::Black);
	text2.setCharacterSize(45);
	text2.setPosition(sf::Vector2f(50.0f, 100.0f));

	sf::Text text3;
	text3.setString("3- Linked List");
	text3.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text3.setFont(font);
	text3.setColor(sf::Color::Black);
	text3.setCharacterSize(45);
	text3.setPosition(sf::Vector2f(50.0f, 150.0f));

	sf::Text text4;
	text4.setString("4- vector");
	text4.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text4.setFont(font);
	text4.setColor(sf::Color::Black);
	text4.setCharacterSize(45);
	text4.setPosition(sf::Vector2f(50.0f, 200.0f));

	sf::Text text5;
	text5.setString("5- stack");
	text5.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text5.setFont(font);
	text5.setColor(sf::Color::Black);
	text5.setCharacterSize(45);
	text5.setPosition(sf::Vector2f(50.0f, 250.0f));

	sf::Text text6;
	text6.setString("6- queue");
	text6.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text6.setFont(font);
	text6.setColor(sf::Color::Black);
	text6.setCharacterSize(45);
	text6.setPosition(sf::Vector2f(50.0f, 300.0f));

	while (window.isOpen())
	{
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			switch (Event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
				{
					window.setVisible(false);
					createBst();
					window.setVisible(true);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
				{
					window.setVisible(false);
					createHashTable();
					window.setVisible(true);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3))
				{
					window.setVisible(false);
					createLinkedList();
					window.setVisible(true);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))
				{
					window.setVisible(false);
					createVector();
					window.setVisible(true);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5))
				{
					//to be done
					window.setVisible(false);
					
					window.setVisible(true);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
				{
					window.setVisible(false);
					createQueue();
					window.setVisible(true);
				}
			default:
				break;
			}
		}
		window.clear(sf::Color::White);
		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);
		window.draw(text5);
		window.draw(text6);
		window.display();
	}
	return 0;
}

void createVector()
{
	int length = 1800, height = 720;
	sf::RenderWindow window(sf::VideoMode(length, height), "Visual Data-Structures", sf::Style::Close | sf::Style::Resize);

	Vector v(window);
	v.inputHandler();
	v.drawVector(window);

	while (window.isOpen())
	{
		//Breaks if user chooses exit
		if (v.editingHandler(window) == false)
			break;
	}
}

void createLinkedList()
{
	int length = 1800, height = 720;
	sf::RenderWindow window(sf::VideoMode(length, height), "Visual Data-Structures", sf::Style::Close | sf::Style::Resize);

	LinkedList LL(window);
	LL.Drawinitial();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (!LL.startWork())
			return;
	}

}

void createQueue()
{
	int length = 1800, height = 720;
	sf::RenderWindow window(sf::VideoMode(length, height), "Visual Data-Structures", sf::Style::Close | sf::Style::Resize);
	queue q(window);
}

void createBst()
{
	sf::RenderWindow BSTwindow(sf::VideoMode(View_Width, View_Height), "BST", sf::Style::Default);
	sf::View BSTview(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(3000.0f, 3000.0f));

	BSTwindow.setView(BSTview);

	BST<int> B(BSTwindow, BSTview);

	cout << "***************Welcome To BST***************\n";
	cout << "Enter [1] to add\n";
	cout << "Enter [2] to traverse\n";
	cout << "Enter [3] to Balance\n";

	while (BSTwindow.isOpen())
	{
		sf::Event Event;
		while (BSTwindow.pollEvent(Event))
		{
			switch (Event.type)
			{
			case sf::Event::Closed:
				BSTwindow.close();
				break;
			case sf::Event::Resized:
				Resize(&BSTwindow, &BSTview);
				break;
			case sf::Event::KeyPressed:
				B.HandleInput();
			default:
				break;
			}
		}
		BSTwindow.clear(sf::Color::White);
		B.draw();
		BSTwindow.display();
	}
}

void createHashTable()
{
	cout << "************Welcome To HashTables*************\n";
	cout << "Enter 1 to add\n";
	cout << "Enter 2 to remove\n";

	sf::RenderWindow hTableWindow(sf::VideoMode(View_Width, View_Height), "Hash Table", sf::Style::Default);
	sf::View hTableView(sf::Vector2f(View_Width / 2, View_Height / 3), sf::Vector2f(View_Width, View_Height));

	hTableWindow.setView(hTableView);

	HashTable<int> H(hTableWindow, sf::Vector2f(10.0f, 10.0f));
	hTableWindow.clear(sf::Color::White);
	hTableWindow.setView(hTableView);
	H.draw();
	hTableWindow.display();

	while (hTableWindow.isOpen())
	{
		sf::Event event;
		while (hTableWindow.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				hTableWindow.close();
				break;
			case sf::Event::Resized:
				Resize(&hTableWindow, &hTableView);
				break;
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
					hTableView.setCenter(sf::Vector2f(hTableView.getCenter().x, hTableView.getCenter().y - 15.0f));
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
					hTableView.setCenter(sf::Vector2f(hTableView.getCenter().x, hTableView.getCenter().y + 15.0f));
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
					hTableView.setCenter(sf::Vector2f(hTableView.getCenter().x - 15.0f, hTableView.getCenter().y));
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
					hTableView.setCenter(sf::Vector2f(hTableView.getCenter().x + 15.0f, hTableView.getCenter().y));
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
				{
					int entries;
					cout << "Ener the number of entries: ";
					cin >> entries;
					for (int i = 0; i < entries; i++)
					{
						int key, val;
						cout << "Enter key: ";
						cin >> key;
						cout << "Enter val: ";
						cin >> val;
						H.insert(make_pair(key, val));
					}
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
				{
					int key;
					cout << "Enter key you want to remove: ";
					cin >> key;
					H.remove(key);
				}
				break;
			default:
				break;
			}
		}
		hTableWindow.clear(sf::Color::White);
		hTableWindow.setView(hTableView);
		H.draw();
		hTableWindow.display();
	}
}

void Resize(sf::RenderWindow* window, sf::View* view)
{
	float aspectRatio = (float)window->getSize().x / (float)window->getSize().y;
	view->setSize(View_Width * aspectRatio, View_Height * aspectRatio);
}

