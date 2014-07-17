#include "Render.h"
#include <iostream>
#include <string>
#include <sstream>

Render::Render(Scene* s)
{
	window.create(sf::VideoMode(800,600),"Cave of Solitude");
	scene = s;
	floor.loadFromFile("../Resources/StoneFloor64.png");
	Floor.setTexture(floor);
	wall.loadFromFile("../Resources/StoneWall64.png");
	Wall.setTexture(wall);
	wall_H.loadFromFile("../Resources/StoneWallHorizontal.png");
	Wall_H.setTexture(wall_H);
	//Wall_H.scale(0.5f,0.5f);

	player.loadFromFile("../Resources/Player128.png");
	Player.setTexture(player);
	Player.setScale(0.5f,0.5f);

	zombie.loadFromFile("../Resources/zombie128.png");
	Zombie.setTexture(zombie);
	Zombie.setScale(0.5f,0.5f);

	skeleton.loadFromFile("../Resources/Skeleton128.png");
	Skeleton.setTexture(skeleton);
	Skeleton.setScale(0.5f,0.5f);

	wraith.loadFromFile("../Resources/Wraith128.png");
	Wraith.setTexture(wraith);
	Wraith.setScale(0.5f,0.5f);

	goblin.loadFromFile("../Resources/ScaledGoblinWithWeapon128.png");
	Goblin.setTexture(goblin);
	Goblin.setScale(0.5f,0.5f);

	orc.loadFromFile("../Resources/orc128.png");
	Orc.setTexture(orc);
	Orc.setScale(0.5f,0.5f);

	troll.loadFromFile("../Resources/TrollUnarmed128.png");
	Troll.setTexture(troll);
	Troll.setScale(0.5f,0.5f);

	dead.loadFromFile("../Resources/Grave128.png");
	Dead.setTexture(dead);
	Dead.scale(0.5f, 0.5f);

	ui1.loadFromFile("../Resources/Frame256x128.png");
	UI1.setTexture(ui1);

	ui2.loadFromFile("../Resources/FrameExample.png");
	UI2.setTexture(ui2);

	playerMenu.loadFromFile("../Resources/MenuBase.png");
	PlayerMenu.setTexture(playerMenu);

	//Text
	font.loadFromFile("../Resources/Gabriela-Regular.ttf");
	text.setFont(font);
	text.setColor(sf::Color::Red);

	HP.setFont(font);
	HP.setColor(sf::Color::Red);

	EXP.setFont(font);
	EXP.setColor(sf::Color::Green);
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
	for(unsigned int x = 0; x < TILEMAP_WIDTH; x++)
	{
		for(unsigned int y = 0; y < TILEMAP_HEIGHT; y++)
		{
			//std::cout<<"block:" <<x<<y<<"tile:"<<x2<<y2<<std::endl;
			switch(scene->getTileMap()->tiles[x][y])
			{
			case TILE_VOID:
				printf("Invalid tile type!");
				break;
			case TILE_FLOOR:
				//printf("Floor\n");
				Floor.setPosition(x*64,y*64+16);
				window.draw(Floor);
				break;
			case TILE_WALL:
				//printf("Wall\n");
				Wall.setPosition(x*64,y*64+16);
				window.draw(Wall);
				break;
			case TILE_WALL_H:
				Wall_H.setPosition(x*64,y*64+16);
				window.draw(Wall_H);
				break;
			case TILE_SPAWNER_S:
				//printf("Floor\n");
				Floor.setPosition(x*64,y*64+16);
				window.draw(Floor);
				break;
			case TILE_SPAWNER_M:
				//printf("Floor\n");
				Floor.setPosition(x*64,y*64+16);
				window.draw(Floor);
				break;
			case TILE_SPAWNER_L:
				//printf("Floor\n");
				Floor.setPosition(x*64,y*64+16);
				window.draw(Floor);
				break;
			}
		}
	}

	for(unsigned int i = 0; i < temp.size(); i++)
	{
		if(temp.at(i)->Alive)
		{
			switch(temp.at(i)->type)
			{
			case ZOMBIE:
				Zombie.setPosition(temp.at(i)->Position.x*64,temp.at(i)->Position.y*64);
				window.draw(Zombie);
				break;
			case SKELETON:
				Skeleton.setPosition(temp.at(i)->Position.x*64,temp.at(i)->Position.y*64);
				window.draw(Skeleton);
				break;
			case WRAITH:
				Wraith.setPosition(temp.at(i)->Position.x*64,temp.at(i)->Position.y*64);
				window.draw(Wraith);
				break;
			case GOBLIN:
				Goblin.setPosition(temp.at(i)->Position.x*64,temp.at(i)->Position.y*64);
				window.draw(Goblin);
				break;
			case ORC:
				Orc.setPosition(temp.at(i)->Position.x*64,temp.at(i)->Position.y*64);
				window.draw(Orc);
				break;
			case TROLL:
				Troll.setPosition(temp.at(i)->Position.x*64,temp.at(i)->Position.y*64);
				window.draw(Troll);
				break;
			}
		}
		else
		{
			Dead.setPosition(temp.at(i)->Position.x*64,temp.at(i)->Position.y*64);
			window.draw(Dead);
		}

	}

	//Player.setPosition(scene->player->Position.x*64,scene->player->Position.y*64);
	window.draw(Player);


	//UI Drawn on top of playables.

	UI2.setPosition(Player.getPosition().x+272,Player.getPosition().y+172);
	window.draw(UI2);

	UI1.setPosition(Player.getPosition().x-400,Player.getPosition().y+172);
	window.draw(UI1);

	//Texts writen on top
	HP.setPosition(Player.getPosition().x-380,Player.getPosition().y+195);
	std::stringstream ss;
	ss<<"Hp: "<<scene->player->Hp;
	HP.setString(ss.str());
	window.draw(HP);

	EXP.setPosition(Player.getPosition().x-380,Player.getPosition().y+235);
	std::stringstream exp;
	exp<<"Exp: "<<scene->player->Exp;
	EXP.setString(exp.str());
	window.draw(EXP);

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

sf::RenderWindow* Render::GetWindow()
{
	return &window;
}