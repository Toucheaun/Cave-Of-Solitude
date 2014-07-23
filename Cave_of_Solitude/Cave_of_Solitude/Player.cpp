#include "Player.h"


Player::Player(sf::Vector2<int> pos)
{
	Position = pos;
	Vit = 10;
	Str = 10;
	Dex = 10;
	Dam = 1;
	Exp = 0;
	Hp = 100;
	Hp_Max = 100;
	Facing = DOWN;
}


Player::~Player(void)
{
}

void Player::PickItem(Item t)
{
	//lots of checks
}

void Player::Update()
{
	Hp_Max = 10 * Vit;
	Dam = 1 * Str;
}