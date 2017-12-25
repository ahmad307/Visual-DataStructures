#include "queue.h"


queue::queue(sf::RenderWindow &window )
{
	std::cout << "Welcome to Queue!" << std::endl;
	this->window = &window;
	float poscircle = 62;
	int posnext = 72;
	size = 0;
	
	text.setFont(font);
	text.setCharacterSize(45);
	text.setString("Queue");
	font.loadFromFile("arial_font/arial.ttf");
	text.setPosition(175, 35);

	side1.setSize(sf::Vector2f(400.0f, 12.0f));
	side1.setFillColor(sf::Color::White);
	side1.setPosition(50, 206);

	side2.setSize(sf::Vector2f(400.0f, 12.0f));
	side2.setFillColor(sf::Color::White);
	side2.setPosition(50, 284);

	inp.setRadius(20);
	inp.setFillColor(sf::Color::Transparent);
	inp.setOutlineThickness(10);
	inp.setOutlineColor(sf::Color::Red);
	inp.setPosition(poscircle, 231);

	handleInput();
}

void queue::handleInput()
{
	int choice;
	string value;
	while (window->isOpen()) {
		sf::Event ev;
		while (window->pollEvent(ev))
		{
			if (ev.type == ev.Closed)
			{
				window->close();
			}
		}

		while (true) {
			cout << "Press [1] to push\nPress [2] to pop\nPress [3] to exit\n";
			cin >> choice;

			if (choice == 1) {
				if (size == 7) {
					cout << "Queue reached the max size!" << endl;
					break;
				}
				else {
					cout << "Please enter the value you want to add: " << endl;
					cin >> value;
					dq.push_back(value);
					size++;
					break;
				}
			}
			else if (choice == 2) {
				dq.pop_front();
				size--;
				break;
			}
			else if (choice == 3) {
				exit;
				return;
			}
			else {
				cout << "Wrong choice!" << endl;
				break;
			}
			break;
		}
		sf::Text val(value, font, 25);
		val.setPosition(12, 235);
		inp.setPosition(62, 231);
	
		window->clear();
		window->draw(text);
		window->draw(side1);
		window->draw(side2);

		for (int i = 0; i < dq.size(); i++) {
			window->draw(inp);
			val.move(sf::Vector2f(60, 0));
			inp.move(sf::Vector2f(60, 0));
			val.setString(dq[i]);
			window->draw(val);
		}
		window->display();
	}
}
