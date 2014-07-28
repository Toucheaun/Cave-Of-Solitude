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
	BaseHP = 10;
	BaseDam = 10.0f;
	Facing = DOWN;
	MovementCDTimer = 1.0f;
	MovementCD = 1.0f;
	AttackCD = 1.0f;
	AttackCDTimer = 1.0f;
	ExpToLevel = 100;
	Points = 0;
}


Player::~Player(void)
{
}

void Player::PickItem(Item* t)
{
	switch(t->type)
	{
		case SWORD:
			BaseDam += 1;
			break;
		case ARMOR_1:
			BaseHP += 1.0f;
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
	DeltaTime = clock.restart();

	MovementCDTimer += DeltaTime.asSeconds();
	AttackCDTimer += DeltaTime.asSeconds();

	Hp_Max = BaseHP * Vit;
	Dam = BaseDam/10 * Str;
	AttackCD = 10 / Dex;
	MovementCD = 10 / Dex;
	if(Exp >= ExpToLevel)
	{
		Points += 2;
		Exp = 0;
		ExpToLevel = ExpToLevel*1.5f;
	}
}