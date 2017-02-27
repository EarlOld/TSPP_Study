#include <SFML/Graphics.hpp>

#include <iostream>

using namespace sf;

int main()
{


	RenderWindow window(VideoMode(640, 480), "Lab_8");
	

	Image quest_image;
	quest_image.loadFromFile("123.jpg");
	
	Texture quest_texture;
	quest_texture.loadFromImage(quest_image);
	Sprite p;

	p.setTexture(quest_texture);
		
	bool isMove = false;
	float dX = 0;
	float dY = 0;
	while (window.isOpen())
	{
		Vector2i pixelPos = Mouse::getPosition(window);
		Vector2f pos = window.mapPixelToCoords(pixelPos);
		std::cout << pixelPos.x << "\n";
		std::cout << pos.x << "\n";

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
		if (isMove) {//если можем двигать
			p.setColor(Color::Green);//красим спрайт в зеленый 
			p.setPosition(pos.x - dX, pos.y - dY);//двигаем спрайт по Х
			
		}

	window.clear(Color::White);
	window.draw(p);
	window.display();
}

return 0;
}