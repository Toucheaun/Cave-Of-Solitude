#include "Player.h"


Player::Player(sf::Vector2<int> pos)
{
	Position = pos;
	Vit = 10;
	Str = 10;
	Stam = 10;
	Int = 10;
	Dam = Str;
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
}