#include <iostream>
#include "SoundSystem.h"

SoundSystem::SoundSystem()
{
	// Main Menu
	if (!menu.openFromFile("../Resources/Music/Main_Menu.mp3"))
	{
		printf("MUSIC load failed ");
	}

	// In Game
	if (!inGame.openFromFile("../Resources/Music/InGame.mp3"))
	{
		printf("MUSIC load failed ");
	}

	// Coin
	coinBuffer.loadFromFile("../Resources/Sound/Coin.wav");
	if(!coinBuffer.loadFromFile("../Resources/Sound/Coin.wav"))
	{
		printf("SOUND load failed ");
	}
	coin.setBuffer(coinBuffer);

	// Food
	foodBuffer.loadFromFile("../Resources/Sound/Food.wav");
	if(!foodBuffer.loadFromFile("../Resources/Sound/Food.wav"))
	{
		printf("SOUND load failed ");
	}
	food.setBuffer(foodBuffer);

	// Sword
	swordBuffer.loadFromFile("../Resources/Sound/sword.wav");
	if(!swordBuffer.loadFromFile("../Resources/Sound/sword.wav"))
	{
		printf("SOUND load failed ");
	}
	sword.setBuffer(swordBuffer);

	// Player Step
	playerStepBuffer.loadFromFile("../Resources/Sound/Player_Step.wav");
	if(!playerStepBuffer.loadFromFile("../Resources/Sound/Player_Step.wav"))
	{
		printf("SOUND load failed ");
	}
	playerStep.setBuffer(playerStepBuffer);

	// Player GetHit
	playerGetHitBuffer.loadFromFile("../Resources/Sound/Player_GetHit.wav");
	if(!playerGetHitBuffer.loadFromFile("../Resources/Sound/Player_GetHit.wav"))
	{
		printf("SOUND load failed ");
	}
	playerGetHit.setBuffer(playerGetHitBuffer);

	// Player Death
	playerDeathBuffer.loadFromFile("../Resources/Sound/Player_Death.wav");
	if(!playerDeathBuffer.loadFromFile("../Resources/Sound/Player_Death.wav"))
	{
		printf("SOUND load failed ");
	}
	playerDeath.setBuffer(playerDeathBuffer);

	// Goblin
	goblinBuffer.loadFromFile("../Resources/Sound/Goblin.wav");
	if(!goblinBuffer.loadFromFile("../Resources/Sound/Goblin.wav"))
	{
		printf("SOUND load failed ");
	}
	goblin.setBuffer(goblinBuffer);

	// Goblin Hit
	goblinHitBuffer.loadFromFile("../Resources/Sound/Goblin_Hit.wav");
	if(!goblinHitBuffer.loadFromFile("../Resources/Sound/Goblin_Hit.wav"))
	{
		printf("SOUND load failed ");
	}
	goblinHit.setBuffer(goblinHitBuffer);

	// Goblin GetHit
	goblinGetHitBuffer.loadFromFile("../Resources/Sound/Goblin_GetHit.wav");
	if(!goblinGetHitBuffer.loadFromFile("../Resources/Sound/Goblin_GetHit.wav"))
	{
		printf("SOUND load failed ");
	}
	goblinGetHit.setBuffer(goblinGetHitBuffer);

	// Goblin Death
	goblinDeathBuffer.loadFromFile("../Resources/Sound/Goblin_Death.wav");
	if(!goblinDeathBuffer.loadFromFile("../Resources/Sound/Goblin_Death.wav"))
	{
		printf("SOUND load failed ");
	}
	goblinDeath.setBuffer(goblinDeathBuffer);

	// Zombie
	zombieBuffer.loadFromFile("../Resources/Sound/Zombie.wav");
	if(!zombieBuffer.loadFromFile("../Resources/Sound/Zombie.wav"))
	{
		printf("SOUND load failed ");
	}
	zombie.setBuffer(zombieBuffer);

	// Zombie Hit
	zombieHitBuffer.loadFromFile("../Resources/Sound/Zombie_Hit.wav");
	if(!zombieHitBuffer.loadFromFile("../Resources/Sound/Zombie_Hit.wav"))
	{
		printf("SOUND load failed ");
	}
	zombieHit.setBuffer(zombieHitBuffer);

	// Zombie GetHit
	zombieGetHitBuffer.loadFromFile("../Resources/Sound/Zombie_GetHit.wav");
	if(!zombieGetHitBuffer.loadFromFile("../Resources/Sound/Zombie_GetHit.wav"))
	{
		printf("SOUND load failed ");
	}
	zombieGetHit.setBuffer(zombieGetHitBuffer);

	// Zombie Death
	zombieDeathBuffer.loadFromFile("../Resources/Sound/Zombie_Death.wav");
	if(!zombieDeathBuffer.loadFromFile("../Resources/Sound/Zombie_Death.wav"))
	{
		printf("SOUND load failed ");
	}
	zombieDeath.setBuffer(zombieDeathBuffer);

	// Orc
	orcBuffer.loadFromFile("../Resources/Sound/Orc.wav");
	if(!orcBuffer.loadFromFile("../Resources/Sound/Orc.wav"))
	{
		printf("SOUND load failed ");
	}
	orc.setBuffer(orcBuffer);

	// Orc Hit
	orcHitBuffer.loadFromFile("../Resources/Sound/Orc_Hit.wav");
	if(!orcHitBuffer.loadFromFile("../Resources/Sound/Orc_Hit.wav"))
	{
		printf("SOUND load failed ");
	}
	orcHit.setBuffer(orcHitBuffer);

	// Orc GetHit
	orcGetHitBuffer.loadFromFile("../Resources/Sound/Orc_GetHit.wav");
	if(!orcGetHitBuffer.loadFromFile("../Resources/Sound/Orc_GetHit.wav"))
	{
		printf("SOUND load failed ");
	}
	orcGetHit.setBuffer(orcGetHitBuffer);

	// Orc Death
	orcDeathBuffer.loadFromFile("../Resources/Sound/Orc_Death.wav");
	if(!orcDeathBuffer.loadFromFile("../Resources/Sound/Orc_Death.wav"))
	{
		printf("SOUND load failed ");
	}
	orcDeath.setBuffer(orcDeathBuffer);

	// Skeleton
	skeletonBuffer.loadFromFile("../Resources/Sound/Skeleton.wav");
	if(!skeletonBuffer.loadFromFile("../Resources/Sound/Skeleton.wav"))
	{
		printf("SOUND load failed ");
	}
	skeleton.setBuffer(skeletonBuffer);

	// Skeleton Hit
	skeletonHitBuffer.loadFromFile("../Resources/Sound/Skeleton_Hit.wav");
	if(!skeletonHitBuffer.loadFromFile("../Resources/Sound/Skeleton_Hit.wav"))
	{
		printf("SOUND load failed ");
	}
	skeletonHit.setBuffer(skeletonHitBuffer);

	// Skeleton GetHit
	skeletonGetHitBuffer.loadFromFile("../Resources/Sound/Skeleton_GetHit.wav");
	if(!skeletonGetHitBuffer.loadFromFile("../Resources/Sound/Skeleton_GetHit.wav"))
	{
		printf("SOUND load failed ");
	}
	skeletonGetHit.setBuffer(skeletonGetHitBuffer);

	// Skeleton Death
	skeletonDeathBuffer.loadFromFile("../Resources/Sound/Skeleton_Death.wav");
	if(!skeletonDeathBuffer.loadFromFile("../Resources/Sound/Skeleton_Death.wav"))
	{
		printf("SOUND load failed ");
	}
	skeletonDeath.setBuffer(skeletonDeathBuffer);

	// Troll
	trollBuffer.loadFromFile("../Resources/Sound/Troll.wav");
	if(!trollBuffer.loadFromFile("../Resources/Sound/Troll.wav"))
	{
		printf("SOUND load failed ");
	}
	troll.setBuffer(trollBuffer);

	// Troll Hit
	trollHitBuffer.loadFromFile("../Resources/Sound/Troll_Hit.wav");
	if(!trollHitBuffer.loadFromFile("../Resources/Sound/Troll_Hit.wav"))
	{
		printf("SOUND load failed ");
	}
	trollHit.setBuffer(trollHitBuffer);

	// Troll GetHit
	trollGetHitBuffer.loadFromFile("../Resources/Sound/Troll_GetHit.wav");
	if(!trollGetHitBuffer.loadFromFile("../Resources/Sound/Troll_GetHit.wav"))
	{
		printf("SOUND load failed ");
	}
	trollGetHit.setBuffer(trollGetHitBuffer);

	// Troll Death
	trollDeathBuffer.loadFromFile("../Resources/Sound/Troll_Death.wav");
	if(!trollDeathBuffer.loadFromFile("../Resources/Sound/Troll_Death.wav"))
	{
		printf("SOUND load failed ");
	}
	trollDeath.setBuffer(trollDeathBuffer);

	// Wraith
	wraithBuffer.loadFromFile("../Resources/Sound/Wraith.wav");
	if(!wraithBuffer.loadFromFile("../Resources/Sound/Wraith.wav"))
	{
		printf("SOUND load failed ");
	}
	wraith.setBuffer(wraithBuffer);

	// Wraith Hit
	wraithHitBuffer.loadFromFile("../Resources/Sound/Wraith_Hit.wav");
	if(!wraithHitBuffer.loadFromFile("../Resources/Sound/Wraith_Hit.wav"))
	{
		printf("SOUND load failed ");
	}
	wraithHit.setBuffer(wraithHitBuffer);

	// Wraith GetHit
	wraithGetHitBuffer.loadFromFile("../Resources/Sound/Wraith_GetHit.wav");
	if(!wraithGetHitBuffer.loadFromFile("../Resources/Sound/Wraith_GetHit.wav"))
	{
		printf("SOUND load failed ");
	}
	wraithGetHit.setBuffer(wraithGetHitBuffer);

	// Wraith Death
	wraithDeathBuffer.loadFromFile("../Resources/Sound/Wraith_Death.wav");
	if(!wraithDeathBuffer.loadFromFile("../Resources/Sound/Wraith_Death.wav"))
	{
		printf("SOUND load failed ");
	}
	wraithDeath.setBuffer(wraithDeathBuffer);
}

SoundSystem::~SoundSystem()
{
	// Remove buffers
}