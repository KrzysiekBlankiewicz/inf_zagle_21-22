#ifndef BOARD_H
#define BOARD_H
#include <cstdlib>
#include <iostream>
#include <set>
#include "Player.h"

class Board
{
	public:
	short size;
	const static short enemy_number = 6;
	Player mainPlayer;
	Player enemy[enemy_number];
	
	bool set_up_game();
	bool gameplay();
	bool display_board();
	bool set_enemy_start_position();
	bool move_all_enemies();
	bool will_cover_sb(short cords, bool layout[], short x);
	bool can_move (short cords, bool layout[]);
	std::string which_directions_possible(short x, bool layout[]);
};

#endif
