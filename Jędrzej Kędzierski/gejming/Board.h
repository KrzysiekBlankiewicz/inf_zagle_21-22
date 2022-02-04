#ifndef BOARD_H
#define BOARD_H

#include "Player.h"

class Board
{
	public:
		
		int size_x;
		int size_y;
		const static int enemies_number=2;
				
		Player my_player;
		Player enemies[enemies_number];
		
		bool define_board();
		bool display_board();
		bool spawn_my_player();
		bool spawn_enemies();
		bool set_up_game();
		bool play();
};

#endif
