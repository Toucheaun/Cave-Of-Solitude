//You lost it!
#ifndef Game_H
#define Game_H


#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include "Scene.h"
#include "SearchNode.h"
#include "SoundSystem.h"

//class SoundSystem;

class Game
{

public:
	Game(Scene *s,sf::RenderWindow *win, SoundSystem *ss);
	~Game(void);

private:

	SoundSystem *soundSystem;

public:

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
	Player *player;

	sf::RenderWindow *window;

	sf::Vector2<int> Pos;
	int level;

	//sound play timers
	sf::Clock clock;
	sf::Time DeltaTime;
	//float AmbientSound,AmbientSoundTimer;

	//Menu and point allocation
	void MouseControl();

	//Components for menu
	sf::Rect<int> Start;
	sf::Rect<int> Info;
	sf::Rect<int> Exit;
	sf::Rect<int> CharacterScreen;
	sf::Rect<int> Strength;
	sf::Rect<int> Dexterity;
	sf::Rect<int> Vitality;

	//Components for pahtfinding
	std::vector<SearchNode*> openList;
	std::vector<SearchNode*> closedList;
	std::vector<sf::Vector2<int>> PathToGoal;
};
#endif