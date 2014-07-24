#ifndef Item_H
#define Item_h

#include "Chest.h"

class Item
{
public:
	Item(Item_type t,sf::Vector2<int> Pos);
	~Item(void);

	Item_type type;
	sf::Vector2<int> Position;
};
#endif