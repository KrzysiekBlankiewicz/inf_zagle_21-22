#include "Player.h"

bool Player::move (char command, short size)
{
	if (command == 'a'&&cord_x!=0)
	{
		cord_x--;
		return 0;
	}
	if (command == 'w'&&cord_y!=0)
	{
		cord_y--;
		return 0;
	}
	if (command == 's'&&size-1>cord_y)
	{
		cord_y++;
		return 0;
	}
	if (command == 'd'&&size-1>cord_x)
	{
		cord_x++;
		return 0;
	}
	return 1;
}

bool Player::move_enemy (short command, short size)
{
	switch (command)
	{
		case 0:
			cord_x--; break;
		case 1:
			cord_y--; break;
		case 2:
			cord_x++; break;
		case 3:
			cord_y++; break;
	}
	return 0;
}
