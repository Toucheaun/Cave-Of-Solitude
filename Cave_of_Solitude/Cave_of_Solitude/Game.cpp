#include "Game.h"
#include <SFML\Window.hpp>

Game::Game(Scene *s)
{
	scene = s;
}


Game::~Game(void)
{
}

void Game::Update()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) == true)
	{
		scene->player->Position.y--;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) == true)
	{
		scene->player->Position.y++;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) == true)
	{
		scene->player->Position.x--;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) == true)
	{
		scene->player->Position.x++;
	}
}