#include "Vector.h"


//Class Constructor
Vector::Vector(sf::RenderWindow &window)
{
	//Setting initial drawing indices
	valueCorX = 80.0f, valueCorY = 300.0f;
	font.loadFromFile("arial_font/arial.ttf");
	elementsNumber = 0;
}

//Draws one index of the vector
void Vector::drawIndex(sf::RenderWindow &window)
{
	sf::RectangleShape indexRec(sf::Vector2f(100.0f, 45.0f));
	sf::RectangleShape valueRec(sf::Vector2f(100.0f, 100.0f));

	//Value rectangle properties
	valueRec.setPosition(valueCorX, valueCorY);
	valueRec.setOutlineColor(sf::Color::Green);
	valueRec.setOutlineThickness(2.0f);

	//Index rectangle properties
	indexRec.setPosition(valueCorX, valueCorY - 48.0f);
	indexRec.setOutlineColor(sf::Color::Red);
	indexRec.setOutlineThickness(2.0f);

	window.draw(indexRec);
	window.draw(valueRec);
}

//Helper function for MergeSort
void Vector::markActive(float x, float y, sf::RenderWindow &window)
{
	//Draws blue bar below the index being sorted
	sf::RectangleShape activeBar(sf::Vector2f(100.0f, 30.0f));
	activeBar.setFillColor(sf::Color::Blue);
	activeBar.setPosition(x, y + 110.0f);
	window.draw(activeBar);
}

//Uses drawIndex to draw the current vector
void Vector::drawVector(sf::RenderWindow &window)
{
	window.clear(sf::Color::White);		//Making background white

	//Drawing title
	sf::Text title;
	title.setFont(font);
	title.setPosition(600.0f, 10.0f);
	title.setCharacterSize(130);
	title.setColor(sf::Color::Black);
	title.setString("Vector");
	window.draw(title);

	//Displaying number of elements in the vector
	sf::Text elements;
	elements.setFont(font);
	elements.setString("Elements Count:  " + std::to_string(elementsNumber));
	elements.setColor(sf::Color::Black);
	elements.setCharacterSize(65);
	elements.setPosition(150.0f, 600.0f);
	window.draw(elements);

	//Checking if the index is being sorted
	for (int i = 0; i < arr.size(); i++)
	{
		if (indicesToSort[i] == 1)
		{
			markActive(valueCorX, valueCorY, window);
		}
		drawIndex(window);

		//i-th index text
		sf::Text index;
		index.setFont(font);
		index.setCharacterSize(30);
		index.setColor(sf::Color::Black);
		index.setString(std::to_string(i));
		index.setStyle(sf::Text::Bold);
		index.setPosition(valueCorX + 35.0f, valueCorY - 45.0f);
		window.draw(index);

		//i-th value's text
		int temp = arr[i], numLength = 0;
		while (temp > 0) //Counts number length to determine its font size
		{
			numLength++;
			temp /= 10;
		}

		sf::Text number;
		number.setFont(font);
		number.setColor(sf::Color::Red);
		number.setString(std::to_string(arr[i]));
		number.setStyle(sf::Text::Bold);
		if (numLength > 2)
		{
			number.setCharacterSize(25);
			number.setPosition(valueCorX + 20.0f, valueCorY + 30.0f);
		}
		else {
			number.setCharacterSize(50);
			number.setPosition(valueCorX + 30.0f, valueCorY + 20.0f);
		}
		window.draw(number);

		valueCorX += 100.0f;
	}

	valueCorX = 100.0f;
	window.display();
}

