#ifndef PLAYER_H
#define PLAYER_H

class Player
{
	public:
	short cord_x;
	short cord_y;
	bool move (char command, short size);
	bool move_enemy (short command, short size);
};

#endif
