#pragma once

typedef struct tagInfo
{
	D3DXVECTOR3 vPos;
	D3DXVECTOR3 vSize;
	string		sID;
} INFO;

typedef struct tagTileInfo
{
	struct ICOORD
	{
		int X;
		int Y;
	};
	// Ÿ���� ��ǥ
	ICOORD Coordinate;
	
	bool  bCanPass;
	bool  bIsInScreen;

	// Ÿ�� ������
	static const INT tileSizeX = 260;
	static const INT tileSizeY = 130;
} TILE_INFO;