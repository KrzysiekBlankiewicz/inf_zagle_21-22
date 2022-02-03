#ifndef BOARD_H
#define BOARD_H
#include "Player.h"
#include <cstdlib>
#include <iostream>
class Board
{
	public:
	short size;
	Player mainPlayer;
	bool display_board(short cord_x, short cord_y, short size);
};

#endif
