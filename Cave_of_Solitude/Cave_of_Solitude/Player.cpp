#include "Player.h"


Player::Player(sf::Vector2<int> pos)
{
	Position = pos;
	Vit = 10;
	Str = 10;
	Stam = 10;
	Int = 10;
}


Player::~Player(void)
{
}
