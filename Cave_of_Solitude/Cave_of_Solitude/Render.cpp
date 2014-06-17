#include "Render.h"
#include <iostream>

Render::Render(Scene* s)
{
	window.create(sf::VideoMode(800,600),"Cave of Solitude");
	scene = s;
	floor.loadFromFile("../Resources/StoneFloor64.png");
	Floor.setTexture(floor);
	wall.loadFromFile("../Resources/StoneWall64.png");
	Wall.setTexture(wall);

	skeleton.loadFromFile("../Resources/Skeleton64.png");
	Skeleton.setTexture(skeleton);

	player.loadFromFile("../Resources/PlayerCharacter64.png");
	Player.setTexture(player);
}

Render::~Render()
{}


void Render::Update()
{
	window.clear();

	std::vector<Enemy*> temp = scene->enemies;

	Player.setPosition(scene->player->Position.x*64,scene->player->Position.y*64);
	view.reset(sf::FloatRect(0,0,800,600));
	view.setCenter(Player.getPosition());
	window.setView(view);

	//draw here
	for(unsigned int x = 0; x < MAX_MAP_WIDTH; ++x)
	{
		for(unsigned int y = 0; y < MAX_MAP_HEIGHT; ++y)
		{
			for(unsigned int x2 = 0; x2 < BLOCK_WIDTH; ++x2)
			{
				for(unsigned int y2 = 0; y2 < BLOCK_HEIGHT; ++y2)
				{
					//std::cout<<"block:" <<x<<y<<"tile:"<<x2<<y2<<std::endl;
					switch(scene->getMap()->blocks[x][y].tiles[x2][y2])
					{
					case TILE_VOID:
						printf("Invalid tile type!");
						break;
					case TILE_FLOOR:
						//printf("Floor\n");
						Floor.setPosition((x2*64)+(x*21*64),(y2*64)+(y*21*64));
						window.draw(Floor);
						break;
					case TILE_WALL:
						//printf("Wall\n");
						Wall.setPosition((x2*64)+(x*21*64),(y2*64)+(y*21*64));
						window.draw(Wall);
						break;
					}
				}
			}
		}
	}

	for(unsigned int i = 0; i < temp.size(); i++)
	{
		switch(temp.at(i)->type)
		{
		case SKELETON:
			Skeleton.setPosition(temp.at(i)->Position.x*64,temp.at(i)->Position.y*64);
			window.draw(Skeleton);
			break;
		}
	}

	//Player.setPosition(scene->player->Position.x*64,scene->player->Position.y*64);
	window.draw(Player);

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