#include "Map.h"


Map::Map(int x, int y)
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
			blocks[x][y] = Block();
		}
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