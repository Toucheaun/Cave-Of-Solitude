#include "Scene.h"
#include <iostream>

Scene::Scene()
{
	tilemap = TileMap(2,2,1);
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
	std::cout<<"Playerposition: "<<player->Position.x<<","<<player->Position.y<<std::endl;
	//std::cout<<"Player HP: "<<player->Hp<<std::endl;
}

void Scene::Spawn()
{

	for(int x = 0; x < TILEMAP_WIDTH; ++x)
	{
		for(int y = 0; y < TILEMAP_HEIGHT; ++y)
		{
			if(tilemap.tiles[x][y] == TILE_SPAWNER_S)
				{
					if(std::rand() % 100+1 > 50)
					{
						enemies.push_back(new Enemy(GOBLIN,sf::Vector2<int>(x,y)));
					}
				}
			if(tilemap.tiles[x][y] == TILE_SPAWNER_M)
				{
					if(std::rand() % 100+1 > 50)
					{
						enemies.push_back(new Enemy(ORC,sf::Vector2<int>(x,y)));
					}
				}
			if(tilemap.tiles[x][y] == TILE_SPAWNER_L)
				{
					if(std::rand() % 100+1 > 50)
					{
						enemies.push_back(new Enemy(TROLL,sf::Vector2<int>(x,y)));
					}
				}
			if(tilemap.tiles[x][y] == TILE_SPAWNER_T)
				{
						if(std::rand() % 100+1 > 50)
						{
							items.push_back(new Item(std::rand()%2,sf::Vector2<int>(x,y)));
						}
				}
		}
	}
}

void Scene::NewLevel()
{
	for (unsigned int i = 0; i < enemies.size(); i++)
	{
		delete enemies[i];
	}
	enemies.clear();

	int size = tilemap.Height;

	tilemap = TileMap(size+1,size+1,1);
	
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

TileType Scene::GetTileByPos(sf::Vector2<int> Pos)
{
	return tilemap.tiles[Pos.x][Pos.y];
}

bool Scene::CheckWalkable(sf::Vector2<int> Pos)
{
	//return true;
	if(tilemap.tiles[Pos.x][Pos.y] == TILE_WALL ||
		tilemap.tiles[Pos.x][Pos.y] == TILE_WALL_H || tilemap.tiles[Pos.x][Pos.y] == TILE_PILLAR )
	{
		return false;
	}

	return true;
}

Enemy* Scene::GetEnemyByPos(sf::Vector2<int> Pos)
{
	//std::cout<<"Attack pos:"<<Pos.x<<","<<Pos.y<<std::endl;
	for(unsigned int i = 0; i < enemies.size();i++)
	{
		if(enemies.at(i)->Position == Pos)
		{
			return enemies.at(i);
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