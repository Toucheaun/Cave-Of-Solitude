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

	float Vit, Str, Dex, Dam, Exp;
	int Hp, Hp_Max,Points;
	Direction Facing;
	sf::Vector2<int> Position;

	sf::Clock clock;
	sf::Time DeltaTime;

	float MovementCD, MovementCDTimer, AttackCD, AttackCDTimer, ExpToLevel;
};
#endif