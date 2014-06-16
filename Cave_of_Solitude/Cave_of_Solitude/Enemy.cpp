#include "Enemy.h"


Enemy::Enemy(Enemy_Type t)
{
	type = t;
	HP = 25;
	Position = sf::Vector2<int>(5,5);
}


Enemy::~Enemy(void)
{
}
