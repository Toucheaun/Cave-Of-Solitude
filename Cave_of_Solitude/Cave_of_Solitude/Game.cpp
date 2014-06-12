#include "Game.h"
#include <SFML\Window.hpp>

Game::Game(Scene *s)
{
	scene = s;
}


Game::~Game(void)
{
}

void Game::Update()
{
	sf::Vector2<int> Temp = scene->player->Position;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) == true)
	{
		if(scene->GetTileByPos(sf::Vector2<int>(Temp.x,Temp.y-1)) != TILE_WALL)
		{
			scene->player->Position.y--;
		}
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) == true)
	{
		if(scene->GetTileByPos(sf::Vector2<int>(Temp.x,Temp.y+1)) != TILE_WALL)
		{
			scene->player->Position.y++;
		}	
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) == true)
	{
		if(scene->GetTileByPos(sf::Vector2<int>(Temp.x-1,Temp.y)) != TILE_WALL)
		{
			scene->player->Position.x--;
		}
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) == true)
	{
		if(scene->GetTileByPos(sf::Vector2<int>(Temp.x+1,Temp.y)) != TILE_WALL)
		{
			scene->player->Position.x++;
		}
	}
}