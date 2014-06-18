//You lost it!
#ifndef Game_H
#define Game_H


#include <SFML\System.hpp>
#include "Scene.h"

class Game
{
public:
	Game(Scene *s);
	~Game(void);

	void Update();
	void Move();
	void Attack(Enemy* e);

	Scene *scene;

	sf::Clock clock;
	sf::Time DeltaTime;
	float MovementCD,MovementCDTimer;
	sf::Vector2<int> Pos;
};
#endif