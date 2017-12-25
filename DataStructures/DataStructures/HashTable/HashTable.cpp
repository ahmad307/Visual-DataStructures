#include "HashTable.h"

template<class T>
int HashTable<T>::hashing(int key)
{
	return (key % size);
}

template<class T>
void HashTable<T>::expand(sf::Vector2f position)
{
	LList<T>** arr2;
	arr2 = new LList<T>*[size * 2];
	for (int i = 0; i < size * 2; i++)
	{
		arr2[i] = new LList<T>(*window, position + sf::Vector2f(0.0f, i * 114.0f));
	}
	for (int i = 0; i < size; i++)
	{
		vector<pair<int, T>> vec;
		vec = arr[i]->getElements();
		for(int j = 0 ; j < vec.size(); j++)
			arr2[vec[j].first % (size * 2)]->insert(vec[j]);
	}
	clear();
	arr = arr2;
	size *= 2;
}

template<class T>
void HashTable<T>::clear()
{
	for (int i = 0; i < size; i++)
	{
		delete arr[i];
	}
	delete[] arr;
}

template <class T>
HashTable<T>::HashTable(sf::RenderWindow & window, sf::Vector2f position)
{
	size = 7;
	elements = 0;
	arr = new LList<T>*[size];
	this->window = &window;


	for (int i = 0; i < size; i++)
	{
		arr[i] = new LList<T>(window, position + sf::Vector2f(0.0f, i * 114.0f));
	}
	font = arr[0]->font;
	Title.setString("Hash Table");
	Title.setFillColor(sf::Color::Black);
	Title.setStyle(sf::Text::Bold | sf::Text::Underlined);
	Title.setPosition(position + sf::Vector2f(400.0f, -150.0f));
	Title.setFont(font);
	Title.setCharacterSize(60);
}

template <class T>
HashTable<T>::~HashTable()
{
	clear();
}

template<class T>
void HashTable<T>::draw()
{
	if(Title.getString() == "Hash Table")
		window->draw(Title);
	for (int i = 0; i < size; i++)
	{
		arr[i]->draw();
	}
}

template<class T>
void HashTable<T>::remove(int key)
{
	if (arr[hashing(key)]->removeKey(key))
		elements--;
}

template<class T>
void HashTable<T>::insert(pair<int, T> value)
{
	if (arr[hashing(value.first)]->insert(value))
	{
		elements++;
		if ((double)elements / size >= 0.7)
		{
			expand(sf::Vector2f(10.0f, 10.0f));
		}
	}
}
