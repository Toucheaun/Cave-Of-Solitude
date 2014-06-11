#include "Player.h"


Player::Player(sf::Vector2<int> pos)
{
	Position = pos;
	Vit = 10;
	Str = 10;
	Stam = 10;
	Int = 10;
	Hp = 10;
	Hp_Max = 10;
}


Player::~Player(void)
{
}

void Player::Update()
{
	Hp_Max = Vit;
}