#ifndef BOARD_H
#define BOARD_H

#include "Player.h"

class Board
{
	public:
		
		int size_x;
		int size_y;
				
		Player my_player;
		Player enemy;
		
		bool define_board();
		bool display_board();
		bool spawn_my_player();
		bool spawn_enemy();
		bool set_up_game();
		bool play();
};

#endif
