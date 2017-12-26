#include"Stack.h"

using namespace std;

	Fonts::Fonts(){
		elementsFont.loadFromFile("arial_font/arial.ttf");
		titleFont.loadFromFile("fonts/monkey_hat_DEMO.otf");
		sizeFont.loadFromFile("fonts/Fullamak.ttf");	
	}

	sf::Text Fonts::Set_titleFont(float windowX){
		sf::Text title;
		title.setString("Stack Visualizer");
		title.setFont(titleFont);
		title.setCharacterSize(60);
		title.setPosition(sf::Vector2f(20, 2));
		title.setFillColor(sf::Color(89, 238, 121));
		return title;
	}

	sf::Text Fonts::Set_elementsFont(string value){
		sf::Text text;
		text.setCharacterSize(28);
		text.setStyle(sf::Text::Bold);
		text.setFillColor(sf::Color::Black);
		text.setFont(elementsFont);
		text.setString(value);
		return text;
	}

	sf::Text Fonts:: Set_sizeFont(int size){
		sf::Text sizze;
		sizze.setString("#Size = " + to_string(size));
		sizze.setFont(sizeFont);
		sizze.setCharacterSize(45);
		sizze.setPosition(sf::Vector2f(70,160));
		sizze.setFillColor(sf::Color(255, 0, 128));
		return sizze;
	}
	
	sf::Text Fonts:: Set_topFont(string n){
		sf::Text sizza;
		sizza.setString("#Top : " + n);
		sizza.setFont(sizeFont);
		sizza.setCharacterSize(45);
		sizza.setPosition(sf::Vector2f(70, 260));
		sizza.setFillColor(sf::Color(227, 0, 255));
		return sizza;
	}


	StackElement::StackElement(string val, int counter)
	{
		value = val;
		rec.setSize(sf::Vector2f(270.5f, 40.0f));
		rec.setOutlineColor(sf::Color(0, 255, 4));
		rec.setOutlineThickness(4);
		rec.setFillColor(sf::Color::Transparent);
		rec.setPosition(805.0f, (655- (50 * counter)));
		//int p = 440 - (value.size() * 2);
		
		text = f.Set_elementsFont(value);
		text.setPosition(sf::Vector2f(900, rec.getPosition().y + 1.0f));

	}

	Borders::Borders(int size){
		borderY1.setSize(sf::Vector2f(10.0f, 58 + (44.0f*size)));
		borderY1.setPosition(788.0f, 706.0f - (58 + (44.0f*size)));
		borderY1.setFillColor(sf::Color(102, 102, 102));


		borderY2.setSize(sf::Vector2f(10.0f, 58 + (44.0f*size)));
		borderY2.setPosition(1082.0f, 706.0f - (58 + (44.0f* size)));
		borderY2.setFillColor(sf::Color(102, 102, 102));

		borderX.setSize(sf::Vector2f(304.0f, 10.0f));
		borderX.setFillColor(sf::Color(102, 102, 102));
		borderX.setPosition(788.0f, 702.0f);
	}




	StackFunctions:: StackFunctions(sf::RenderWindow &wind){
		StackWindow = &wind;
	}
	
	
	void StackFunctions::push(string n){
		
		StackElement s(n, v.size());
		v.push_back(s);
		mystack.push(s);

		StackElement pushed(n, v.size() + 3);

		StackWindow->clear(sf::Color(250, 251, 244));
		StackWindow->draw(title);
		StackWindow->draw(d.Set_sizeFont(v.size()));
		StackWindow->draw(d.Set_topFont(mystack.top().value));
		StackWindow->draw(Borders(v.size()).borderY1);
		StackWindow->draw(Borders(v.size()).borderY2);
		StackWindow->draw(Borders(v.size()).borderX);
		StackWindow->draw(pushed.rec);
		StackWindow->draw(pushed.text);
		StackWindow->display();

		while (pushed.rec.getPosition().y < mystack.top().rec.getPosition().y){

			StackWindow->clear(sf::Color(250, 251, 244));
			StackWindow->draw(title);
			StackWindow->draw(d.Set_topFont(mystack.top().value));
			StackWindow->draw(d.Set_sizeFont(v.size()));
			StackWindow->draw(Borders(v.size()).borderY1);
			StackWindow->draw(Borders(v.size()).borderY2);
			StackWindow->draw(Borders(v.size()).borderX);

			for (int i = 0; i < v.size() - 1; i++){

				StackElement b = v[i];
				StackWindow->draw(b.rec);
				StackWindow->draw(b.text);
			}
			float yy = mystack.top().rec.getPosition().y - (pushed.rec.getPosition().y);
			pushed.rec.move(0, min(y, yy));
			pushed.text.move(0, min(y, yy));

			if (mystack.top().rec.getPosition().y - pushed.rec.getPosition().y < 0)
				pushed.rec.move(0, mystack.top().rec.getPosition().y - pushed.rec.getPosition().y);

			StackWindow->draw(pushed.rec);
			StackWindow->draw(pushed.text);
			StackWindow->display();

		}
		if (pushed.rec.getPosition().y == mystack.top().rec.getPosition().y){
			StackWindow->clear(sf::Color(250, 251, 244));
			StackWindow->draw(title);
			StackWindow->draw(d.Set_topFont(mystack.top().value));
			StackWindow->draw(d.Set_sizeFont(v.size()));
			StackWindow->draw(Borders(v.size()).borderY1);
			StackWindow->draw(Borders(v.size()).borderY2);
			StackWindow->draw(Borders(v.size()).borderX);

			for (int i = 0; i < v.size(); i++){
				StackElement b = v[i];
				StackWindow->draw(b.rec);
				StackWindow->draw(b.text);		
			}
			StackWindow->display();
		}
	}
	void StackFunctions::pop(){
		if (mystack.size() > 0)
			mystack.pop();
		if (v.size() > 0)
			v.pop_back();

		StackWindow->clear(sf::Color(250, 251, 244));
		StackWindow->draw(title);
		if (mystack.size() > 0)
		StackWindow->draw(d.Set_topFont(mystack.top().value));
		StackWindow->draw(d.Set_sizeFont(v.size()));
		StackWindow->draw(Borders(v.size()).borderY1);
		StackWindow->draw(Borders(v.size()).borderY2);
		StackWindow->draw(Borders(v.size()).borderX);

		for (int i = 0; i < v.size(); i++){
			StackElement b(v[i].value, i);
			StackWindow->draw(b.rec);
			StackWindow->draw(b.text);
		}

		StackWindow->display();
	}
	void StackFunctions::DrawForStack(){
		Fonts d;
		sf::Text title = d.Set_titleFont(StackWindow->getPosition().x);
		
		sf::Text size = d.Set_sizeFont(v.size());
		StackWindow->clear(sf::Color(250, 251, 244));
		//StackWindow->clear(sf::Color(33, 2, 56)); // mov 8ame2

		StackWindow->draw(title);
		StackWindow->draw(size);
		StackWindow->draw(Borders(v.size()).borderY1);
		StackWindow->draw(Borders(v.size()).borderY2);
		StackWindow->draw(Borders(v.size()).borderX);
		StackWindow->display();
	}
	void StackFunctions::Delay(){

		for (int i = 0; i < 100000000; i++);

}

	void StackFunctions::CheckBalance(){
		
		cout << "Enter String \n";
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != '(' && s[i] != ')')
			{
				cout << "Please Enter a Valid String\n";
				return;
			}
		}

		for (int i = 0; i<s.size(); i++){
			if (s[i] == '('){
				push("(");
				Delay();
			}
			else if (s[i] == ')'){
				if (!mystack.empty() && mystack.top().value == "("){
					Delay();
					pop();
					Delay();
				}

				else{
					push(")");
					Delay();
				}
			}
		}
		if (mystack.size()>0)
			cout << "NOT BALANCED\n";
		else
			cout << "BALANCED\n";
	}

	void StackFunctions::clear()
	{
		while (!mystack.empty())
		{
			pop();
		}
	}

	


