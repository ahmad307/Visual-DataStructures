#include <SFML\Graphics.hpp>
#include "BST\BST.cpp"
#include "LinkedList\LinkedList.h"
#include "Queue\Queue.h"
#include "Vector\Vector.h"
#include "HashTable\HashTable.cpp"
#include "HashTable\llist.cpp"

void createMainWindow(sf::RenderWindow &window, sf::Font font);
void createVector();
void createLinkedList();
void createQueue();
void createBst();
void createHashTable();
void Resize(sf::RenderWindow* window, sf::View* view);

//Setting Main window dimensions
static const float View_Width = 1920, View_Height = 1080;

int main()
{	
	//Creating initial welcome window
	sf::RenderWindow window(sf::VideoMode(View_Width, View_Height), "DataStructue Visualizer", sf::Style::Default);

	//Setting main font
	sf::Font font;
	font.loadFromFile("arial_font/arial.ttf");
	
	createMainWindow(window, font);

	return 0;
}

void createMainWindow(sf::RenderWindow &window, sf::Font font)
{
	//Creating main titles
	sf::Text Title_BST;
	Title_BST.setString("1-	Binary Search Tree");
	Title_BST.setStyle(sf::Text::Bold);
	Title_BST.setFont(font);
	Title_BST.setColor(sf::Color::Black);
	Title_BST.setCharacterSize(45);
	Title_BST.setPosition(sf::Vector2f(50, 50));

	sf::Text Title_HashTable;
	Title_HashTable.setString("2-   Hash Tables");
	Title_HashTable.setStyle(sf::Text::Bold);
	Title_HashTable.setFont(font);
	Title_HashTable.setColor(sf::Color::Black);
	Title_HashTable.setCharacterSize(45);
	Title_HashTable.setPosition(sf::Vector2f(50.0f, 150.0f));

	sf::Text Title_LinkedList;
	Title_LinkedList.setString("3-   Linked List");
	Title_LinkedList.setStyle(sf::Text::Bold);
	Title_LinkedList.setFont(font);
	Title_LinkedList.setColor(sf::Color::Black);
	Title_LinkedList.setCharacterSize(45);
	Title_LinkedList.setPosition(sf::Vector2f(50.0f, 250.0f));

	sf::Text Title_Vector;
	Title_Vector.setString("4-   Vector");
	Title_Vector.setStyle(sf::Text::Bold);
	Title_Vector.setFont(font);
	Title_Vector.setColor(sf::Color::Black);
	Title_Vector.setCharacterSize(45);
	Title_Vector.setPosition(sf::Vector2f(50.0f, 350.0f));

	sf::Text Title_Stack;
	Title_Stack.setString("5-   Stack(Temporary Down)");
	Title_Stack.setStyle(sf::Text::Bold);
	Title_Stack.setFont(font);
	Title_Stack.setColor(sf::Color::Black);
	Title_Stack.setCharacterSize(45);
	Title_Stack.setPosition(sf::Vector2f(50.0f, 450.0f));

	sf::Text Title_Queue;
	Title_Queue.setString("6-   Queue");
	Title_Queue.setStyle(sf::Text::Bold);
	Title_Queue.setFont(font);
	Title_Queue.setColor(sf::Color::Black);
	Title_Queue.setCharacterSize(45);
	Title_Queue.setPosition(sf::Vector2f(50.0f, 550.0f));

	//Handling user input
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
				//Switches to BST window
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
				{
					window.setVisible(false);
					createBst();
					window.setVisible(true);
				}
				//Switches to HashTable window
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
				{
					window.setVisible(false);
					createHashTable();
					window.setVisible(true);
				}
				//Switches to LinkedList window
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3))
				{
					window.setVisible(false);
					createLinkedList();
					window.setVisible(true);
				}
				//Switches to Vector window
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))
				{
					window.setVisible(false);
					createVector();
					window.setVisible(true);
				}
				//Switches to Stack window
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5))
				{
					//Temporary not working
					/* 
					window.setVisible(false);

					window.setVisible(true);
					*/
				}
				//Switches to Queue window
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
				{
					window.setVisible(false);
					createQueue();
					window.setVisible(true);
				}

			default:
				break;
			}
		}

		////Drawing main titles
		window.clear(sf::Color::White);
		window.draw(Title_BST);
		window.draw(Title_HashTable);
		window.draw(Title_LinkedList);
		window.draw(Title_Vector);
		window.draw(Title_Stack);
		window.draw(Title_Queue);
		window.display();
	}
}

void createVector()
{
	//Creating Vector window
	int length = 1800, height = 720;
	sf::RenderWindow window(sf::VideoMode(length, height), "Vector", sf::Style::Close | sf::Style::Resize);

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
	sf::RenderWindow window(sf::VideoMode(length, height), "Linked List", sf::Style::Close | sf::Style::Resize);

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
	sf::RenderWindow window(sf::VideoMode(length, height), "Queue", sf::Style::Close | sf::Style::Resize);
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

