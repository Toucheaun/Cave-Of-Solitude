#include "Game.h"
#include <SFML\Window.hpp>
#include <iostream>

#include "SoundSystem.h"

Game::Game(Scene *s, sf::RenderWindow *win, SoundSystem *ss)
{
	soundSystem = ss;
	scene = s;
	MovementCDTimer = 1.0f;
	MovementCD = 1.0f;
	Pos = scene->player->Position;
	window = win;
	level = 1;
	std::vector<Enemy*> Temp = scene->enemies;
	for(unsigned int i = 0; i<Temp.size(); i++)
	{
		if(Temp.at(i)->Position == sf::Vector2<int>(4,3))
		{
			Temp.at(i)->CurrentState.SetNewState(CHASE);
		}
	}

	// Äänen play esimerkki
	soundSystem->troll.play();

}


Game::~Game(void)
{
}

void Game::Update()
{
	if(scene->state == INFO)
	{
	DeltaTime = clock.restart();

	Pos = scene->player->Position;

	if(scene->End == Pos)
	{
		scene->NewLevel();
	}

	Move();

	Attack();


	std::vector<Enemy*> Temp = scene->enemies;
	std::vector<Item> Temp2 = scene->items;

	for(unsigned int i = 0; i<Temp.size(); i++)
	{
		switch(Temp.at(i)->CurrentState.state)
		{
		case GUARD:
			if(GetDistance(scene->player->Position,Temp.at(i)->Position) < 10)
			{
				Temp.at(i)->CurrentState.SetNewState(CHASE);
			}
			//check if player visible
		break;
		case CHASE:
			if(Temp.at(i)->Alive != false)
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
				else
				{
					Temp.at(i)->SetPath(FindPath(Temp.at(i)->Position, Pos));
					Temp.at(i)->Move();
					printf("I move");
				}
			}
			break;
		}
		Temp.at(i)->Update();
	}

	for(unsigned int i = 0; i<Temp2.size(); i++)
	{
		if(Temp2[i].Position == Pos)
		{
			//
		}
	}

	MovementCDTimer += DeltaTime.asSeconds();
	//std::cout<<MovementCDTimer<<std::endl;
	}
	else
	{}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		scene->SetNewState(INFO);
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		scene->SetNewState(START_SCREEN);
	}
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

void Game::Attack()
{
	//Melee attack with mouse attack
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
}

void Game::clearVectors()
{
	for (unsigned int i = 0; i < openList.size(); i++)
	{
		delete openList[i];
	}
	openList.clear();
	
	for (unsigned int i = 0; i < closedList.size(); i++)
	{
		delete closedList[i];
	}
	closedList.clear();

	
	PathToGoal.clear();
}

std::vector<sf::Vector2<int>> Game::FindPath(sf::Vector2<int> Start,sf::Vector2<int> End)
{
	return FindPathReversed(Start,End);
}

