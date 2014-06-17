#include "Scene.h"
#include <iostream>

Scene::Scene()
{
	map = Map(1,1);
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
	std::cout<<"Enemy hp: "<<enemies.at(0)->HP<<std::endl;

	if(player->Position.x/21 > 0)
	{
		CurrentBlockX = player->Position.x/21;
	}
	if(player->Position.y/21 > 0)
	{
		CurrentBlockY = player->Position.y/21;
	}
}

TileType Scene::GetTileByPos(sf::Vector2<int> Pos)
{
	return map.blocks[CurrentBlockX][CurrentBlockY].tiles[Pos.x][Pos.y];
}