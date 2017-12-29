#include "LList.h"

template<class T>
Nodee<T>::Nodee(pair<int, T> value, sf::Vector2f size, sf::Texture* NodeeTexture)
{
	this->value = value;

	rectangle.setSize(size);
	rectangle.setFillColor(sf::Color::White);
	rectangle.setTexture(NodeeTexture);
	rectangle.setOutlineColor(sf::Color::Black);
	rectangle.setOutlineThickness(7.0f);

	text.setFillColor(sf::Color::Black);
	text.setStyle(sf::Text::Bold);

	next = nullptr;
}

template<class T>
void Nodee<T>::setPosition(sf::Vector2f position)
{
	rectangle.setPosition(position);
	text.setPosition(sf::Vector2f(position.x + rectangle.getSize().x / 6, position.y + rectangle.getSize().y / 3));
}

template <class T>
LList<T>::LList(sf::RenderWindow & window, sf::Vector2f position)
{
	head = tail = light = nullptr;
	this->window = &window;
	this->position = position;
	font.loadFromFile("arial_font/arial.ttf");
	size = 0;
}

template<class T>
bool LList<T>::insert(pair<int, T> value)
{
	if (head == nullptr)
	{
		head = tail = new Nodee<T>(value, sf::Vector2f(100.0f, 100.0f), nullptr);
		size++;
	}
	else
	{
		Nodee<T>* temp = head;
		while (temp != nullptr)
		{
			if (temp->value.first == value.first)
			{
				temp->value = value;
				return false;
			 }
			temp = temp->next;
		}
		tail->next = new Nodee<T>(value, sf::Vector2f(100.0f, 100.0f), nullptr);
		tail = tail->next;
		size++;
	}
	return true;
}

template<class T>
bool LList<T>::removeKey(int key)
{
	if (head != nullptr && head->value.first == key)
	{
		Nodee<T>* temp = head;
		head = head->next;
		size--;
		delete temp;
		return true;
	}
	Nodee<T>* temp = head;
	while (temp != nullptr)
	{
		if (temp->next == nullptr)
			return false;
		if (temp->next->value.first == key)
		{
			Nodee<T>* temp2 = temp->next;
			temp->next = temp->next->next;
			delete temp2;
			size--;
			return true;
		}
		temp = temp->next;
	}
	return false;
}

template<class T>
void LList<T>::draw()
{
	Nodee<T>* temp = head;
	sf::Vector2f newPosition = position;
	while (temp != nullptr)
	{
		temp->setPosition(newPosition);
		window->draw(temp->rectangle);

		drawArrow(sf::Vector2f(temp->rectangle.getPosition().x + temp->rectangle.getSize().x,
			temp->rectangle.getPosition().y + temp->rectangle.getSize().y / 2),
			sf::Vector2f(temp->rectangle.getPosition().x + temp->rectangle.getSize().x + 40.0f,
				temp->rectangle.getPosition().y + temp->rectangle.getSize().y / 2));
		newPosition = sf::Vector2f(temp->rectangle.getPosition().x + temp->rectangle.getSize().x + 40.0f,
			temp->rectangle.getPosition().y);

		temp->text.setString(to_string(temp->value.first) + "," + to_string(temp->value.second));
		temp->text.setFont(font);
		window->draw(temp->text);

		temp = temp->next;
	}

	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(100.0f, 100.0f));
	rect.setPosition(newPosition);
	rect.setFillColor(sf::Color::Red);
	rect.setOutlineColor(sf::Color::Black);
	rect.setOutlineThickness(7.0f);

	sf::Text text;
	text.setStyle(sf::Text::Bold);
	text.setPosition(rect.getPosition().x + rect.getSize().x / 6, rect.getPosition().y + rect.getSize().y / 3);
	text.setColor(sf::Color::Black);
	text.setFont(font);
	text.setString("NULL");

	window->draw(rect), window->draw(text);
}


template<class T>
void LList<T>::drawArrow(sf::Vector2f first, sf::Vector2f second)
{
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(sqrt(pow(first.x - second.x, 2) + pow(first.y - second.y, 2)), 20.0f));
	rectangle.setPosition(first);
	rectangle.setFillColor(sf::Color::Black);
	window->draw(rectangle);
}

template<class T>
T LList<T>::getval(int key)
{
	Nodee<T>* temp = head;
	while (temp != nullptr)
	{
		if (key == temp->value.first)
		{
			return temp->value.second;
		}
	}
	return T(0);
}

template<class T>
vector<pair<int, T>> LList<T>::getElements()
{
	vector<pair<int, T>> vec;
		Nodee<T>* temp = head;
	while (temp != nullptr)
	{
		vec.push_back(temp->value);
		temp = temp->next;
	}
	return vec;
}

template<class T>
void LList<T>::clear()
{
	while (head != nullptr)
	{
		Nodee<T>* temp = head;
		head = head->next;
		delete temp;
	}
}

template <class T>
LList<T>::~LList()
{
	clear();
}