#include "Block.h"


Block::Block()
{
	for(unsigned int x = 0; x < BLOCK_WIDTH; ++x)
	{
		for(unsigned int y = 0; y < BLOCK_HEIGHT; ++y)
		{
			tiles[x][y] = TILE_FLOOR;
		}
	}
}


Block::~Block(void)
{}
