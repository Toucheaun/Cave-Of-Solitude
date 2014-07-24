#include "Chest.h"


Chest::Chest(int t,sf::Vector2<int> Pos)
{
	switch(t)
	{
	case 0:
		type = SWORD;
		break;
	case 1:
		type = ARMOR_1;
		break;
	case 2:
		type = FOOD;
		break;
	}
	Position = Pos;
	Open = false;
}


Chest::~Chest(void)
{
}
