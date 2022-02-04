#ifndef BOARD_H
#define BOARD_H
#include "Player.h"
#include <cstdlib>
#include <iostream>
class Board
{
	public:
	short size;
	const static short enemy_number = 5;
	Player mainPlayer;
	Player enemy[enemy_number];
	
	bool display_board(short cord_x, short cord_y, short size);
	bool set_enemy_start_position();
};

#endif
