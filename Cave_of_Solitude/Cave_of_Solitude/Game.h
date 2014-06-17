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
	void Attack(Enemy* e);

	Scene *scene;

	sf::Clock clock;
	sf::Time DeltaTime;
	float MovementCD;
};
#endif