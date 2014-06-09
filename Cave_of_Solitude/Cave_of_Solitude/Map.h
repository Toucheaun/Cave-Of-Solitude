#ifndef Map_H
#define Map_H

#include "Block.h"

class Map
{
public:
	Map(int x, int y);
	~Map(void);
	int Width, Height;
	Block blocks[Width][Height];
};
#endif
