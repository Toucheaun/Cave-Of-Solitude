#ifndef Map_H
#define Map_H

#include "Block.h"

#define MAX_MAP_WIDTH 15
#define MAX_MAP_HEIGHT 15

class Map
{
public:
	Map(int x, int y, int t);
	Map();
	~Map(void);
	int Width, Height,Type;
	Block blocks[MAX_MAP_WIDTH][MAX_MAP_HEIGHT];
};
#endif