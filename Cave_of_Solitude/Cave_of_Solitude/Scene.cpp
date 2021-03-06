#include "Scene.h"
#include <iostream>

Scene::Scene()
{
	tilemap = TileMap(2,2,0);
	player = new Player(sf::Vector2<int>(1,1));
	//enemies.push_back(new Enemy(ZOMBIE,sf::Vector2<int>(2,2)));
	//enemies.push_back(new Enemy(SKELETON,sf::Vector2<int>(4,4)));
	//enemies.push_back(new Enemy(WRAITH,sf::Vector2<int>(6,6)));
	//enemies.push_back(new Enemy(GOBLIN,sf::Vector2<int>(8,8)));
	//enemies.push_back(new Enemy(ORC,sf::Vector2<int>(10,10)));
	//enemies.push_back(new Enemy(TROLL,sf::Vector2<int>(12,12)));


	for(int x = 0; x < TILEMAP_WIDTH; ++x)
	{
		for(int y = 0; y < TILEMAP_HEIGHT; ++y)
		{
			if(tilemap.tiles[x][y] == TILE_BEGIN)
			{
				player->Position = sf::Vector2<int>(x,y);
			}
			if(tilemap.tiles[x][y] == TILE_END)
			{
				End = sf::Vector2<int>(x,y);
			}
		}
	}

	state = START_SCREEN;

	Spawn();
}


Scene::~Scene(void)
{
}

TileMap* Scene::getTileMap()
{
	return &tilemap;
}

void Scene::Update()
{
}

void Scene::Spawn()
{

	for(int x = 0; x < TILEMAP_WIDTH; ++x)
	{
		for(int y = 0; y < TILEMAP_HEIGHT; ++y)
		{
			if(tilemap.tiles[x][y] == TILE_SPAWNER_S)
				{
					if(tilemap.Type == 0)
					{
						if(std::rand() % 100+1 > 50)
						{
							enemies.push_back(new Enemy(GOBLIN,sf::Vector2<int>(x,y)));
						}
					}
					else
					{
						if(std::rand() % 100+1 > 50)
						{
							enemies.push_back(new Enemy(ZOMBIE,sf::Vector2<int>(x,y)));
						}
					}
				}
			if(tilemap.tiles[x][y] == TILE_SPAWNER_M)
				{
					if(tilemap.Type == 0)
					{
						if(std::rand() % 100+1 > 50)
						{
							enemies.push_back(new Enemy(ORC,sf::Vector2<int>(x,y)));
						}
					}
					else
					{
						if(std::rand() % 100+1 > 50)
						{
							enemies.push_back(new Enemy(SKELETON,sf::Vector2<int>(x,y)));
						}
					}
				}
			if(tilemap.tiles[x][y] == TILE_SPAWNER_L)
				{
					if(tilemap.Type == 0)
					{
						if(std::rand() % 100+1 > 50)
						{
							enemies.push_back(new Enemy(TROLL,sf::Vector2<int>(x,y)));
						}
					}
					else
					{
						if(std::rand() % 100+1 > 50)
						{
							enemies.push_back(new Enemy(WRAITH,sf::Vector2<int>(x,y)));
						}
					}
				}
			if(tilemap.tiles[x][y] == TILE_SPAWNER_T)
				{
						if(std::rand() % 100+1 > 50)
						{
							int temprand = std::rand() % 10;
							int chesttype = 9;
							if(temprand == 0)
								chesttype = 0;
							else if (temprand == 1)
								chesttype = 1;
							else
								chesttype = 2;

							chests.push_back(new Chest(chesttype,sf::Vector2<int>(x,y)));
						}
				}
		}
	}
}

void Scene::SpawnItem(Item_type T, sf::Vector2<int> Pos)
{
	items.push_back(new Item(T,Pos));
}

void Scene::NewLevel()
{
	for (unsigned int i = 0; i < enemies.size(); i++)
	{
		delete enemies[i];
	}
	enemies.clear();

	for (unsigned int i = 0; i < chests.size(); i++)
	{
		delete chests[i];
	}
	chests.clear();

	for (unsigned int i = 0; i < items.size(); i++)
	{
		delete items[i];
	}
	items.clear();

	int size = tilemap.Height;

	int type = std::rand() % 2;
	tilemap = TileMap(size+1,size+1,type);
	
	for(int x = 0; x < TILEMAP_WIDTH; ++x)
	{
		for(int y = 0; y < TILEMAP_HEIGHT; ++y)
		{
			if(tilemap.tiles[x][y] == TILE_BEGIN)
			{
			player->Position = sf::Vector2<int>(x,y);
			}
			if(tilemap.tiles[x][y] == TILE_END)
			{
				End = sf::Vector2<int>(x,y);
			}
		}
	}

	Spawn();
}

void Scene::NewGame()
{
	for (unsigned int i = 0; i < enemies.size(); i++)
	{
		delete enemies[i];
	}
	enemies.clear();

	for (unsigned int i = 0; i < chests.size(); i++)
	{
		delete chests[i];
	}
	chests.clear();

	for (unsigned int i = 0; i < items.size(); i++)
	{
		delete items[i];
	}
	items.clear();

	delete player;

	int size = tilemap.Height;

	int type = std::rand() % 2;
	tilemap = TileMap(size+1,size+1,type);
	
	for(int x = 0; x < TILEMAP_WIDTH; ++x)
	{
		for(int y = 0; y < TILEMAP_HEIGHT; ++y)
		{
			if(tilemap.tiles[x][y] == TILE_BEGIN)
			{
				player = new Player(sf::Vector2<int>(x,y));
			}
			if(tilemap.tiles[x][y] == TILE_END)
			{
				End = sf::Vector2<int>(x,y);
			}
		}
	}

	Spawn();
}

TileType Scene::GetTileByPos(sf::Vector2<int> Pos)
{
	return tilemap.tiles[Pos.x][Pos.y];
}

bool Scene::CheckWalkable(sf::Vector2<int> Pos)
{
	if(tilemap.tiles[Pos.x][Pos.y] == TILE_WALL ||
		tilemap.tiles[Pos.x][Pos.y] == TILE_WALL_H || tilemap.tiles[Pos.x][Pos.y] == TILE_PILLAR )
	{
		return false;
	}

	return true;
}

Enemy* Scene::GetEnemyByPos(sf::Vector2<int> Pos)
{
	for(unsigned int i = 0; i < enemies.size();i++)
	{
		if(enemies.at(i)->Position == Pos)
		{
			return enemies.at(i);
		}
	}
	return NULL;
}

Chest* Scene::GetChestByPos(sf::Vector2<int> Pos)
{
	for(unsigned int i = 0; i < chests.size();i++)
	{
		if(chests.at(i)->Position == Pos)
		{
			return chests.at(i);
		}
	}
	return NULL;
}

Item* Scene::GetItemByPos(sf::Vector2<int> Pos)
{
	for(unsigned int i = 0; i < items.size();i++)
	{
		if(items.at(i)->Position == Pos)
		{
			return items.at(i);
		}
	}
	return NULL;
}

void Scene::SetNewState(Scene_State s)
{
	state = s;
}