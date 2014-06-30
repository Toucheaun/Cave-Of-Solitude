#ifndef Tile_H
#define Tile_H

enum TileType
{
	TILE_VOID = 0,
	TILE_FLOOR,
	TILE_WALL,
	TILE_SPAWNER_S,
	TILE_SPAWNER_M,
	TILE_SPAWNER_L
};

#define TILE_SPAWNER_S Spawner
#define TILE_SPAWNER_M Spawner
#define TILE_SPAWNER_L Spawner

#endif