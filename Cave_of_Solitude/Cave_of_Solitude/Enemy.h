#ifndef Enemy_H
#define Enemy_H

#include <SFML\System.hpp>
#include "StateMachine.h"

enum Enemy_Type
{
	ZOMBIE = 0,
	SKELETON,
	WRAITH,
	GOBLIN,
	ORC,
	TROLL,
};

class Enemy
{
public:
	Enemy(Enemy_Type t,sf::Vector2<int> Pos);
	~Enemy(void);
	void Update();

	float HP,DAM, EXP;
	bool Alive;
	Enemy_Type type;
	sf::Vector2<int> Position;

	sf::Clock clockE;
	sf::Time DeltaTimeE;
	float ATTACK_CD, ATTACK_CD_TIMER;

	StateMachine CurrentState;
};
#endif