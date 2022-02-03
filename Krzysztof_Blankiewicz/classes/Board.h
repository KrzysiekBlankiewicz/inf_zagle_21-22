#ifndef BOARD_H
#define BOARD_H
#include "Player.h"

class Board
{
	public:
	int sizeX;
	int sizeY;
	Player player;
	Player opponent;
	
	void draw();
};

#endif
