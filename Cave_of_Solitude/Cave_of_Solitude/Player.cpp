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
	Hp = 10;
	Hp_Max = 10;
	Facing = DOWN;
}


Player::~Player(void)
{
}

void Player::Update()
{
	Hp_Max = Vit;
}