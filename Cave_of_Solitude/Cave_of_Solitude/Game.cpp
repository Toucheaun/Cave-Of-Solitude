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
				scene->player->Facing = DOWN;
			}
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) == true)
		{
			if(scene->GetTileByPos(sf::Vector2<int>(Temp.x,Temp.y+1)) != TILE_WALL)
			{
				scene->player->Position.y++;
				scene->player->Facing = UP;
			}	

		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) == true)
		{
			if(scene->GetTileByPos(sf::Vector2<int>(Temp.x-1,Temp.y)) != TILE_WALL)
			{
				scene->player->Position.x--;
				scene->player->Facing = LEFT;
			}

		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) == true)
		{
			if(scene->GetTileByPos(sf::Vector2<int>(Temp.x+1,Temp.y)) != TILE_WALL)
			{
				scene->player->Position.x++;
				scene->player->Facing = RIGHT;
			}
		}
		MovementCD = 0;
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::J))
	{
		Attack(scene->enemies.at(0));
	}

	MovementCD += DeltaTime.asSeconds();
}

void Game::Attack(Enemy* e)
{
	if(e != NULL)
	{
		e->HP -= scene->player->Dam;
	}
}