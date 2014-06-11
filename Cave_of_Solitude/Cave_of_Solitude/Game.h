//You lost it!
#ifndef Game_H
#define Game_H

#include "Scene.h"

class Game
{
public:
	Game(Scene *s);
	~Game(void);

	void Update();

	Scene *scene;
};
#endif