#include <SFML/Graphics.hpp>

#include <iostream>

using namespace sf;


class Name_autor
{
protected:
	std::string Name;
public:
	Name_autor();
	Name_autor::Name_autor(std::string name);
	void NaText(RenderWindow& w);
};

Name_autor::Name_autor() : Name("Sapozhnyk Dmytro") {}
Name_autor::Name_autor(std::string name) : Name(name) {}

void Name_autor::NaText(RenderWindow& w)
{
	Font font;
	font.loadFromFile("impact.ttf");
	Text autor(Name, font, 20);
	autor.setColor(Color::Black);
	autor.setPosition(Vector2f(500, 5));
	w.draw(autor);
}

class Point
{
public:
	Point();
	~Point();
	Point::Point(float x, float y);

protected:
	float dX;
	float dY;
	bool isMove;

};

Point::Point()
{
	isMove = false;
	dX = 0;
	dY = 0;
}

Point::Point(float x, float y)
{
	isMove = false;
	dX = x;
	dY = y;
}

Point::~Point()
{
}
class myRectangle : public Point , public Name_autor
{
private:
	Name_autor name;
	Image quest_image;
	Texture quest_texture;
	Sprite p;
	
	
public:
	myRectangle();
	myRectangle(float x, float y, std::string name);
	void draw(RenderWindow& w);
};




int main()
{
	RenderWindow window(VideoMode(800, 600), "Lab_8");
	myRectangle tb(100, 100, "Dima");
	
	tb.draw(window);

	return 0;
}


myRectangle::myRectangle()
{
	quest_image.loadFromFile("123.jpg");
	quest_texture.loadFromImage(quest_image);
	p.setTexture(quest_texture);

	p.setPosition(0, 0);
}

myRectangle::myRectangle(float x, float y, std::string name) : Point(x,y), Name_autor(name)
{
	quest_image.loadFromFile("123.jpg");
	quest_texture.loadFromImage(quest_image);
	p.setTexture(quest_texture);
	p.setPosition(x, y);
}

void myRectangle::draw(RenderWindow & window)
{

	while (window.isOpen())
	{
		Vector2i pixelPos = Mouse::getPosition(window);
		Vector2f pos = window.mapPixelToCoords(pixelPos);

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == Event::MouseButtonPressed)
				if (event.key.code == Mouse::Left)
					if (p.getGlobalBounds().contains(pos.x, pos.y))
					{
						std::cout << "isClicked!\n";
						dX = pos.x - p.getPosition().x;
						dY = pos.y - p.getPosition().y;
						isMove = true;
					}
			if (event.type == Event::MouseButtonReleased)
				if (event.key.code == Mouse::Left)
					isMove = false;
			p.setColor(Color::White);
		}
		if (isMove)
		{
			p.setColor(Color::Green);//красим спрайт в зеленый 
			p.setPosition(pos.x - dX, pos.y - dY);//двигаем спрайт по ’

		}

		window.clear(Color::White);
		window.draw(p);
		NaText(window);
		window.display();
		
	}

}
