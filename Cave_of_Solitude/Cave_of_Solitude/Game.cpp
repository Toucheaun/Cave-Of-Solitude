#include "Game.h"
#include <SFML\Window.hpp>
#include <iostream>

Game::Game(Scene *s, sf::RenderWindow *win)
{
	scene = s;
	MovementCDTimer = 1.0f;
	MovementCD = 1.0f;
	Pos = scene->player->Position;
	window = win;
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

	//Ranged attack that is broken
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i WinPos = sf::Mouse::getPosition(*window);
		if(scene->GetEnemyByPos(WinPos/64) != NULL)
		{
			scene->GetEnemyByPos(WinPos/64)->HP -= scene->player->Dam;
		}
	}

	std::vector<Enemy*> Temp = scene->enemies;

	for(unsigned int i = 0; i<Temp.size(); i++)
	{
		if(GetDistance(scene->player->Position,Temp.at(i)->Position) < 2)
		{
			EnemyAttack(Temp.at(i));
		}
	}

	MovementCDTimer += DeltaTime.asSeconds();
	//std::cout<<MovementCDTimer<<std::endl;
}

void Game::Attack(Enemy* e)
{
	if(e != NULL)
	{
		e->HP -= scene->player->Dam;
	}
}

void Game::EnemyAttack(Enemy* e)
{
	scene->player->Hp -= e->DAM;
}

float Game::GetDistance(sf::Vector2<int> Playa,sf::Vector2<int> Beast)
{
	float result = std::sqrt(((float)Playa.x-Beast.x)*(Playa.x-Beast.x)+(Playa.y-Beast.y)*(Playa.y-Beast.y));
	return result;
}

void Game::Move()
{
	
	//if(MovementCDTimer > MovementCD)
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