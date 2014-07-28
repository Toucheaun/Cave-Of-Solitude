#ifndef SOUND_H
#define SOUND_H

#include <stdio.h>
#include <SFML/Audio.hpp>

class SoundSystem
{
public:
	SoundSystem();
	~SoundSystem();

private:
	sf::SoundBuffer coinBuffer;
	sf::SoundBuffer foodBuffer;
	sf::SoundBuffer swordBuffer;

	sf::SoundBuffer playerStepBuffer;
	sf::SoundBuffer playerGetHitBuffer;
	sf::SoundBuffer playerDeathBuffer;

	sf::SoundBuffer goblinBuffer;
	sf::SoundBuffer goblinHitBuffer;
	sf::SoundBuffer goblinGetHitBuffer;
	sf::SoundBuffer goblinDeathBuffer;

	sf::SoundBuffer zombieBuffer;
	sf::SoundBuffer zombieHitBuffer;
	sf::SoundBuffer zombieGetHitBuffer;
	sf::SoundBuffer zombieDeathBuffer;

	sf::SoundBuffer orcBuffer;
	sf::SoundBuffer orcHitBuffer;
	sf::SoundBuffer orcGetHitBuffer;
	sf::SoundBuffer orcDeathBuffer;

	sf::SoundBuffer skeletonBuffer;
	sf::SoundBuffer skeletonHitBuffer;
	sf::SoundBuffer skeletonGetHitBuffer;
	sf::SoundBuffer skeletonDeathBuffer;

	sf::SoundBuffer trollBuffer;
	sf::SoundBuffer trollHitBuffer;
	sf::SoundBuffer trollGetHitBuffer;
	sf::SoundBuffer trollDeathBuffer;

	sf::SoundBuffer wraithBuffer;
	sf::SoundBuffer wraithHitBuffer;
	sf::SoundBuffer wraithGetHitBuffer;
	sf::SoundBuffer wraithDeathBuffer;

public:
	sf::Music menu;
	sf::Music inGame;

	sf::Sound coin;
	sf::Sound food;
	sf::Sound sword;

	sf::Sound playerStep;
	sf::Sound playerGetHit;
	sf::Sound playerDeath;

	sf::Sound goblin;
	sf::Sound goblinHit;
	sf::Sound goblinGetHit;
	sf::Sound goblinDeath;

	sf::Sound zombie;
	sf::Sound zombieHit;
	sf::Sound zombieGetHit;
	sf::Sound zombieDeath;

	sf::Sound orc;
	sf::Sound orcHit;
	sf::Sound orcGetHit;
	sf::Sound orcDeath;

	sf::Sound skeleton;
	sf::Sound skeletonHit;
	sf::Sound skeletonGetHit;
	sf::Sound skeletonDeath;

	sf::Sound troll;
	sf::Sound trollHit;
	sf::Sound trollGetHit;
	sf::Sound trollDeath;

	sf::Sound wraith;
	sf::Sound wraithHit;
	sf::Sound wraithGetHit;
	sf::Sound wraithDeath;
};

#endif