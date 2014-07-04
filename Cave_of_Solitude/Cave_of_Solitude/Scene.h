#ifndef Scene_H
#define Scene_H

#include "TileMap.h"
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

	TileMap tilemap;
	Player *player;

	TileMap* getTileMap();

	TileType GetTileByPos(sf::Vector2<int> Pos);
	bool CheckWalkable(sf::Vector2<int> Pos);

	Enemy* GetEnemyByPos(sf::Vector2<int> Pos);
	std::vector<Enemy*> enemies;

};
#endif