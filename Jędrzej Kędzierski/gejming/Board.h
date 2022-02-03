#ifndef BOARD_H
#define BOARD_H

#include "Player.h"

class Board
{
	public:
		
		int size_x;
		int size_y;
				
		Player my_player;
		
		bool display_board();
};

#endif
