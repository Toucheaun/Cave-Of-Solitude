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

	TileType GetTileByPos(sf::Vector2<int> Pos);

	Map map;
	Player *player;

	Map* getMap();

	int CurrentBlockX,CurrentBlockY;

};
#endif