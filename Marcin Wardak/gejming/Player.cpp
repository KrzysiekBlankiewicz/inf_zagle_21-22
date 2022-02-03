#include "Player.h"

bool Player::move (char command, short size)
{
	if (command == 'a'&&cord_x!=0)
		cord_x--;
	if (command == 'w'&&cord_y!=0)
		cord_y--;
	if (command == 's'&&size-1>cord_y)
		cord_y++;
	if (command == 'd'&&size-1>cord_x)
		cord_x++;
	return 0;
}
