#include <SFML/Graphics.hpp>


#include <iostream>

using namespace sf;

class Point
{
public:
	Point();
	~Point();
	Point::Point(float x, float y);

protected:
	VertexArray triangle(sf::Triangles, 3);
	Vector2f one, two, three;


};

Point::Point()
{
	isMove = false;
	dX = 0;
	dY = 0;
}

Point::Point(float x, float y)
{
	triangle[0].position = sf::Vector2f(10, 10);
	triangle[1].position = sf::Vector2f(100, 10);
	triangle[2].position = sf::Vector2f(100, 100);

	// define the color of the triangle's points
	triangle[0].color = sf::Color::Red;
	triangle[1].color = sf::Color::Blue;
	triangle[2].color = sf::Color::Green;
}

Point::~Point()
{
}


int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}