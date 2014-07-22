#include "Map.h"

#include <cstdlib>


Map::Map(int x, int y, int t)
{
	Width = x;
	Height = y;

	//Everything is walkable(will be changed)
	for(unsigned int x = 0; x < MAX_MAP_WIDTH; ++x)
	{
		for(unsigned int y = 0; y < MAX_MAP_HEIGHT; ++y)
		{
			blocks[x][y] = Block();
		}
	}

	//Actual map construction
	for(unsigned int x = 0; x < Width; ++x)
	{
		for(unsigned int y = 0; y < Height; ++y)
		{
			blocks[x][y] = Block(std::rand() % 6);

		}
	}

	int R = std::rand() % 4;

	switch(R)
	{
	case 0:
		blocks[0][0].tiles[1][1] = TILE_BEGIN;
		blocks[Width-1][Height-1].tiles[1][1] = TILE_END;
		break;
	case 1:
		blocks[0][Height-1].tiles[1][1] = TILE_BEGIN;
		blocks[Width-1][0].tiles[1][1] = TILE_END;
		break;
	case 2:
		blocks[Width-1][0].tiles[1][1] = TILE_BEGIN;
		blocks[0][Height-1].tiles[1][1] = TILE_END;
		break;
	case 3:
		blocks[Width-1][Height-1].tiles[1][1] = TILE_BEGIN;
		blocks[0][0].tiles[1][1] = TILE_END;
		break;
	}
}

Map::Map()
{
	for(unsigned int x = 0; x < MAX_MAP_WIDTH; ++x)
	{
		for(unsigned int y = 0; y < MAX_MAP_HEIGHT; ++y)
		{
			blocks[x][y] = Block();
		}
	}
}


Map::~Map(void)
{
}