//Helper function for MergeSort
void Vector::Merge(int l, int m, int r)
{
	//Marking indecies to be sorted in the map
	indicesToSort.clear();
	for (int i = l; i <= r; i++)
		indicesToSort[i] = 1;

	//Copying two halves into new arrays
	int size1 = m - l + 1, size2 = r - m;
	int *arr1 = new int[size1], *arr2 = new int[size2];
	for (int i = 0; i<size1; i++)
		arr1[i] = arr[i + l];
	for (int i = 0; i<size2; i++)
		arr2[i] = arr[i + m + 1];

	//Merging the two arrays
	int j1 = 0, j2 = 0;
	for (int i = l; i <= r; i++)
	{
		if ((arr1[j1] < arr2[j2] && j1<size1) || j2 >= size2)
		{
			arr[i] = arr1[j1];
			j1++;
		}
		else {
			arr[i] = arr2[j2];
			j2++;
		}
		_sleep(500);
	}
}

//Sorts the vector and displays the sorting process
void Vector::MergeSort(int l, int r, sf::RenderWindow &window)
{
	if (r - l <= 0)   return;

	int mid = (l + r) / 2;
	MergeSort(l, mid, window);
	MergeSort(mid + 1, r, window);
	Merge(l, mid, r);

	drawVector(window);
	_sleep(1000);
}

//Prompts the user to enter initial vector elements
void Vector::inputHandler()
{
	//User Input
	std::cout << "Enter the number of elements you want to enter" << std::endl;
	std::cin >> elementsNumber;

	std::cout << "Enter the " << elementsNumber << " elements" << std::endl;
	for (int i = 0; i < elementsNumber; i++)
	{
		int x;	std::cin >> x;

		if (i >= arr.size())
			arr.push_back(x);
		else
			arr[i] = x;
	}
}

//Prompts the user to Insert/Delete
bool Vector::editingHandler(sf::RenderWindow &window)
{
	std::cout << "Enter the desired choice number" << std::endl;
	std::cout << "[1]PushBack  [2]PopBack  [3]InsertAt	 [4]RemoveAt  [5]Sort  [6]Exit" << std::endl;

	indicesToSort.clear();
	int x;	std::cin >> x;

	if (x == 1)  //PushBack Case
	{
		if (elementsNumber == 16)	//Handling max display size
		{
			std::cout << "You've reached max vector size!" << std::endl;
			return true;
		}

		std::cout << "Enter the value to add" << std::endl;
		std::cin >> x;

		if (elementsNumber == arr.size())
			arr.resize(arr.size() * 2);

		if (arr.size() > elementsNumber)
		{
			arr[elementsNumber] = x;
		}
		else {
			arr.push_back(x);
		}
		elementsNumber++;

		drawVector(window);
	}
	else if (x == 2)  //PopBack Case
	{
		if (elementsNumber == 0)
		{
			std::cout << "Empty Vector, Nothing to remove" << "\n\n";
		}
		else {
			arr[elementsNumber - 1] = 0;
			elementsNumber--;
			drawVector(window);
		}
	}
	else if (x == 3)  //InsertAt Case
	{
		std::cout << "Enter the element's value then the index" << std::endl;
		int pos;
		std::cin >> x >> pos;

		if (pos >= arr.size())	//Handling PushBack Case
		{
			if (pos >= 16)
			{
				std::cout << "Max Vector size is 16\n";
				return true;
			}

			if (elementsNumber == arr.size())
				arr.resize(arr.size() * 2);

			if (arr.size() > elementsNumber)
			{
				arr[elementsNumber] = x;
			}
			else {
				arr.push_back(x);
			}
		}
		else if (arr[pos] == 0)
		{
			arr[pos] = x;
		}
		else
			arr.insert(arr.begin() + pos, x);

		elementsNumber++;
		drawVector(window);
	}
	else if (x == 4)  //DeleteAt Case
	{
		std::cout << "Enter the index to remove" << std::endl;
		int pos;	 std::cin >> pos;
		arr.erase(arr.begin() + pos);
		elementsNumber--;
		drawVector(window);
	}
	else if (x == 5)  //Sort Case
	{
		MergeSort(0, elementsNumber - 1, window);
	}
	else if (x == 6)  //Exit
	{
		return false;
	}

	return true;
}

Vector::~Vector()
{
}
