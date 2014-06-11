#ifndef Player_H
#define Player_H

#include <SFML\System\Vector2.hpp>

class Player
{
public:
	Player(sf::Vector2<int> pos);
	~Player(void);

	void Update();

	float Vit, Str, Stam, Int;
	int Hp, Hp_Max;
	sf::Vector2<int> Position;
};
#endif