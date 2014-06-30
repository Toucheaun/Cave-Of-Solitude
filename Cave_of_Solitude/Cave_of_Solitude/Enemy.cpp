#include "Enemy.h"

#include <iostream>

Enemy::Enemy(Enemy_Type t,sf::Vector2<int> Pos)
{
	type = t;
	switch(t)
	{
	case ZOMBIE:
		HP = 25;
		DAM = 1;
		ATTACK_CD = 1.0f;
		break;
	case SKELETON:
		HP = 40;
		DAM = 3;
		ATTACK_CD = 1.2f;
		break;
	case WRAITH:
		HP = 55;
		DAM = 5;
		ATTACK_CD = 0.8f;
		break;
	case GOBLIN:
		HP = 10;
		DAM = 2;
		ATTACK_CD = 1.0f;
		break;
	case ORC:
		HP = 40;
		DAM = 4;
		ATTACK_CD = 1.6f;
		break;
	case TROLL:
		HP = 70;
		DAM = 10;
		ATTACK_CD = 2.5f;
		break;
	}
	Position = Pos;
	Alive = true;
	ATTACK_CD_TIMER = 0;
}


Enemy::~Enemy(void)
{
}

void Enemy::Update()
{
	DeltaTimeE = clockE.restart();

	ATTACK_CD_TIMER += DeltaTimeE.asSeconds();

	if(HP <= 0)
	{
		Alive = false;
	}

	//std::cout<<ATTACK_CD<<std::endl;
}