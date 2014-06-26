#include "Enemy.h"


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
}


Enemy::~Enemy(void)
{
}

void Enemy::Update()
{}