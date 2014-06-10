#include "Scene.h"


Scene::Scene()
{
	map = Map(1,1);
}


Scene::~Scene(void)
{
}

Map* Scene::getMap()
{
	return &map;
}