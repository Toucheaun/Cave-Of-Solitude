#include "Enemy.h"

#include <iostream>

Enemy::Enemy(Enemy_Type t,sf::Vector2<int> Pos)
{
	type = t;
	switch(t)
	{
	case ZOMBIE:
		HP = 25;
		DAM = 2;
		ATTACK_CD = 1.5f;
		EXP = 2;
		break;
	case SKELETON:
		HP = 40;
		DAM = 3;
		ATTACK_CD = 1.2f;
		EXP = 5;
		break;
	case WRAITH:
		HP = 55;
		DAM = 3;
		ATTACK_CD = 1.0f;
		EXP = 25;
		break;
	case GOBLIN:
		HP = 20;
		DAM = 1;
		ATTACK_CD = 0.8f;
		EXP = 2;
		break;
	case ORC:
		HP = 35;
		DAM = 3;
		ATTACK_CD = 1.5f;
		EXP = 5;
		break;
	case TROLL:
		HP = 70;
		DAM = 8;
		ATTACK_CD = 2.5f;
		EXP = 25;
		break;
	}
	Position = Pos;
	CurrentState = StateMachine(GUARD);
	Alive = true;
	ATTACK_CD_TIMER = 0;

	MOVE_CD = 1.0f;
	MOVE_CD_TIMER = 0;
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

void Enemy::SetPath(std::vector<sf::Vector2<int>> p)
{
	path = p;
	path.erase(path.end()-1);
	it = path.end();
}

void Enemy::Move()
{
	DeltaTimeA = clockA.restart();

	MOVE_CD_TIMER += DeltaTimeA.asSeconds();

	if(!path.empty())
	{
		if(MOVE_CD_TIMER > MOVE_CD)
		{
			if(it != path.begin())
			{
				it--;
			}
			Position = (*it);
			MOVE_CD_TIMER = 0;
		}
	}
}