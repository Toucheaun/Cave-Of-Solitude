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
		sf::Vector2<int>P = scene->player->Position;
		std::cout<<"X: "<<WinPos.x/64<<"Y: "<<WinPos.y/64<<std::endl;
		if(scene->GetEnemyByPos(sf::Vector2<int>(WinPos.x/64-6+P.x,WinPos.y/64-5+P.y)) != NULL)
		{
			if(GetDistance(P,scene->GetEnemyByPos(sf::Vector2<int>(WinPos.x/64-6+P.x,WinPos.y/64-5+P.y))->Position) < 2)
			{
				scene->GetEnemyByPos(sf::Vector2<int>(WinPos.x/64-6+P.x,WinPos.y/64-5+P.y))->HP -= scene->player->Dam;
				if(scene->GetEnemyByPos(sf::Vector2<int>(WinPos.x/64-6+P.x,WinPos.y/64-5+P.y))->Alive &&
					scene->GetEnemyByPos(sf::Vector2<int>(WinPos.x/64-6+P.x,WinPos.y/64-5+P.y))->HP <= 0)
				{
					scene->player->Exp += scene->GetEnemyByPos(sf::Vector2<int>(WinPos.x/64-6+P.x,WinPos.y/64-5+P.y))->EXP;
				}
			}
				//std::cout<<"HP: "<<scene->GetEnemyByPos(sf::Vector2<int>(WinPos.x/64-6+P.x,WinPos.y/64-5+P.y))->HP<<std::endl;
				//std::cout<<"X: "<<scene->GetEnemyByPos(sf::Vector2<int>(WinPos.x/64-6+P.x,WinPos.y/64-5+P.y))->Position.x<<std::endl;
				//std::cout<<"Y: "<<scene->GetEnemyByPos(sf::Vector2<int>(WinPos.x/64-6+P.x,WinPos.y/64-5+P.y))->Position.y<<std::endl;
			}
	}

	std::vector<Enemy*> Temp = scene->enemies;

	for(unsigned int i = 0; i<Temp.size(); i++)
	{
		if(GetDistance(scene->player->Position,Temp.at(i)->Position) < 2)
		{
			if(Temp.at(i)->HP >= 0)
			{
				if(Temp.at(i)->ATTACK_CD_TIMER > Temp.at(i)->ATTACK_CD)
				{
					EnemyAttack(Temp.at(i));
				}
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
		std::cout<<e->HP<<std::endl;
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
			if(scene->CheckWalkable(sf::Vector2<int>(Pos.x,Pos.y-1)) == true)
			{
				//std::cout<<"Can walk"<<std::endl;
				for(unsigned int i = 0; i < Temp.size(); i++)
				{
					if(Temp.at(i)->Position == sf::Vector2<int>(Pos.x,Pos.y-1) &&  Temp.at(i)->Alive != false)
					{
						std::cout<<"Enemy in way"<<std::endl;
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
			if(scene->CheckWalkable(sf::Vector2<int>(Pos.x,Pos.y+1)) == true)
			{
				//std::cout<<"Can walk"<<std::endl;
				for(unsigned int i = 0; i < Temp.size(); i++)
				{
					if(Temp.at(i)->Position == sf::Vector2<int>(Pos.x,Pos.y+1) &&  Temp.at(i)->Alive != false)
					{
						std::cout<<"Enemy in way"<<std::endl;
						std::cout<<Temp.at(i)->Position.x<<Temp.at(i)->Position.y;
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
			if(scene->CheckWalkable(sf::Vector2<int>(Pos.x-1,Pos.y)) == true)
			{
				//std::cout<<"Can walk"<<std::endl;
				for(unsigned int i = 0; i < Temp.size(); i++)
				{
					if(Temp.at(i)->Position == sf::Vector2<int>(Pos.x-1,Pos.y) &&  Temp.at(i)->Alive != false)
					{
						std::cout<<"Enemy in way"<<std::endl;
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
			if(scene->CheckWalkable(sf::Vector2<int>(Pos.x+1,Pos.y)) == true)
			{
				//std::cout<<"Can walk"<<std::endl;
				for(unsigned int i = 0; i < Temp.size(); i++)
				{
					if(Temp.at(i)->Position == sf::Vector2<int>(Pos.x+1,Pos.y) &&  Temp.at(i)->Alive != false)
					{
						std::cout<<"Enemy in way"<<std::endl;
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