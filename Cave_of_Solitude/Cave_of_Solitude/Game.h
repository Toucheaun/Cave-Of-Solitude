//You lost it!
#ifndef Game_H
#define Game_H


#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include "Scene.h"

class Game
{
public:
	Game(Scene *s,sf::RenderWindow *win);
	~Game(void);

	void Update();
	void Move();
	void Attack(Enemy* e);

	Scene *scene;

	sf::Clock clock;
	sf::Time DeltaTime;
	float MovementCD,MovementCDTimer;
	sf::Vector2<int> Pos;
	sf::RenderWindow *window;
};
#endif