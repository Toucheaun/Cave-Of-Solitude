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
private:
	Scene *scene;
	sf::RenderWindow window;
	sf::View view;

	//Map assets
	sf::Texture floor;
	sf::Sprite Floor;

	sf::Texture wall;
	sf::Sprite Wall;

	//Enemy assets
	sf::Texture skeleton;
	sf::Sprite Skeleton;

	//Player assets
	sf::Texture player;
	sf::Sprite Player;
};
#endif