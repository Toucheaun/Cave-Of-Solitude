#ifndef Render_H
#define Render_H

#include <SFML\Graphics.hpp>

#include "Scene.h"

class Render
{
public:
	Render(Scene *s);
	~Render(void);

	void Update();
	sf::RenderWindow* GetWindow();
private:
	Scene *scene;
	sf::RenderWindow window;
	sf::View view;

	//Map assets
	sf::Texture floor;
	sf::Sprite Floor;

	sf::Texture wall;
	sf::Sprite Wall;
	
	sf::Texture wall_H;
	sf::Sprite Wall_H;

	sf::Texture pillar;
	sf::Sprite Pillar;

	sf::Texture end;
	sf::Sprite End;

	sf::Texture treasure;
	sf::Sprite Treasure;

	//UI assets
	sf::Texture ui1;
	sf::Sprite UI1;

	sf::Texture ui2;
	sf::Sprite UI2;

	sf::Texture playerMenu;
	sf::Sprite PlayerMenu;

	sf::RectangleShape StartMenu;

	//Text assets
	sf::Font font;
	sf::Text text;
	sf::Text HP;
	sf::Text EXP;

	//Enemy assets
	sf::Texture zombie;
	sf::Sprite Zombie;

	sf::Texture skeleton;
	sf::Sprite Skeleton;
	
	sf::Texture wraith;
	sf::Sprite Wraith;

	sf::Texture goblin;
	sf::Sprite Goblin;
	
	sf::Texture orc;
	sf::Sprite Orc;
	
	sf::Texture troll;
	sf::Sprite Troll;

	sf::Texture dead;
	sf::Sprite Dead;

	//Player assets
	sf::Texture player;
	sf::Sprite Player;
};
#endif