#include <SFML\Graphics.hpp>
#include "AnimatedSprite.h"
#include <iostream>

#include "Render.h"
#include "Game.h"
#include "SoundSystem.h"


int main()
{
	
	srand(time(NULL));

	SoundSystem *soundSystem = new SoundSystem();

	Scene *scene = new Scene();
	Render r(scene);
	Game g(scene,r.GetWindow(), soundSystem);

	sf::Vector2<int> WinPos = r.GetWindow()->getPosition();

	sf::Rect<int> Exit = sf::Rect<int>(WinPos.x+300,WinPos.y+450,200,100);

	bool pressed = false;

	for(;;)
	{
		if(scene->state == START_SCREEN)
		{
			if(Exit.contains(sf::Mouse::getPosition()) == true)
			{
				if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					break;
				}
			}
		}

		scene->Update();
		g.Update();
		r.Update();
	}

	return 0;
}