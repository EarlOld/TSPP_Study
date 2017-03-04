#include <SFML/Graphics.hpp>


#include <iostream>

using namespace sf;

class Point
{
public:
	Point();
	~Point();
	Point::Point(float x, float y);

public:
	VertexArray triangle;
	Vector2f one, two, three;


};

Point::Point()
{
	triangle.setPrimitiveType(Triangles);
	triangle.resize(3);

	triangle[0].position = sf::Vector2f(10, 10);
	triangle[1].position = sf::Vector2f(100, 10);
	triangle[2].position = sf::Vector2f(100, 100);

	// define the color of the triangle's points
	triangle[0].color = sf::Color::Red;
	triangle[1].color = sf::Color::Blue;
	triangle[2].color = sf::Color::Green;
}

Point::Point(float x, float y)
{

	
}

Point::~Point()
{
}


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

	Point point;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(Color::White);
		window.draw(point.triangle);
		window.display();
	}

	return 0;
}