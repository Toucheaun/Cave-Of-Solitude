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
	AttackCD = 1;
	MovementCD =1;
}


Player::~Player(void)
{
}

void Player::PickItem(Item* t)
{
	switch(t->type)
	{
		case SWORD:
			break;
		case ARMOR_1:
			break;
		case FOOD:
			if(Hp+25 > Hp_Max)
			{
				Hp = Hp_Max;
			}
			else
			{
				Hp += 25;
			}
			break;
	}
}

void Player::Update()
{
	Hp_Max = 10 * Vit;
	Dam = 1 * Str;
	AttackCD = 10 / Dex;
	MovementCD = 10 / Dex;
}