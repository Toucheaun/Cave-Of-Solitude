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

	for(unsigned int x = 0; x < BLOCK_WIDTH; ++x)
	{
		tiles[x][0] = TILE_WALL;
	}
	for(unsigned int x = 0; x < BLOCK_WIDTH; ++x)
	{
		tiles[BLOCK_HEIGHT][0] = TILE_WALL;
	}
	for(unsigned int y = 0; y < BLOCK_HEIGHT; ++y)
	{
		tiles[0][y] = TILE_WALL;
	}
	for(unsigned int y = 0; y < BLOCK_HEIGHT; ++y)
	{
		tiles[y][BLOCK_WIDTH] = TILE_WALL;
	}
}


Block::~Block(void)
{}
