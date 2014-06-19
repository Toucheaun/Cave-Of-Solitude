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

	//Text assets
	sf::Font font;
	sf::Text text;
	sf::Text HP;
	sf::Text EXP;

	//Enemy assets
	sf::Texture skeleton;
	sf::Sprite Skeleton;

	//Player assets
	sf::Texture player;
	sf::Sprite Player;
};
#endif