#ifndef Enemy_H
#define Enemy_H

#include <SFML\System\Vector2.hpp>
#include "StateMachine.h"

enum Enemy_Type
{
	SKELETON = 0,
	BLEH
};

class Enemy
{
public:
	Enemy(Enemy_Type t);
	~Enemy(void);

	float HP,DAM;
	Enemy_Type type;
	sf::Vector2<int> Position;

	StateMachine CurrentState;
};
#endif