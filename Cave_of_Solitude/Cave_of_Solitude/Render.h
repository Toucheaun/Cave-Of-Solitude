#ifndef Render_H
#define Render_H

#include <SFML\Graphics.hpp>

#include "Scene.h"

class Render
{
public:
	Render(void);
	~Render(void);

	Scene *scene;
};
#endif