//You lost it!
#ifndef Game_H
#define Game_H


#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include "Scene.h"
#include "SearchNode.h"



class Game
{
public:
	Game(Scene *s,sf::RenderWindow *win);
	~Game(void);

	void Update();
	void Move();
	void Attack();
	void Attack(Enemy* e);
	void EnemyAttack(Enemy* e);
	float GetDistance(sf::Vector2<int> Playa,sf::Vector2<int> Beast);

	//Pathfinding
	SearchNode* getNextNode();
	std::vector<sf::Vector2<int>> FindPath(sf::Vector2<int> Start,sf::Vector2<int> End);
	std::vector<sf::Vector2<int>> FindPathReversed(sf::Vector2<int> Start,sf::Vector2<int> End);
	void clearVectors();
	void pathOpened(sf::Vector2<int> Position, float newCost,SearchNode* nextNode, SearchNode* goalNode);

	Scene *scene;

	sf::RenderWindow *window;

	sf::Clock clock;
	sf::Time DeltaTime;
	float MovementCD,MovementCDTimer;
	sf::Vector2<int> Pos;
	int level;

	//Components for pahtfinding
	std::vector<SearchNode*> openList;
	std::vector<SearchNode*> closedList;
	std::vector<sf::Vector2<int>> PathToGoal;
};
#endif