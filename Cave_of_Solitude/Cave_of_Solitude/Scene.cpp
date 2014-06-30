#include "Scene.h"
#include <iostream>

Scene::Scene()
{
	map = Map(6,6,1);
	player = new Player(sf::Vector2<int>(1,1));
	//enemies.push_back(new Enemy(ZOMBIE,sf::Vector2<int>(2,2)));
	//enemies.push_back(new Enemy(SKELETON,sf::Vector2<int>(4,4)));
	//enemies.push_back(new Enemy(WRAITH,sf::Vector2<int>(6,6)));
	//enemies.push_back(new Enemy(GOBLIN,sf::Vector2<int>(8,8)));
	//enemies.push_back(new Enemy(ORC,sf::Vector2<int>(10,10)));
	//enemies.push_back(new Enemy(TROLL,sf::Vector2<int>(12,12)));
	CurrentBlockX = 0;
	CurrentBlockY = 0;

	Spawn();
}


Scene::~Scene(void)
{
}

Map* Scene::getMap()
{
	return &map;
}

void Scene::Update()
{

	//std::cout<<"Currentblock: "<<CurrentBlockX<<","<<CurrentBlockY<<std::endl;
	//std::cout<<"Playerposition: "<<player->Position.x<<","<<player->Position.y;
	//std::cout<<"Player HP: "<<player->Hp<<std::endl;
	//std::cout<<"Enemy hp: "<<enemies.at(0)->HP<<"Position:"<<enemies.at(0)->Position.x<<","<<enemies.at(0)->Position.y<<std::endl;

	if(player->Position.x/21 > 0)
	{
		CurrentBlockX = player->Position.x/21;
	}
	else
	{
		CurrentBlockX = 0;
	}
	if(player->Position.y/21 > 0)
	{
		CurrentBlockY = player->Position.y/21;
	}
	else
	{
		CurrentBlockY = 0;
	}
}

void Scene::Spawn()
{
	for(unsigned int x = 0; x < MAX_MAP_WIDTH; ++x)
	{
		for(unsigned int y = 0; y < MAX_MAP_HEIGHT; ++y)
		{
			for(unsigned int x2 = 0; x2 < BLOCK_WIDTH; x2++)
			{
				for(unsigned int y2 = 0; y2 < BLOCK_HEIGHT; y2++)
				{
					if(map.blocks[x][y].tiles[x2][y2] == TILE_SPAWNER_S)
					{
						if(std::rand() % 100+1 > 50)
						{
							enemies.push_back(new Enemy(GOBLIN,sf::Vector2<int>(x2+x*21,y2+y*21)));
						}
					}
					if(map.blocks[x][y].tiles[x2][y2] == TILE_SPAWNER_M)
					{
						if(std::rand() % 100+1 > 50)
						{
							enemies.push_back(new Enemy(ORC,sf::Vector2<int>(x2+x*21,y2+y*21)));
						}
					}
					if(map.blocks[x][y].tiles[x2][y2] == TILE_SPAWNER_L)
					{
						if(std::rand() % 100+1 > 50)
						{
							enemies.push_back(new Enemy(TROLL,sf::Vector2<int>(x2+x*21,y2+y*21)));
						}
					}
					if(map.blocks[x][y].tiles[x2][y2] == TILE_SPAWNER_T)
					{
						
					}
				}
			}
		}
	}

}

TileType Scene::GetTileByPos(sf::Vector2<int> Pos)
{
	//return TILE_FLOOR;
	sf::Vector2<int> Temp = Pos;
	if(Pos.x / 21 > 1)
	{
		Temp.x = Pos.x/21;
	}
	if(Pos.y / 21 > 1)
	{
		Temp.y = Pos.y/21;
	}
	if(Temp.x == 21)
	{
		return map.blocks[CurrentBlockX+1][CurrentBlockY].tiles[0][Temp.y];
	}
	else if(Temp.y == 21)
	{
		return map.blocks[CurrentBlockX][CurrentBlockY+1].tiles[Temp.x][0];
	}
	return map.blocks[CurrentBlockX][CurrentBlockY].tiles[Temp.x][Temp.y];
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