std::vector<sf::Vector2<int>> Game::FindPathReversed(sf::Vector2<int> Start,sf::Vector2<int> End)
{
	clearVectors();

	SearchNode* startNode = new SearchNode(Start,scene->GetTileByPos(Start),NULL);

	SearchNode* goalNode = new SearchNode(End,scene->GetTileByPos(End), NULL);

	startNode->G = 0;
	startNode->H = startNode->HeuristicDistance(*goalNode);

	openList.push_back(startNode);

	while(!openList.empty())
	{
		SearchNode* currentNode = getNextNode();

		if(currentNode->Position == goalNode->Position)
		{
			goalNode->nextNode = currentNode->nextNode;

			for(std::vector<SearchNode*>::iterator it = openList.begin(); it != openList.end(); it++)
			{
				//propably unnecessary(honestly no fucking idea)
			}

			SearchNode* getPath = goalNode;
			while (getPath != NULL)
			{
				/*if (GetTileByPos(getPath->position) != walkable)
				{
					//error message
				}*/
				PathToGoal.push_back(getPath->Position);
				getPath = getPath->nextNode;
			}
			
			return PathToGoal;
		}
		else
		{
			//rightCell
			pathOpened(currentNode->Position + sf::Vector2<int>(1,0),currentNode->G+1,currentNode,goalNode);
			//leftCell
			pathOpened(currentNode->Position + sf::Vector2<int>(-1,0),currentNode->G+1,currentNode,goalNode);
			//upperCell
			pathOpened(currentNode->Position + sf::Vector2<int>(0,-1),currentNode->G+1,currentNode,goalNode);
			//lowerCell
			pathOpened(currentNode->Position + sf::Vector2<int>(0,1),currentNode->G+1,currentNode,goalNode);

			//upperRight
			//pathOpened(currentNode->Position + sf::Vector2<int>(1,-1),currentNode->G+1.141f,currentNode,goalNode);
			//upperLeft
			//pathOpened(currentNode->Position + sf::Vector2<int>(-1,-1),currentNode->G+1.141f,currentNode,goalNode);
			//lowerRight
			//pathOpened(currentNode->Position + sf::Vector2<int>(1,1),currentNode->G+1.141f,currentNode,goalNode);
			//loverLeft
			//pathOpened(currentNode->Position + sf::Vector2<int>(-1,1),currentNode->G+1.141f,currentNode,goalNode);
		}
	}
	PathToGoal.push_back(Start);
	return PathToGoal;
}

SearchNode* Game::getNextNode()
{
	float bestF = FLT_MAX;
	int cellIndex = -1;

	SearchNode* nextNode = NULL;

	for(unsigned int i = 0; i<openList.size(); i++)
	{
		if(openList[i]->GetF() <= bestF)
		{
			bestF = openList[i]->GetF();
			cellIndex = i;
		}
	}

	if(cellIndex != -1)
	{
		nextNode = openList[cellIndex];

		for(int i = 0; i<closedList.size(); i++)
		{
			if(closedList[i]->Position == nextNode->Position)
			{
				break;
			}
		}
		closedList.push_back(nextNode);
		//move
		openList.erase(openList.begin()+cellIndex);

		return nextNode;
	}
	else
	{
		return NULL;
	}
}

void Game::pathOpened(sf::Vector2<int> Position, float newCost,SearchNode* nextNode, SearchNode* goalNode)
{
	//tähän väliin checkki että voidaanko mennä ja return(eli break) jos on
	if(Position.x < 0 || Position.x > TILEMAP_WIDTH ||
		Position.y < 0 || Position.y > TILEMAP_HEIGHT ||
		scene->GetTileByPos(Position) == TILE_WALL ||
		scene->GetTileByPos(Position) == TILE_WALL_H)
	return;

	//Checkki otusten paikoille
	std::vector<Enemy*> Temp = scene->enemies;
	for(unsigned int i = 0; i < Temp.size(); i++)
	{
		if(Temp[i]->Position != goalNode->Position)
		{
			if(Temp.at(i)->Alive == true)
			{
				if(Temp[i]->Position == Position)
				{
					return;
				}
			}
		}
	}

	//Checkki pelaajan paikalle
	if(Pos != goalNode->Position)
	{
		if(Pos == Position)
		{
			return;
		}
	}


	for(unsigned int i = 0; i < closedList.size(); i++)
	{
		if(Position == closedList[i]->Position)
		return;
	}

	SearchNode* newNode = new SearchNode(Position,scene->GetTileByPos(Position),nextNode);
	newNode->G = newCost;
	newNode->H = newNode->HeuristicDistance(*goalNode);

	for(unsigned int i = 0; i <openList.size(); i++)
	{
		if(Position == openList[i]->Position)
		{
			if(newNode->G < openList[i]->G)
			{
				delete openList[i];
				openList.erase(openList.begin()+i);
			}
			else
			{
				delete newNode;
				return;
			}
		}
	}
	openList.push_back(newNode);
}