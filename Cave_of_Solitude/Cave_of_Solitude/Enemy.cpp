#include "Enemy.h"

#include <iostream>

Enemy::Enemy(Enemy_Type t)
{
	type = t;
	switch(t)
	{
	case SKELETON:
		break;
	case ZOMBIE:
		break;
	case WRAITH:
		break;
	case GOBLIN:
		break;
	case ORC:
		break;
	case TROLL:
		break;
	}
	HP = 25;
	DAM = 5;
	Position = sf::Vector2<int>(5,5);

	ATTACK_CD = 1.0f;
}


Enemy::~Enemy(void)
{
}

void Enemy::Update()
{
	DeltaTimeE = clockE.restart();

	ATTACK_CD += DeltaTimeE.asSeconds();

	std::cout<<ATTACK_CD<<std::endl;
}