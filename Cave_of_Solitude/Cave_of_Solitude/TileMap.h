#ifndef TleMap_H
#define TileMap_H

#include "Map.h"

#define TILEMAP_WIDTH 315
#define TILEMAP_HEIGHT 315

class TileMap
{
public:
	TileMap(int w, int h,int t);
	TileMap();
	~TileMap(void);

	int Width, Height, Type;
	TileType tiles[TILEMAP_WIDTH][TILEMAP_WIDTH];
};
#endif