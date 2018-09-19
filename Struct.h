#pragma once

typedef struct tagInfo
{
	D3DXVECTOR3 vPos;
	D3DXVECTOR3 vSize;
	string		sID;
} INFO;

typedef struct tagTileInfo
{
	// 타일의 좌표
	COORD Coordinate;
	
	bool  bCanPass;

	// 타일 사이즈
	static const INT tileSizeX = 100;
	static const INT tileSizeY = 100;
} TILE_INFO;