#ifndef PLAYER_H
#define PLAYER_H


class Player
{
	public:
	
	int coordinate_x;
	int coordinate_y;
	
	void move(char command,int board_size_x, int board_size_y);
};

#endif
