#include "Player.h"

bool Player::move(char direction, int boardSize)
{
	if(direction == UP)
		if(y == 0)
			return false;
		else
			--y;
	if(direction == DOWN)
		if(y == boardSize - 1)
			return false;
		else
			++y;		
	if(direction == RIGHT)
		if(x == boardSize - 1)
			return false;
		else
			++x;
	if(direction == LEFT)
		if(x == 0)
			return false;
		else
			--x;
	return true;
}

void Player::setPosition(int newX, int newY)
{
	x = newX;
	y = newY;
}
