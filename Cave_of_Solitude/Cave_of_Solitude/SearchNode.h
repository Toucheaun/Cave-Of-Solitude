#ifndef SEARCHNODE_H
#define SEARCHNODE_H

#include "Tile.h"
#include <SFML\System\Vector2.hpp>
#include <math.h>

struct SearchNode
{
	SearchNode* nextNode;

	sf::Vector2<int> Position;

	float G, H , T;

	SearchNode() : nextNode(0)
	{	}

	SearchNode(sf::Vector2<int> Pos,TileType t, SearchNode* Next = 0) : Position(Pos), nextNode(Next), G(0), H(0)
	{
		switch(t)
		{
		TILE_FLOOR:
			T = 1.0;
			break;
		TILE_SPAWNER_S:
			T = 1.0;
			break;
		TILE_SPAWNER_M:
			T = 1.0;
			break;
		TILE_SPAWNER_L:
			T = 1.0;
			break;
		TILE_SPAWNER_T:
			T = 1.0;
			break;
		TILE_WALL:
			T = INT_MAX;
			break;
		TILE_WALL_H:
			T = INT_MAX;
			break;
		TILE_PILLAR:
			T = INT_MAX;
			break;
		TILE_BEGIN:
			T = 1.0;
			break;
		TILE_END:
			T = 1.0;
			break;
		}
	}

	float GetF()
	{
		return G + H + T;
	}

	float HeuristicDistance(SearchNode &otherNode)
	{
		//return 0; <--- ???
		int x = abs(Position.x - otherNode.Position.x);
		int y = abs(Position.y - otherNode.Position.y);

		return (float)x+y; //manhattan
		//return (float)x+y + (1.414f - 2) * std::min(x,y); //diagonal
	}
};

#endif