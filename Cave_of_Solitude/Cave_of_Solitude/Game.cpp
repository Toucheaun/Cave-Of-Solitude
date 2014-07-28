#include "Game.h"
#include <SFML\Window.hpp>
#include <iostream>

#include "SoundSystem.h"

Game::Game(Scene *s, sf::RenderWindow *win, SoundSystem *ss)
{
	soundSystem = ss;
	scene = s;
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
	
	soundSystem->menu.setLoop(true);
	soundSystem->menu.play();
	soundSystem->inGame.setLoop(true);

	sf::Vector2<int> WinPos = win->getPosition();

	Start = sf::Rect<int>(WinPos.x+300,WinPos.y+250,200,100);
	Info = sf::Rect<int>(WinPos.x+300,WinPos.y+350,200,100);

	CharacterScreen = sf::Rect<int>(WinPos.x+690,WinPos.y+500,110,72);
	InGameExit = sf::Rect<int>(WinPos.x+690,WinPos.y+572,110,82);
	Strength = sf::Rect<int>(WinPos.x+223,WinPos.y+127,33,33);
	Dexterity = sf::Rect<int>(WinPos.x+223,WinPos.y+225,33,33);
	Vitality = sf::Rect<int>(WinPos.x+223,WinPos.y+325,33,33);
}


Game::~Game(void)
{
}

void Game::Update()
{
	player = scene->player;

	if(scene->state == GAME || scene->state == CHARACTER_SCREEN)
	{
		soundSystem->menu.stop();


		Pos = player->Position;

		if(scene->End == Pos)
		{
			scene->NewLevel();
		}

		if(player->Hp <= 0)
		{
			scene->state = START_SCREEN;
			scene->NewGame();
			soundSystem->inGame.stop();
			soundSystem->menu.play();
		}

		Move();

		Attack();

		std::vector<Enemy*> Temp = scene->enemies;
		std::vector<Item*> Temp2 = scene->items;

		for(unsigned int i = 0; i<Temp.size(); i++)
		{
			switch(Temp.at(i)->CurrentState.state)
			{
			case GUARD:
				if(GetDistance(player->Position,Temp.at(i)->Position) < 10)
				{
					Temp.at(i)->CurrentState.SetNewState(CHASE);
				}
			break;
			case CHASE:
				if(Temp.at(i)->Alive != false)
				{
					if(GetDistance(player->Position,Temp.at(i)->Position) < 2)
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
					}
				}
				break;
			}
			Temp.at(i)->Update();
		}
	}
	else if(scene->state == INFO_SCREEN)
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			scene->state = START_SCREEN;
		}
	}
	else
	{
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		scene->SetNewState(START_SCREEN);
		soundSystem->inGame.stop();
		soundSystem->menu.play();
	}
	scene->player->Update();

	MouseControl();

}

void Game::Attack(Enemy* e)
{
	if(e != NULL)
	{
		e->HP -= player->Dam;
		std::cout<<e->HP<<std::endl;
	}
}

void Game::EnemyAttack(Enemy* e)
{
	player->Hp -= e->DAM;
	e->ATTACK_CD_TIMER = 0;
	soundSystem->playerGetHit.play();
	if(player->Hp <= 0)
	{
		soundSystem->playerDeath.play();
	}
}

float Game::GetDistance(sf::Vector2<int> Playa,sf::Vector2<int> Beast)
{
	float result = std::sqrt(((float)Playa.x-Beast.x)*(Playa.x-Beast.x)+(Playa.y-Beast.y)*(Playa.y-Beast.y));
	return result;
}

void Game::Move()
{
	std::vector<Enemy*> Temp = scene->enemies;
	std::vector<Item*> Temp2 = scene->items;
	bool walkable = true;

	if(player->MovementCDTimer > player->MovementCD)
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) == true)
		{
			if(scene->CheckWalkable(sf::Vector2<int>(Pos.x,Pos.y-1)) == true)
			{
				for(unsigned int i = 0; i < Temp.size(); i++)
				{
					if(Temp.at(i)->Position == sf::Vector2<int>(Pos.x,Pos.y-1) &&  Temp.at(i)->Alive != false)
					{
						walkable = false;
					}
				}
				if(walkable == true)
				{
				player->Position.y--;
				soundSystem->playerStep.play();
				}
			}
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) == true)
		{
			if(scene->CheckWalkable(sf::Vector2<int>(Pos.x,Pos.y+1)) == true)
			{

				for(unsigned int i = 0; i < Temp.size(); i++)
				{
					if(Temp.at(i)->Position == sf::Vector2<int>(Pos.x,Pos.y+1) &&  Temp.at(i)->Alive != false)
					{
						std::cout<<Temp.at(i)->Position.x<<Temp.at(i)->Position.y;
						walkable = false;
					}
				}
				if(walkable == true)
				{
				player->Position.y++;
				soundSystem->playerStep.play();
				}
			}	

		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) == true)
		{
			if(scene->CheckWalkable(sf::Vector2<int>(Pos.x-1,Pos.y)) == true)
			{
				for(unsigned int i = 0; i < Temp.size(); i++)
				{
					if(Temp.at(i)->Position == sf::Vector2<int>(Pos.x-1,Pos.y) &&  Temp.at(i)->Alive != false)
					{
						walkable = false;
					}
				}
				if(walkable == true)
				{
				player->Position.x--;
				soundSystem->playerStep.play();
				}
			}

		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) == true)
		{
			if(scene->CheckWalkable(sf::Vector2<int>(Pos.x+1,Pos.y)) == true)
			{
				for(unsigned int i = 0; i < Temp.size(); i++)
				{
					if(Temp.at(i)->Position == sf::Vector2<int>(Pos.x+1,Pos.y) &&  Temp.at(i)->Alive != false)
					{
						walkable = false;
					}
				}
				if(walkable == true)
				{
				player->Position.x++;
				soundSystem->playerStep.play();
				}
			}
		}
		player->MovementCDTimer = 0;
	}

	for(unsigned int i = 0; i < Temp2.size(); i++)
	{
		if(Temp2.at(i)->Position == Pos)
		{
			scene->player->PickItem(Temp2.at(i));
			Temp2.at(i)->Position = sf::Vector2<int>(-500,-500);
		}
	}
}

