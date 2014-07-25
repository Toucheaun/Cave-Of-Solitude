#include "Render.h"
#include <iostream>
#include <string>
#include <sstream>

Render::Render(Scene* s)
{
	window.create(sf::VideoMode(800,600),"Cave of Solitude");
	scene = s;
	floor.loadFromFile("../Resources/Graphics/StoneFloor64.png");
	Floor.setTexture(floor);
	wall.loadFromFile("../Resources/Graphics/StoneWall64.png");
	Wall.setTexture(wall);
	wall_H.loadFromFile("../Resources/Graphics/StoneWallHorizontal.png");
	Wall_H.setTexture(wall_H);
	//Wall_H.scale(0.5f,0.5f);
	pillar.loadFromFile("../Resources/Graphics/Pillar128.png");
	Pillar.setTexture(pillar);
	Pillar.setScale(0.5f,0.5f);
	treasure.loadFromFile("../Resources/Graphics/TreasureChest128.png");
	Treasure.setTexture(treasure);
	Treasure.setScale(0.5f,0.5f);
	treasureOpened.loadFromFile("../Resources/Graphics/TreasureChestOpened128.png");
	end.loadFromFile("../Resources/Graphics/StairsDown128.png");
	End.setTexture(end);
	End.setScale(0.5f,0.5f);
	start.loadFromFile("../Resources/Graphics/StairsUp128.png");
	Start.setTexture(start);
	Start.setScale(0.5f,0.5f);

	apple.loadFromFile("../Resources/Graphics/Apple.png");
	Apple.setTexture(apple);

	player.loadFromFile("../Resources/Graphics/Player128.png");
	Player.setTexture(player);
	Player.setScale(0.5f,0.5f);

	zombie.loadFromFile("../Resources/Graphics/zombie128.png");
	Zombie.setTexture(zombie);
	Zombie.setScale(0.5f,0.5f);

	skeleton.loadFromFile("../Resources/Graphics/Skeleton128.png");
	Skeleton.setTexture(skeleton);
	Skeleton.setScale(0.5f,0.5f);

	wraith.loadFromFile("../Resources/Graphics/Wraith128.png");
	Wraith.setTexture(wraith);
	Wraith.setScale(0.5f,0.5f);

	goblin.loadFromFile("../Resources/Graphics/Goblin128.png");
	Goblin.setTexture(goblin);
	Goblin.setScale(0.5f,0.5f);

	orc.loadFromFile("../Resources/Graphics/orc128.png");
	Orc.setTexture(orc);
	Orc.setScale(0.5f,0.5f);

	troll.loadFromFile("../Resources/Graphics/TrollUnarmed128.png");
	Troll.setTexture(troll);
	Troll.setScale(0.5f,0.5f);

	dead.loadFromFile("../Resources/Graphics/Grave128.png");
	Dead.setTexture(dead);
	Dead.scale(0.5f, 0.5f);

	ui1.loadFromFile("../Resources/Graphics/Frame256x128.png");
	UI1.setTexture(ui1);

	ui2.loadFromFile("../Resources/Graphics/FrameExample2.png");
	UI2.setTexture(ui2);

	playerMenu.loadFromFile("../Resources/Graphics/Frame256x384.png");
	PlayerMenu.setTexture(playerMenu);
	PlayerMenu.setScale(1.07f,1.0f);

	pointAlloc.loadFromFile("../Resources/Graphics/+.png");
	PointAlloc.setTexture(pointAlloc);
	PointAlloc.setScale(0.5f,0.5f);

	startMenu.loadFromFile("../Resources/Graphics/StartMenu.png");
	StartMenu.setTexture(startMenu);

	//Text
	font.loadFromFile("../Resources/Graphics/Gabriela-Regular.ttf");
	text.setFont(font);
	text.setColor(sf::Color::Red);

	HP.setFont(font);
	HP.setColor(sf::Color::Red);

	EXP.setFont(font);
	EXP.setColor(sf::Color::Green);

	TextLines.setFont(font);
	TextLines.setColor(sf::Color::White);

	TextLines2.setFont(font);
	TextLines2.setColor(sf::Color::White);
	TextLines2.setScale(0.5f,0.5f);
}

Render::~Render()
{}


