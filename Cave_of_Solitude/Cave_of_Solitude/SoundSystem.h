#ifndef SOUND_H
#define SOUND_H

#include <stdio.h>
#include <SFML/Audio.hpp>

class SoundSystem
{
public:
	SoundSystem()
	{
		if(!trollBuffer.loadFromFile("../Resources/Sound/Troll.wav"));
		{
			printf("SOUND load failed ");
		}
		troll.setBuffer(trollBuffer);
	}

	~SoundSystem()
	{
		//TODO: Remove buffers !
	}

private:
	sf::SoundBuffer trollBuffer;

public:
	sf::Sound troll;
};

#endif