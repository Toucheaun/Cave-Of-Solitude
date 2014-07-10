#ifndef Item_H
#define Item_h

#include <SFML\System.hpp>

enum Item_type
{
	SWORD = 0,
	ARMOR_1,
};

class Item
{
public:
	Item(Item_type t,sf::Vector2<int> Pos);
	~Item(void);

	Item_type type;
	sf::Vector2<int> Position;
};
#endif