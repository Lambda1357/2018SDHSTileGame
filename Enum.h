#pragma once

enum MessageType {
	// 이동 관련 메시지
	E_MSG_MOVEPOS,
	E_MSG_SETPOS,

	// 객체 관련 메시지
	E_MSG_CREATE_OBJ,

	// 총, 총알 관련 메시지
	E_MSG_SHOOT,
};

enum EntityType {
	E_TYPE_OBJ,
	E_TYPE_UI
};

enum TileType {
	E_TEST_TILE
};