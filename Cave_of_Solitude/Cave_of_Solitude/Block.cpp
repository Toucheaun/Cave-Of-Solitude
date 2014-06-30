#include "Block.h"


Block::Block()
{
	for(unsigned int x = 0; x < BLOCK_WIDTH; x++)
	{
		for(unsigned int y = 0; y < BLOCK_HEIGHT; y++)
		{
			tiles[x][y] = TILE_FLOOR;
		}
	}

	for(unsigned int x = 0; x < BLOCK_WIDTH; x++)
	{
		tiles[x][0] = TILE_WALL;
	}
	for(unsigned int x = 0; x < BLOCK_WIDTH; x++)
	{
		tiles[BLOCK_HEIGHT-1][0] = TILE_WALL;
	}
	for(unsigned int y = 0; y < BLOCK_HEIGHT; y++)
	{
		tiles[0][y] = TILE_WALL;
	}
	for(unsigned int y = 0; y < BLOCK_HEIGHT; y++)
	{
		tiles[y][BLOCK_WIDTH-1] = TILE_WALL;
	}

	tiles[20][10] = TILE_FLOOR;
	tiles[10][20] = TILE_FLOOR;
	tiles[0][10] = TILE_FLOOR;
	tiles[10][0] = TILE_FLOOR;
}

Block::Block(int type)
{
	{
#define F  TILE_FLOOR
#define W  TILE_WALL
#define H  TILE_WALL_H
#define S  TILE_SPAWNER_S
#define M  TILE_SPAWNER_M
#define L  TILE_SPAWNER_L
#define T  TILE_SPAWNER_T
	switch(type)
	{
	case 0:
		{
		TileType t[21][21] =
		{
		{W,H,H,H,H,H,H,H,H,H,F,H,H,H,H,H,H,H,H,H,W},
		{W,F,F,F,F,F,F,F,F,F,F,W,F,F,S,F,F,F,F,F,W},
		{W,F,W,H,H,H,W,H,H,H,W,H,F,W,F,H,H,H,W,F,W},
		{W,F,H,F,F,F,W,F,F,F,W,F,F,W,F,F,F,F,W,F,W},
		{W,F,F,S,W,F,W,F,W,F,W,F,W,H,H,H,H,F,W,F,W},
		{W,H,H,H,W,F,W,F,W,F,W,F,W,F,F,F,F,F,W,M,W},
		{W,F,F,F,F,F,W,F,W,F,H,F,W,F,W,H,H,H,W,T,W},
		{W,F,W,F,W,H,H,F,W,F,F,F,W,F,W,S,F,F,W,W,W},
		{W,F,W,F,W,T,M,F,W,H,H,H,H,F,W,F,W,F,W,W,W},
		{W,F,W,F,H,H,H,H,H,F,F,F,F,F,F,F,W,F,H,H,W},
		{F,F,W,F,F,F,F,F,F,L,W,H,H,H,H,H,W,F,F,F,F},
		{W,H,H,H,H,H,H,H,W,F,W,S,F,F,F,F,W,H,H,H,W},
		{W,F,F,F,F,F,F,F,W,F,W,H,H,H,H,F,W,F,F,F,W},
		{W,F,W,H,H,H,W,F,W,F,W,F,F,F,F,F,W,F,W,F,W},
		{W,F,W,F,S,F,W,F,W,F,H,F,H,H,H,H,H,F,W,F,W},
		{W,F,W,F,W,F,F,F,W,F,F,F,F,F,S,F,F,F,W,F,W},
		{W,F,W,F,H,H,H,H,H,F,H,H,H,W,F,H,H,H,W,F,W},
		{W,F,W,F,F,F,F,F,F,F,F,F,F,W,F,F,F,F,W,F,W},
		{W,F,H,H,H,H,H,H,H,H,H,W,F,W,H,H,H,F,H,F,W},
		{W,F,F,F,F,F,F,F,F,F,F,W,F,F,F,F,F,F,F,F,W},
		{W,W,W,W,W,W,W,W,W,W,F,W,W,W,W,W,W,W,W,W,W}
		};
		CopyArray(t);
		}
		break;
	case 1:
		{
		TileType c[21][21] =
		{
		{W,H,H,H,H,H,H,H,H,H,F,H,H,H,H,H,H,H,H,H,W},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{W,W,W,W,W,W,W,W,W,W,F,W,W,W,W,W,W,W,W,W,W}
		};
		CopyArray(c);
		break;
		}
	case 2:
		{
		TileType v[21][21] =
		{
		{W,H,H,H,H,H,H,H,H,H,F,H,H,H,H,H,H,H,H,H,W},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{W,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,W},
		{W,W,W,W,W,W,W,W,W,W,F,W,W,W,W,W,W,W,W,W,W}
		};
		CopyArray(v);
		break;
		}
	default:
		Block();
		break;
	}
	}
}


Block::~Block(void)
{}

void Block::CopyArray(TileType t[BLOCK_WIDTH][BLOCK_HEIGHT])
{
	for(unsigned int x = 0; x < BLOCK_WIDTH; x++)
	{
		for(unsigned int y = 0; y < BLOCK_HEIGHT; y++)
		{
			tiles[x][y] = t[x][y];
		}
	}
}