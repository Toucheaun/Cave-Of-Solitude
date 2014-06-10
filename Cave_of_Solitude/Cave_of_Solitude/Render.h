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

	//Map assets
	sf::Texture floor;
	sf::Sprite Floor;
};
#endif