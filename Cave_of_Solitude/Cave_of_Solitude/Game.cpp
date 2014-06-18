#include "Game.h"
#include <SFML\Window.hpp>

Game::Game(Scene *s)
{
	scene = s;
	MovementCDTimer = 1.0f;
	MovementCD = 1.0f;
	Pos = scene->player->Position;
}


Game::~Game(void)
{
}

void Game::Update()
{
	DeltaTime = clock.restart();

	Pos = scene->player->Position;

	Move();

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::J))
	{
		switch(scene->player->Facing)
		{
		case UP:
			Attack(scene->GetEnemyByPos(sf::Vector2<int>(Pos.x,Pos.y+1)));
			break;
		case LEFT:
			Attack(scene->GetEnemyByPos(sf::Vector2<int>(Pos.x+1,Pos.y)));
			break;
		case DOWN:
			Attack(scene->GetEnemyByPos(sf::Vector2<int>(Pos.x,Pos.y-1)));
			break;
		case RIGHT:
			Attack(scene->GetEnemyByPos(sf::Vector2<int>(Pos.x-1,Pos.y)));
			break;
		}
	}


	MovementCDTimer += DeltaTime.asSeconds();
	//printf("%.0f",&MovementCDTimer);
}

void Game::Attack(Enemy* e)
{
	if(e != NULL)
	{
		e->HP -= scene->player->Dam;
	}
}

void Game::Move()
{
	
	if(MovementCDTimer > MovementCD)
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) == true)
		{
			if(scene->GetTileByPos(sf::Vector2<int>(Pos.x,Pos.y-1)) != TILE_WALL)
			{
				scene->player->Position.y--;
				scene->player->Facing = DOWN;
			}
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) == true)
		{
			if(scene->GetTileByPos(sf::Vector2<int>(Pos.x,Pos.y+1)) != TILE_WALL)
			{
				scene->player->Position.y++;
				scene->player->Facing = UP;
			}	

		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) == true)
		{
			if(scene->GetTileByPos(sf::Vector2<int>(Pos.x-1,Pos.y)) != TILE_WALL)
			{
				scene->player->Position.x--;
				scene->player->Facing = LEFT;
			}

		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) == true)
		{
			if(scene->GetTileByPos(sf::Vector2<int>(Pos.x+1,Pos.y)) != TILE_WALL)
			{
				scene->player->Position.x++;
				scene->player->Facing = RIGHT;
			}
		}
		MovementCDTimer = 0;
	}
}