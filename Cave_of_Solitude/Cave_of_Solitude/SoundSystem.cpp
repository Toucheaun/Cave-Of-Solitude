#include <iostream>
#include "SoundSystem.h"

SoundSystem::SoundSystem()
{
	coinBuffer.loadFromFile("../Resources/Sound/Coin.wav");

	if(!coinBuffer.loadFromFile("../Resources/Sound/Coin.wav"))
	{
		printf("SOUND load failed ");
	}
	coin.setBuffer(coinBuffer);
}

SoundSystem::~SoundSystem()
{
	// Remove Buffers
}