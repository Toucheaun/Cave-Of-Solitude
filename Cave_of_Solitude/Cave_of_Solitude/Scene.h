#ifndef Scene_H
#define Scene_H

#include "Map.h"
#include "Enemy.h"
#include "Player.h"

#include <vector>;

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

	std::vector<Enemy*> enemies;

};
#endif