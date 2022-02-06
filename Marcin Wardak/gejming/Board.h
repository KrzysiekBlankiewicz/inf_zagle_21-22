#ifndef BOARD_H
#define BOARD_H
#include <cstdlib>
#include <iostream>
#include "Player.h"

class Board
{
	public:
	short size;
	const static short enemy_number = 10;
	Player mainPlayer;
	Player enemy[enemy_number];
	
	bool set_up_game();
	bool gameplay();
	bool display_board();
	bool set_enemy_start_position();
	bool move_all_enemies();
	std::string game_over();
};

#endif
