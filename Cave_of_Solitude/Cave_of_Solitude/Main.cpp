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

	bool pressed = false;

	for(;;)
	{
		if(scene->state != START_SCREEN)
		{
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				pressed = true;
			}
		}
		if(scene->state == START_SCREEN)
		{
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				if(pressed == false)
				break;
			}
		}
		if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			pressed = false;
		}

		scene->Update();
		g.Update();
		r.Update();
	}

	return 0;
}