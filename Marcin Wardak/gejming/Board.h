#ifndef BOARD_H
#define BOARD_H
#include <cstdlib>
#include <iostream>
#include <set>
#include "Player.h"
#include "animations.h"

class Board
{
	public:
	int size;
	short win_cords;
	const static short enemy_number = 10;
	Player mainPlayer;
	Player enemy[enemy_number];
	animations anim_handling;
	
	bool set_up_game();
	bool gameplay();
	bool display_board();
	bool set_enemy_start_position();
	bool move_all_enemies();
	bool will_cover_sb(int cords, bool layout[], short x, bool enemies_left[]);
	bool can_move (int cords, bool layout[]);
	std::string which_directions_possible(short x, bool layout[], bool enemies_left[]);
};

#endif
