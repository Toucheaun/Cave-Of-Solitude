#ifndef Scene_H
#define Scene_H

#include "Map.h"
#include "Player.h"

class Scene
{
public:
	Scene();
	~Scene(void);

	Map map;
	Player *player;

	Map* getMap();

};
#endif