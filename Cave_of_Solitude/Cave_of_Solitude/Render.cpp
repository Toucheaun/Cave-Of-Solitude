#include "Render.h"


Render::Render(Scene* s)
{
	window.create(sf::VideoMode(800,600),"Cave of Solitude");
	scene = s;
	floor.loadFromFile("../Resources/StoneFloor64.png");
	Floor.setTexture(floor);
}

Render::~Render()
{}


void Render::Update()
{
	window.clear();

	//draw here
	for(unsigned int x = 0; x < MAX_MAP_WIDTH; ++x)
	{
		for(unsigned int y = 0; y < MAX_MAP_HEIGHT; ++y)
		{
			for(unsigned int x2 = 0; x2 < BLOCK_WIDTH; ++x2)
			{
				for(unsigned int y2 = 0; y2 < BLOCK_HEIGHT; ++y2)
				{
					
					switch(scene->getMap()->blocks[x][y].tiles[x2][y2])
					{
					case TILE_VOID:
						printf("Invalid tile type!");
						break;
					case TILE_FLOOR:
						Floor.setPosition(x2*64/*+x*15*64*/,y2*64/*+y*15*64*/);
						window.draw(Floor);
						break;
					case TILE_WALL:
						break;
					}

				}
			}
		}
	}


	window.display();
	if (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			window.close();
		}
	}
}