void Game::Attack()
{
	//Melee attack with mouse attack
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i WinPos = sf::Mouse::getPosition(*window);
		sf::Vector2<int>P = scene->player->Position;
		if(scene->GetEnemyByPos(sf::Vector2<int>(WinPos.x/64-6+P.x,WinPos.y/64-5+P.y)) != NULL)
		{
			Enemy* Target = scene->GetEnemyByPos(sf::Vector2<int>(WinPos.x/64-6+P.x,WinPos.y/64-5+P.y));
			if(GetDistance(P,Target->Position) < 2)
			{
				if(player->AttackCDTimer > player->AttackCD)
				{
					Target->HP -= player->Dam;
					if(Target->HP >= 0)
					{
						switch(Target->type)
						{
						case ZOMBIE: 
							soundSystem->zombieGetHit.play();
							if(Target->Alive &&
								Target->HP <= 0)
							{
								player->Exp += Target->EXP;
								soundSystem->zombieDeath.play();
							}
							break;
							case SKELETON: 
							soundSystem->skeletonGetHit.play();
							if(Target->Alive &&
								Target->HP <= 0)
							{
								player->Exp += Target->EXP;
								soundSystem->skeletonDeath.play();
							}
							break;
							case WRAITH: 
							soundSystem->wraithGetHit.play();
							if(Target->Alive &&
								Target->HP <= 0)
							{
								player->Exp += Target->EXP;
								soundSystem->wraithDeath.play();
							}
							break;
							case GOBLIN: 
							soundSystem->goblinGetHit.play();
							if(Target->Alive &&
								Target->HP <= 0)
							{
								player->Exp += Target->EXP;
								soundSystem->goblinDeath.play();
							}
							break;
							case ORC: 
							soundSystem->orcGetHit.play();
							if(Target->Alive &&
								Target->HP <= 0)
							{
								player->Exp += Target->EXP;
								soundSystem->orcDeath.play();
							}
							break;
							case TROLL: 
							soundSystem->trollGetHit.play();
							if(Target->Alive &&
								Target->HP <= 0)
							{
								player->Exp += Target->EXP;
								soundSystem->trollDeath.play();
							}
							break;
						}
					}
					player->AttackCDTimer = 0;
				}
			}
		}
		if(scene->GetChestByPos(sf::Vector2<int>(WinPos.x/64-6+P.x,WinPos.y/64-5+P.y)) != NULL)
		{
			if(GetDistance(P,scene->GetChestByPos(sf::Vector2<int>(WinPos.x/64-6+P.x,WinPos.y/64-5+P.y))->Position) < 2)
			{
				if(scene->GetChestByPos(sf::Vector2<int>(WinPos.x/64-6+P.x,WinPos.y/64-5+P.y))->Open == false)
				{
					scene->SpawnItem(scene->GetChestByPos(sf::Vector2<int>(WinPos.x/64-6+P.x,WinPos.y/64-5+P.y))->type,scene->GetChestByPos(sf::Vector2<int>(WinPos.x/64-6+P.x,WinPos.y/64-5+P.y))->Position);
					scene->GetChestByPos(sf::Vector2<int>(WinPos.x/64-6+P.x,WinPos.y/64-5+P.y))->Open = true;
				}
			}

		}
	}
}

void Game::MouseControl()
{
	if(scene->state == START_SCREEN)
	{
		if(Start.contains(sf::Mouse::getPosition()) == true)
			{
				if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					scene->state = GAME;
					soundSystem->inGame.play();
				}
			}
			if(Info.contains(sf::Mouse::getPosition()) == true)
			{
				if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					scene->state = INFO_SCREEN;
				}
			}
	}
	else if(scene->state == GAME || scene->state == CHARACTER_SCREEN)
	{
		if(scene->state == CHARACTER_SCREEN)
		{
			if(CharacterScreen.contains(sf::Mouse::getPosition()) == true)
				{
					if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						scene->state = GAME;
					}
				}
			if(player->Points > 0)
			{
				if(Strength.contains(sf::Mouse::getPosition()) == true)
					{
						if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							player->Str++;
							player->Points--;
						}
					}
				if(Dexterity.contains(sf::Mouse::getPosition()) == true)
					{
						if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							player->Dex++;
							player->Points--;
						}
					}
				if(Vitality.contains(sf::Mouse::getPosition()) == true)
					{
						if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							player->Vit++;
							player->Points--;
						}
					}
			}
			}
		else if(scene->state == GAME)
		{
			if(CharacterScreen.contains(sf::Mouse::getPosition()) == true)
			{
				if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					scene->state = CHARACTER_SCREEN;

				}
			}
		}
		if(InGameExit.contains(sf::Mouse::getPosition()) == true)
		{
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				scene->state = START_SCREEN;
				scene->NewGame();
				soundSystem->inGame.stop();
				soundSystem->menu.play();
			}
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
		scene->GetTileByPos(Position) == TILE_WALL_H ||
		scene->GetTileByPos(Position) == TILE_PILLAR)
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