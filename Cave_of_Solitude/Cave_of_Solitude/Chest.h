#ifndef Chest_H
#define Chest_h

#include <SFML\System.hpp>

enum Item_type
{
	SWORD = 0,
	ARMOR_1,
	FOOD,
};

class Chest
{
public:
	Chest(int t,sf::Vector2<int> Pos);
	~Chest(void);

	Item_type type;
	sf::Vector2<int> Position;
	bool Open;
};
#endif