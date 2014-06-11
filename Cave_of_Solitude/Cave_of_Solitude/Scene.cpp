#include "Scene.h"


Scene::Scene()
{
	map = Map(1,1);
	player = new Player(sf::Vector2<int>(1,1));
}


Scene::~Scene(void)
{
}

Map* Scene::getMap()
{
	return &map;
}