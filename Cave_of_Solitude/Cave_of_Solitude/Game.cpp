#include "Game.h"
#include <SFML\Window.hpp>

Game::Game(Scene *s)
{
	scene = s;
	MovementCD = 1;
}


Game::~Game(void)
{
}

void Game::Update()
{
	DeltaTime = clock.restart();

	sf::Vector2<int> Temp = scene->player->Position;

	if(MovementCD > 1)
	{
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
		MovementCD = 0;
	}

	MovementCD += DeltaTime.asSeconds();
}