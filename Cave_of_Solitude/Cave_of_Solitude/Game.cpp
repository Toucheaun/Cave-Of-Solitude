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
			if(Temp.at(i)->ATTACK_CD_TIMER > Temp.at(i)->ATTACK_CD)
			{
				EnemyAttack(Temp.at(i));
			}
		}
		Temp.at(i)->Update();
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
	e->ATTACK_CD_TIMER = 0;
}

float Game::GetDistance(sf::Vector2<int> Playa,sf::Vector2<int> Beast)
{
	float result = std::sqrt(((float)Playa.x-Beast.x)*(Playa.x-Beast.x)+(Playa.y-Beast.y)*(Playa.y-Beast.y));
	return result;
}

void Game::Move()
{
	std::vector<Enemy*> Temp = scene->enemies;
	bool walkable = true;

	//if(MovementCDTimer > MovementCD)
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) == true)
		{
			if(scene->GetTileByPos(sf::Vector2<int>(Pos.x,Pos.y-1)) != TILE_WALL)
			{
				for(unsigned int i = 0; i < Temp.size(); i++)
				{
					if(Temp.at(i)->Position == sf::Vector2<int>(Pos.x,Pos.y-1))
					{
						walkable = false;
					}
				}
				if(walkable == true)
				{
				scene->player->Position.y--;
				}
			}
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) == true)
		{
			if(scene->GetTileByPos(sf::Vector2<int>(Pos.x,Pos.y+1)) != TILE_WALL)
			{
				for(unsigned int i = 0; i < Temp.size(); i++)
				{
					if(Temp.at(i)->Position == sf::Vector2<int>(Pos.x,Pos.y+1))
					{
						walkable = false;
					}
				}
				if(walkable == true)
				{
				scene->player->Position.y++;
				}
			}	

		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) == true)
		{
			if(scene->GetTileByPos(sf::Vector2<int>(Pos.x-1,Pos.y)) != TILE_WALL)
			{
				for(unsigned int i = 0; i < Temp.size(); i++)
				{
					if(Temp.at(i)->Position == sf::Vector2<int>(Pos.x-1,Pos.y))
					{
						walkable = false;
					}
				}
				if(walkable == true)
				{
				scene->player->Position.x--;
				}
			}

		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) == true)
		{
			if(scene->GetTileByPos(sf::Vector2<int>(Pos.x+1,Pos.y)) != TILE_WALL)
			{
				for(unsigned int i = 0; i < Temp.size(); i++)
				{
					if(Temp.at(i)->Position == sf::Vector2<int>(Pos.x+1,Pos.y))
					{
						walkable = false;
					}
				}
				if(walkable == true)
				{
				scene->player->Position.x++;
				}
			}
		}
		MovementCDTimer = 0;
	}
}