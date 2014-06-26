#ifndef Block_H
#define Block_H

#include "Tile.h"

#define BLOCK_WIDTH 21
#define BLOCK_HEIGHT 21

#define TILE_WIDTH 64
#define TILE_HEIGHT 64

class Block
{
public:
	Block();
	Block(int type);
	~Block(void);
	void CopyArray(TileType t[BLOCK_WIDTH][BLOCK_HEIGHT]);

	TileType tiles[BLOCK_WIDTH][BLOCK_HEIGHT];
};
#endif