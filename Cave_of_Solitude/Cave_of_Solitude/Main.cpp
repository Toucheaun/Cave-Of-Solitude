#include <SFML\Graphics.hpp>

#include "Render.h"


int main()
{
	
	Scene *scene = new Scene();
	Render r(scene);

	for(;;)
	{
	r.Update();
	}

	return 0;
}