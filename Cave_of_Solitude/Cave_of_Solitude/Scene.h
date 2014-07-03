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
	void Spawn();

	Map map;
	Player *player;

	Map* getMap();

	TileType GetTileByPos(sf::Vector2<int> Pos);
	bool CheckWalkable(sf::Vector2<int> Pos);

	int CurrentBlockX,CurrentBlockY;

	Enemy* GetEnemyByPos(sf::Vector2<int> Pos);
	std::vector<Enemy*> enemies;

};
#endif