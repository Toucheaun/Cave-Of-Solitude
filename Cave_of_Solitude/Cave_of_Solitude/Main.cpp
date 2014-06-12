#include <SFML\Graphics.hpp>

#include "Render.h"
#include "Game.h"


int main()
{
	
	Scene *scene = new Scene();
	Game g(scene);
	Render r(scene);

	for(;;)
	{
		scene->Update();
		g.Update();
		r.Update();
	}

	return 0;
}