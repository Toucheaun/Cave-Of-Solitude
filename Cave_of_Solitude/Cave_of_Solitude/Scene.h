#ifndef Scene_H
#define Scene_H

#include "Map.h"
#include "Player.h"

class Scene
{
public:
	Scene();
	~Scene(void);

	void Update();

	Map map;
	Player *player;

	Map* getMap();

	TileType GetTileByPos(sf::Vector2<int> Pos);

	int CurrentBlockX,CurrentBlockY;

};
#endif