void Render::Update()
{
	window.clear();

	std::vector<Enemy*> temp = scene->enemies;
	std::vector<Chest*> temp2 = scene->chests;
	std::vector<Item*> temp3 = scene->items;

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
			case TILE_SPAWNER_T:
				Floor.setPosition(x*64,y*64+16);
				window.draw(Floor);
				break;
			case TILE_PILLAR:
				Pillar.setPosition(x*64,y*64+16);
				window.draw(Pillar);
				break;
			case TILE_BEGIN:
				Start.setPosition(x*64,y*64+16);
				window.draw(Start);
				break;
			case TILE_END:
				End.setPosition(x*64,y*64+16);
				window.draw(End);
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

	for(unsigned int i = 0; i < temp2.size(); i++)
	{
		if(temp2.at(i)->Open == true)
		{
			Treasure.setTexture(treasureOpened);
		}
		else
		{
			Treasure.setTexture(treasure);
		}
		Treasure.setPosition(temp2.at(i)->Position.x*64,temp2.at(i)->Position.y*64);
		window.draw(Treasure);
	}

	for(unsigned int i = 0; i < temp3.size(); i++)
	{
		switch(temp3.at(i)->type)
		{
		case SWORD:
			break;
		case ARMOR_1:
			break;
		case FOOD:
			Apple.setPosition(temp3.at(i)->Position.x*64+16, temp3.at(i)->Position.y*64+48);
			window.draw(Apple);
			break;
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
	HP.setPosition(Player.getPosition().x-380,Player.getPosition().y+185);
	std::stringstream ss;
	ss<<"Hp: "<<scene->player->Hp;
	HP.setString(ss.str());
	window.draw(HP);

	EXP.setPosition(Player.getPosition().x-380,Player.getPosition().y+220);
	std::stringstream exp;
	exp<<"Exp: "<<scene->player->Exp;
	EXP.setString(exp.str());
	window.draw(EXP);
	
	TextLines.setPosition(Player.getPosition().x-380,Player.getPosition().y+255);
	std::stringstream Text1;
	Text1<<"To level: "<< scene->player->ExpToLevel;
	TextLines.setString(Text1.str());
	window.draw(TextLines);

	if(scene->state == CHARACTER_SCREEN)
	{
		PlayerMenu.setPosition(Player.getPosition().x-400, Player.getPosition().y-250);
		window.draw(PlayerMenu);

		std::stringstream Text;
		Text<<"Strength: "<< scene->player->Str;
		TextLines.setPosition(Player.getPosition().x-380,Player.getPosition().y-205);
		TextLines.setString(Text.str());
		window.draw(TextLines);

		TextLines2.setPosition(Player.getPosition().x-380,Player.getPosition().y-160);
		TextLines2.setString("Strength increases your damage.");
		window.draw(TextLines2);

		std::stringstream Text1;
		Text1<<"Dexterity: "<< scene->player->Dex;
		TextLines.setPosition(Player.getPosition().x-380,Player.getPosition().y-105);
		TextLines.setString(Text1.str());
		window.draw(TextLines);
		TextLines2.setPosition(Player.getPosition().x-380,Player.getPosition().y-60);
		TextLines2.setString("Dexterity makes you faster.");
		window.draw(TextLines2);
		
		std::stringstream Text2;
		Text2<<"Vitality: "<< scene->player->Vit;
		TextLines.setPosition(Player.getPosition().x-380,Player.getPosition().y-5);
		TextLines.setString(Text2.str());
		window.draw(TextLines);
		TextLines2.setPosition(Player.getPosition().x-380,Player.getPosition().y+40);
		TextLines2.setString("Vitality increases your health.");
		window.draw(TextLines2);

		std::stringstream Text3;
		Text3<<"Points: "<< scene->player->Points;
		TextLines.setPosition(Player.getPosition().x-325,Player.getPosition().y+80);
		TextLines.setString(Text3.str());
		window.draw(TextLines);

		PointAlloc.setPosition(Player.getPosition().x-185, Player.getPosition().y-200);
		window.draw(PointAlloc);
		PointAlloc.setPosition(Player.getPosition().x-185, Player.getPosition().y-100);
		window.draw(PointAlloc);
		PointAlloc.setPosition(Player.getPosition().x-185, Player.getPosition().y);
		window.draw(PointAlloc);
	}

	if(scene->state == START_SCREEN)
	{
		StartMenu.setPosition(Player.getPosition().x-400,Player.getPosition().y-300);
		window.draw(StartMenu);
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

sf::RenderWindow* Render::GetWindow()
{
	return &window;
}