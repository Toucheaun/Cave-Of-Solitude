#ifndef Enemy_H
#define Enemy_H

#include <SFML\System\Vector2.hpp>

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

	float HP;
	Enemy_Type type;
	sf::Vector2<int> Position;
};
#endif