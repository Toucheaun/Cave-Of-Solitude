#include "Item.h"


Item::Item(Item_type t,sf::Vector2<int> Pos)
{
	type = t;
	Position = Pos;
}


Item::~Item(void)
{
}
