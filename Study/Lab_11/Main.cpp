#include <SFML/Graphics.hpp>


#include <iostream>
#include <cmath>
#include <sstream>
#include <windows.h>
using namespace sf;
using namespace std;


class Point
{
public:
	Point(Vector2f one, Vector2f two, Vector2f three);
	~Point();
	Point::Point();
	virtual void draw(RenderWindow &window) = 0;
	virtual float area() = 0;
	virtual void move() = 0;
protected:
	
	Vector2f one, two, three;


};

Point::Point(Vector2f one1, Vector2f two1, Vector2f three1)
{
	this->one = one1;
	this->two = two1;
	this->three = three1;
}

Point::Point()
{
	this->one = Vector2f(0,100);
	this->two = Vector2f(100,100);
	this->three = Vector2f(100,0);
	
}

Point::~Point()
{
}


class Triangle : public Point

{
public:
	Triangle(Vector2f one1, Vector2f two1, Vector2f three1);
	Triangle();
	~Triangle();
	void draw(RenderWindow &window);
	float area();
	void move();

private:
	VertexArray triangle;
	double s;

};

Triangle::Triangle(Vector2f one1, Vector2f two1, Vector2f three1) : Point(one1, two1,  three1)
{

	triangle.setPrimitiveType(Triangles);
	triangle.resize(3);

	triangle[0].position = one;
	triangle[1].position = two;
	triangle[2].position = three;

	// define the color of the triangle's points
	triangle[0].color = sf::Color::Red;
	triangle[1].color = sf::Color::Blue;
	triangle[2].color = sf::Color::Green;
}

Triangle::Triangle() : Point()
{

	triangle.setPrimitiveType(Triangles);
	triangle.resize(3);

	triangle[0].position = one;
	triangle[1].position = two;
	triangle[2].position = three;

	// define the color of the triangle's points
	triangle[0].color = sf::Color::Red;
	triangle[1].color = sf::Color::Blue;
	triangle[2].color = sf::Color::Green;
}

void Triangle::draw(RenderWindow &window) 
{

	triangle[0].position = one;
	triangle[1].position = two;
	triangle[2].position = three;

	window.draw(triangle);

	string str;
	ostringstream ost;
    ost << s;
    str = ost.str();
	
	Font font;
	font.loadFromFile("impact.ttf");
	Text autor(str, font, 20);
	autor.setFillColor(Color::Black);
	autor.setPosition(Vector2f(500, 5));
	window.draw(autor);

	
}

float Triangle::area() 
{

	float st1, st2, st3, p;

	st1 = sqrt((two.x-one.x)*(two.x-one.x) + (two.y-one.y)*(two.y-one.y));
	st2 = sqrt((three.x-one.x)*(three.x-one.x) + (three.y-one.y)*(three.y-one.y));
	st3 = sqrt((two.x-three.x)*(two.x-three.x) + (two.y-three.y)*(two.y-three.y));

	p = (st1 + st2 + st3)/2;


	float a = p - st1, b= p - st2, c= p - st3;
	s = sqrt(p*a*b*c);

	return sqrt(s);
}

void Triangle::move() 
{
	if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A))))
	{
		one.x -= 3;
		two.x -= 3;
		three.x -= 3;
	}

	if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))))
	{
		one.x += 3;
		two.x += 3;
		three.x += 3;
	}

	if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W))))
	{
		one.y -= 3;
		two.y -= 3;
		three.y -= 3;
	}

	if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S))))
	{
		one.y += 3;
		two.y += 3;
		three.y += 3;
	}

}
Triangle
::~Triangle
()
{
}



int main()
{
	HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);

	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

	Triangle triangle(Vector2f(0,0),Vector2f(300,0),Vector2f(300,400));
	triangle.area();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			triangle.move();
		}

		window.clear(Color::White);
		triangle.draw(window);
		window.display();
	}

	return 0;
}