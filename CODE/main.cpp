#include "pch.h"
#include "Game.h"
#include <iostream>
#include <string>
#include <vector>
#include <chrono>

class Object
{
public:
	sf::CircleShape shape;

	Object(int radius, sf::Color color, int X, int Y)
	{
		
		this->shape.setPosition(X-radius, Y-radius);
		/*this->shape.setOrigin
		(
			this->shape.getLocalBounds().left + this->shape.getLocalBounds().width / 2.f,
			this->shape.getLocalBounds().top + this->shape.getLocalBounds().height / 2.f
		);*/
		this->shape.setFillColor(color);
		this->shape.setRadius(radius);
	};
};

class Universe 
{
public:
	std::vector<Object> obj;
	void Draw(sf::RenderWindow &window)
	{
		for (int i = 0; i < obj.size(); i++)
		{
			window.draw(obj[i].shape);
		};
	}
};

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Lesson 1. kychka-pc.ru");
	
	std::vector<Object> obj;
	Universe uni;
	
	int X = 0, Y = 0, time = 0, size = 0;
	while (window.isOpen())
	{
		sf::Event event;
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		};

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

			auto start = std::chrono::steady_clock::now();
			bool exitCreation = false;
		
			while (exitCreation != true)
			{
				
				if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					auto end = std::chrono::steady_clock::now();
					exitCreation = true;
					int size = (std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count())/10;
					std::cout << "size=" << size << std::endl;
					Object object(size, sf::Color::Yellow, sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
					uni.obj.push_back(object);
				};
				
				auto  now = std::chrono::steady_clock::now();
				int size = (std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count())/10;
				sf::CircleShape shape;
				shape.setRadius(size);
				shape.setPosition(sf::Mouse::getPosition(window).x-size, sf::Mouse::getPosition(window).y-size);
				window.clear();
				uni.Draw(window);
				window.draw(shape);
				window.display();
			};
			
		
		}
		
		
		
		window.clear();
		uni.Draw(window);
		window.display();
	}
	
	
	return 0;
}