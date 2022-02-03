#ifndef PLAYER_H
#define PLAYER_H


class Player
{
	public:
	
	int coordinate_x;
	int coordinate_y;
	
	bool move(char command,int board_size_x, int board_size_y);
	bool move_enemy(int board_size_x, int board_size_y);
};

#endif
