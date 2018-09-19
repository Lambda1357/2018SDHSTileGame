#pragma once

typedef struct tagInfo
{
	D3DXVECTOR3 vPos;
	D3DXVECTOR3 vSize;
	string		sID;
} INFO;

typedef struct tagTileInfo
{
	// Ÿ���� ��ǥ
	COORD Coordinate;
	
	bool  bCanPass;

	// Ÿ�� ������
	static const INT tileSizeX = 100;
	static const INT tileSizeY = 100;
} TILE_INFO;