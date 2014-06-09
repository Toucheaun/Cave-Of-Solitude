#include "Map.h"


Map::Map(int x, int y)
{
	Width = x;
	Height = y;

	for(unsigned int x = 0; x < Width; ++x)
	{
		for(unsigned int y = 0; y < Height; ++y)
		{
			blocks[x][y] = Block();
		}
	}
}


Map::~Map(void)
{
}
