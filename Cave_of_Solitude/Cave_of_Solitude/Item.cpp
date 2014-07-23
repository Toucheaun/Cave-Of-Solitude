#include "Item.h"


Item::Item(int t,sf::Vector2<int> Pos)
{
	switch(t)
	{
	case 0:
		type = SWORD;
		break;
	case 1:
		type = ARMOR_1;
		break;
	}
	Position = Pos;
	Open = false;
}


Item::~Item(void)
{
}
