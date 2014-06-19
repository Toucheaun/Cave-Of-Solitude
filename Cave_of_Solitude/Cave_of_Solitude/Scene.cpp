#include "Scene.h"
#include <iostream>

Scene::Scene()
{
	map = Map(6,6);
	player = new Player(sf::Vector2<int>(1,1));
	enemies.push_back(new Enemy(SKELETON));
	CurrentBlockX = 0;
	CurrentBlockY = 0;
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

	std::cout<<"Currentblock: "<<CurrentBlockX<<","<<CurrentBlockY<<std::endl;
	std::cout<<"Playerposition: "<<player->Position.x<<","<<player->Position.y;
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

TileType Scene::GetTileByPos(sf::Vector2<int> Pos)
{
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