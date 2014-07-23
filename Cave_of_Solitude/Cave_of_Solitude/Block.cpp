#include "Block.h"


Block::Block()
{
	for(unsigned int x = 0; x < BLOCK_WIDTH; x++)
	{
		for(unsigned int y = 0; y < BLOCK_HEIGHT; y++)
		{
			tiles[x][y] = TILE_WALL;
		}
	}
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
#define P  TILE_PILLAR
	switch(type)
	{
	case 0:
		{
		TileType b[21][21] =
		{
		{W,H,H,H,H,H,H,H,H,H,F,H,H,H,H,H,H,H,H,H,W},
		{W,F,F,F,F,F,F,F,F,F,F,W,F,F,S,F,F,F,F,F,W},
		{W,F,W,H,H,H,W,H,H,H,W,H,F,W,F,H,H,H,W,F,W},
		{W,F,H,F,F,F,W,F,F,F,W,F,F,W,F,F,F,F,W,F,W},
		{W,F,F,S,W,F,W,F,W,F,W,F,W,H,H,H,H,F,W,F,W},
		{W,H,H,H,W,F,W,F,W,F,W,F,W,S,F,F,F,F,W,M,W},
		{W,F,F,F,F,F,W,F,W,F,H,F,W,F,W,H,H,H,W,T,W},
		{W,F,W,F,W,H,H,F,W,F,F,F,W,F,W,S,F,F,W,W,W},
		{W,F,W,F,W,T,M,F,W,H,H,H,H,F,W,F,W,F,W,W,W},
		{H,F,W,F,H,H,H,H,H,F,F,F,F,F,F,F,W,F,H,H,H},
		{F,F,W,F,F,F,F,F,F,L,W,H,H,H,H,H,W,F,F,F,F},
		{W,H,H,H,H,H,H,H,W,F,W,S,F,F,F,F,W,H,H,H,W},
		{W,F,F,F,F,F,F,F,W,F,W,H,H,H,H,F,W,F,F,F,W},
		{W,F,W,H,H,H,W,F,W,F,W,F,F,F,F,F,W,F,W,F,W},
		{W,F,W,F,S,F,H,F,W,F,H,F,H,H,H,H,H,F,W,F,W},
		{W,F,W,F,W,F,F,F,W,F,F,F,F,F,S,F,F,F,W,F,W},
		{W,F,W,F,H,H,H,H,H,F,H,H,H,W,F,H,H,H,W,S,W},
		{W,F,W,F,F,F,F,F,F,F,F,F,F,W,F,F,F,F,W,F,W},
		{W,S,H,H,H,H,H,H,H,H,H,W,F,W,H,H,H,F,H,F,W},
		{W,F,F,F,F,F,F,F,F,F,F,W,F,F,F,F,F,F,F,F,W},
		{W,W,W,W,W,W,W,W,W,W,F,W,W,W,W,W,W,W,W,W,W}
		};
		CopyArray(b);
		}
		break;
	case 1:
		{
		TileType c[21][21] =
		{
		{W,H,H,H,W,H,H,H,H,H,F,W,H,H,H,H,H,H,W,H,W},
		{W,F,F,S,H,F,F,F,F,F,F,W,F,F,F,F,F,F,F,F,W},
		{W,F,W,F,F,F,W,H,W,H,F,W,F,W,F,H,W,F,P,M,W},
		{W,F,H,H,H,H,W,S,H,F,F,W,S,W,F,F,W,F,F,T,W},
		{W,F,F,F,F,F,W,F,F,F,W,W,H,H,W,F,W,H,H,H,W},
		{W,H,H,H,W,F,W,F,W,F,H,F,F,F,W,F,H,S,F,F,W},
		{W,F,F,F,W,F,W,F,W,F,F,F,W,F,W,F,F,F,W,F,W},
		{W,F,W,F,H,F,W,M,W,W,F,W,W,F,H,H,H,H,H,F,W},
		{W,F,W,F,S,F,W,T,W,H,F,H,W,F,F,F,F,F,F,F,W},
		{H,F,W,H,H,H,H,H,H,F,F,F,H,H,H,H,H,H,W,H,H},
		{F,F,W,F,F,F,F,F,F,F,P,L,F,F,F,F,F,F,W,F,F},
		{W,F,W,F,H,H,W,F,W,F,F,F,W,H,H,H,H,F,W,F,W},
		{W,F,W,F,S,F,W,F,H,W,F,W,H,F,M,T,W,F,W,F,W},
		{W,F,H,H,H,F,W,F,S,H,F,W,F,F,W,H,H,F,W,F,W},
		{W,F,F,F,F,F,W,W,F,F,F,W,F,H,W,F,F,F,W,F,W},
		{W,H,H,H,W,H,H,H,H,H,F,W,F,F,W,F,W,H,H,F,W},
		{W,F,F,F,H,F,F,F,F,F,F,W,H,F,W,F,H,F,F,F,W},
		{W,F,W,S,F,F,W,W,H,H,H,W,F,S,W,F,F,S,W,F,W},
		{W,F,H,H,H,H,H,H,F,F,F,W,F,H,H,H,H,H,H,F,W},
		{W,F,F,F,F,F,F,F,S,W,F,W,F,F,F,F,F,F,F,F,W},
		{W,W,W,W,W,W,W,W,W,W,F,W,W,W,W,W,W,W,W,W,W}
		};
		CopyArray(c);
		break;
		}
	case 2:
		{
		TileType v[21][21] =
		{
		{W,H,H,H,H,H,W,H,H,H,F,H,H,W,H,H,H,H,H,H,W},
		{W,F,F,F,F,F,W,F,F,F,F,F,F,W,F,F,F,F,F,F,W},
		{W,F,W,H,H,F,W,F,W,H,H,H,F,W,F,P,S,H,W,F,W},
		{W,F,W,F,F,F,W,F,W,F,F,F,F,W,F,F,F,F,W,F,W},
		{W,F,W,F,W,H,H,F,W,F,H,H,H,H,H,H,H,F,W,F,W},
		{W,F,W,F,H,F,F,F,W,S,F,F,F,F,F,F,F,F,H,F,W},
		{W,F,W,F,F,S,W,H,H,F,W,H,H,H,H,W,W,W,H,F,W},
		{W,F,H,H,W,H,H,F,F,F,W,F,F,F,F,W,H,H,H,F,W},
		{W,F,S,F,W,F,F,F,W,H,H,F,W,W,F,W,F,F,F,F,W},
		{H,H,W,F,W,F,W,H,H,F,F,F,W,T,M,W,S,W,H,H,H},
		{F,F,H,F,W,F,S,F,F,F,W,H,W,H,H,H,F,W,F,F,F},
		{W,F,F,F,W,H,H,H,H,H,W,L,F,F,F,F,F,W,F,H,W},
		{W,H,H,H,H,F,F,F,F,F,W,F,W,W,H,H,H,W,F,F,W},
		{W,F,F,F,F,S,W,H,H,F,W,F,W,W,F,F,F,W,W,F,W},
		{W,F,P,F,W,H,W,F,F,F,W,F,H,H,F,W,S,F,W,F,W},
		{W,F,F,F,W,F,W,F,W,F,F,F,F,F,F,W,W,F,W,F,W},
		{W,F,P,F,W,H,H,F,W,H,H,W,H,H,H,H,H,F,W,F,W},
		{W,F,M,F,W,S,F,F,W,F,F,W,F,F,F,F,F,F,W,F,W},
		{W,F,P,F,W,F,H,H,H,F,H,W,F,H,H,H,H,H,W,F,W},
		{W,T,F,F,W,F,F,F,F,F,F,W,F,F,F,F,S,F,F,F,W},
		{W,W,W,W,W,W,W,W,W,W,F,W,W,W,W,W,W,W,W,W,W}
		};
		CopyArray(v);
		break;
		}
	case 3:
		{
		TileType z[21][21] =
		{
		{W,H,H,H,H,H,W,H,H,H,F,H,H,W,H,H,H,H,H,H,W},
		{W,F,F,F,F,F,W,F,F,F,F,F,F,W,F,F,S,F,F,F,W},
		{W,F,P,M,P,F,W,F,W,H,H,H,F,W,F,W,H,H,W,F,W},
		{W,F,F,F,F,F,W,F,W,F,F,F,F,W,F,F,F,F,W,F,W},
		{W,F,W,F,W,H,H,F,W,F,H,H,H,H,H,H,H,F,W,F,W},
		{W,F,W,F,H,F,F,F,F,S,F,F,F,F,F,F,F,F,H,F,W},
		{W,F,W,F,F,S,W,H,H,F,W,H,H,H,H,W,W,W,H,F,W},
		{W,F,H,H,W,F,H,F,F,F,W,F,F,F,F,W,H,H,H,F,W},
		{W,F,S,F,W,F,F,F,W,H,H,F,W,W,F,W,F,F,F,S,W},
		{H,F,W,F,W,F,W,H,H,F,F,F,W,F,F,W,F,W,H,H,H},
		{F,F,W,F,W,F,F,F,F,F,W,H,W,F,H,H,F,W,F,F,F},
		{W,W,W,F,W,F,P,S,P,F,W,F,F,L,F,F,F,W,F,H,W},
		{W,F,F,F,W,F,F,F,F,F,W,F,W,F,H,H,H,W,F,F,W},
		{W,F,W,H,H,H,W,H,H,F,W,F,W,F,F,F,F,W,W,F,W},
		{W,F,W,F,S,F,W,F,F,F,W,F,H,H,F,W,F,H,W,F,W},
		{W,F,W,F,W,F,W,F,W,F,F,S,F,F,F,W,F,F,F,F,W},
		{W,F,W,F,W,F,W,F,W,H,F,W,H,H,H,H,H,F,H,H,W},
		{W,F,W,F,W,F,W,F,W,F,F,W,F,F,F,F,F,S,F,F,W},
		{W,F,H,F,W,F,H,F,W,F,H,H,F,W,H,H,H,H,H,F,W},
		{W,F,F,F,W,F,F,F,W,F,F,F,F,W,T,M,F,F,F,F,W},
		{W,W,W,W,W,W,W,W,W,W,F,W,W,W,W,W,W,W,W,W,W}
		};
		CopyArray(z);
		break;
		}
	case 4:
		{
		TileType x[21][21] =
		{
		{W,H,H,H,H,H,H,H,H,H,F,W,H,H,H,H,H,H,H,H,W},
		{W,F,F,F,F,F,S,F,F,F,F,W,F,F,F,F,F,F,F,F,W},
		{W,F,W,H,H,H,H,H,H,H,H,H,S,W,H,H,H,H,W,F,W},
		{W,F,W,F,F,F,F,F,F,F,F,F,F,W,M,F,F,F,W,F,W},
		{W,F,W,F,W,W,W,H,H,H,H,H,H,H,F,W,W,F,W,F,W},
		{W,F,W,F,H,H,W,F,F,F,F,F,F,F,F,W,W,F,W,S,W},
		{W,F,W,M,F,F,W,F,W,H,H,H,H,H,H,H,W,F,W,F,W},
		{W,F,H,H,W,F,W,F,W,F,F,F,F,F,F,F,W,F,W,F,W},
		{W,F,S,F,W,F,W,F,W,F,H,H,H,H,W,F,W,F,W,F,W},
		{H,H,W,F,W,F,W,F,W,F,F,F,F,F,W,F,W,F,W,F,H},
		{F,F,W,F,W,F,W,F,H,H,L,H,W,F,W,F,W,F,W,F,F},
		{W,F,W,F,W,F,W,F,F,F,F,F,W,F,W,F,W,F,H,H,W},
		{W,F,W,F,W,F,H,H,H,H,H,F,W,F,W,F,W,F,S,F,W},
		{W,F,W,F,W,F,F,F,F,F,F,F,W,F,W,F,H,H,W,F,W},
		{W,F,W,F,W,W,H,H,H,H,H,H,H,F,W,F,F,M,W,F,W},
		{W,S,W,F,W,W,F,F,F,F,F,F,F,F,W,W,W,F,W,F,W},
		{W,F,W,F,H,H,F,H,H,H,H,H,H,H,H,H,H,F,W,F,W},
		{W,F,W,F,F,F,M,W,F,F,F,F,F,F,F,F,F,F,W,F,W},
		{W,F,H,H,H,H,H,H,S,W,H,H,H,H,H,H,H,H,H,F,W},
		{W,F,F,F,F,F,F,F,F,W,F,F,F,F,F,S,F,F,F,F,W},
		{W,W,W,W,W,W,W,W,W,W,F,W,W,W,W,W,W,W,W,W,W}
		};
		CopyArray(x);
		break;
		}	case 5:
		{
		TileType n[21][21] =
		{
		{W,H,H,H,H,H,H,H,W,W,F,H,H,H,W,H,H,H,H,H,W},
		{W,F,F,F,F,F,F,F,H,H,F,F,F,F,W,F,F,F,F,F,W},
		{W,F,W,H,H,H,W,F,F,F,F,W,H,F,W,F,W,F,P,F,W},
		{W,F,W,F,S,F,W,H,H,H,W,W,S,F,W,F,W,F,F,F,W},
		{W,F,W,F,W,F,W,T,M,F,W,W,F,H,H,F,W,F,P,F,W},
		{W,F,H,F,W,F,H,H,W,F,W,W,F,F,F,F,W,F,F,F,W},
		{W,F,F,F,W,F,F,F,W,F,H,H,H,H,W,H,H,H,H,F,W},
		{W,H,H,H,W,H,H,F,W,F,F,F,F,F,W,F,F,F,F,F,W},
		{W,F,F,F,W,F,F,F,W,H,H,H,W,F,W,F,W,H,H,H,W},
		{H,F,W,F,W,F,W,F,W,F,F,F,W,F,W,F,W,F,F,F,H},
		{F,F,W,F,W,F,W,F,H,F,W,F,W,F,W,F,W,F,W,F,F},
		{W,H,H,F,W,F,W,F,S,F,W,F,H,F,H,F,W,F,H,H,W},
		{W,F,F,F,W,F,W,H,H,H,W,F,F,L,F,F,W,F,S,F,W},
		{W,F,P,S,H,F,W,F,F,F,W,H,H,H,H,F,H,H,H,F,W},
		{W,F,F,F,F,F,W,F,W,F,H,F,F,F,F,F,F,F,F,F,W},
		{W,H,H,H,W,H,H,F,W,F,S,F,W,H,H,H,H,H,W,F,W},
		{W,F,F,F,H,F,F,F,W,W,W,W,H,F,F,F,M,T,W,F,W},
		{W,F,W,F,S,F,W,H,H,H,W,W,F,F,W,H,H,H,W,F,W},
		{W,F,H,H,H,H,H,F,F,F,H,W,F,H,H,F,F,S,H,F,W},
		{W,F,F,F,F,F,F,S,W,F,F,W,F,F,F,F,W,F,F,F,W},
		{W,W,W,W,W,W,W,W,W,W,F,W,W,W,W,W,W,W,W,W,W}

		};
		CopyArray(n);
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
			tiles[x][y] = t[y][x];
		}
	}
}