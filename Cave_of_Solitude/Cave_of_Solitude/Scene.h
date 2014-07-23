#ifndef Scene_H
#define Scene_H

#include "TileMap.h"
#include "Enemy.h"
#include "Player.h"

#include <vector>;

enum Scene_State
{
	START_SCREEN,
	INFO,
};

class Scene
{
public:
	Scene();
	~Scene(void);

	void Update();
	void Spawn();

	TileMap tilemap;
	Player *player;

	sf::Vector2<int> End;

	TileMap* getTileMap();
	void NewLevel();

	TileType GetTileByPos(sf::Vector2<int> Pos);
	bool CheckWalkable(sf::Vector2<int> Pos);

	Enemy* GetEnemyByPos(sf::Vector2<int> Pos);
	Item* GetItemByPos(sf::Vector2<int> Pos);
	std::vector<Enemy*> enemies;
	std::vector<Item*> items;

	void SetNewState(Scene_State s);
	Scene_State state;
};
#endif