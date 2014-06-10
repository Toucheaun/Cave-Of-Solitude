#ifndef Player_H
#define Player_H

#include <SFML\System\Vector2.hpp>

class Player
{
public:
	Player(sf::Vector2<int> pos);
	~Player(void);

	float Vit, Str, Stam, Int;
	sf::Vector2<int> Position;
};
#endif