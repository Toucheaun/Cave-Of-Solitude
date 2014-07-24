#ifndef Player_H
#define Player_H

#include <SFML\System\Vector2.hpp>
#include "Item.h"

enum Direction
{
	UP = 0,
	LEFT,
	DOWN,
	RIGHT
};

class Player
{
public:
	Player(sf::Vector2<int> pos);
	~Player(void);

	void Update();
	void PickItem(Item* t);

	float Vit, Str, Dex, Dam, Exp, AttackCD, MovementCD;
	int Hp, Hp_Max;
	Direction Facing;
	sf::Vector2<int> Position;
};
#endif