#include "TileMap.h"


TileMap::TileMap(int w, int h,int t)
{
	Width = w;
	Height = h;

	//Everything is wall
	for(int x = 0; x < TILEMAP_WIDTH; ++x)
	{
		for(int y = 0; y < TILEMAP_HEIGHT; ++y)
		{
			tiles[x][y] = TILE_WALL;
		}
	}

	Map m(Width, Height, t);

	for(unsigned int x = 0; x < MAX_MAP_WIDTH; ++x)
	{
		for(unsigned int y = 0; y < MAX_MAP_HEIGHT; ++y)
		{
			for(unsigned int x2 = 0; x2 < BLOCK_WIDTH; x2++)
			{
				for(unsigned int y2 = 0; y2 < BLOCK_HEIGHT; y2++)
				{
					tiles[x2+x*21][y2+y*21] = m.blocks[x][y].tiles[x2][y2];
				}
			}
		}
	}

	//random begin and end

	for(unsigned int x = 0; x < TILEMAP_WIDTH; x++)
	{
		tiles[x][0] = TILE_WALL;
	}
	for(unsigned int y = 0; y < TILEMAP_HEIGHT; y++)
	{
		tiles[0][y] = TILE_WALL;
	}
	for(unsigned int x = 0; x < TILEMAP_WIDTH; x++)
	{
		tiles[x][TILEMAP_WIDTH-1] = TILE_WALL;
	}
	for(unsigned int y = 0; y < TILEMAP_HEIGHT; y++)
	{
		tiles[TILEMAP_HEIGHT-1][y] = TILE_WALL;
	}
}

TileMap::TileMap()
{
	//Everything is wall
	for(int x = 0; x < TILEMAP_WIDTH; ++x)
	{
		for(int y = 0; y < TILEMAP_HEIGHT; ++y)
		{
			tiles[x][y] = TILE_WALL;
		}
	}
}


TileMap::~TileMap(void)
{
}
