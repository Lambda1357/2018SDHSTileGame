#pragma once

enum MessageType {
	// �̵� ���� �޽���
	E_MSG_MOVEPOS,
	E_MSG_SETPOS,

	// ��ü ���� �޽���
	E_MSG_CREATE_OBJ,

	// ��, �Ѿ� ���� �޽���
	E_MSG_SHOOT,
};

enum EntityType {
	E_TYPE_OBJ,
	E_TYPE_UI
};

enum TileType {
	E_TEST_TILE
};