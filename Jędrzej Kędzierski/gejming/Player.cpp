#include "Player.h"
#include <cstdlib>
#include <ctime>


bool Player::move(char command, int board_size_x, int board_size_y)
{
	if(command=='w')
	{
	if(coordinate_y!=0)
		coordinate_y--;
	}
	if(command=='a')
	{
		if(coordinate_x!=0)
			coordinate_x--;
	}
	if(command=='s')
	{
		if(coordinate_y!=board_size_y-1)
			coordinate_y++;
	}
	if(command=='d')
	{
		if(coordinate_x!=board_size_x-1)
			coordinate_x++;
	}
	
	return 0;
}

bool Player::move_enemy(int board_size_x, int board_size_y)
{
	srand(time(NULL));
	
	int command=rand()%4;
	
	if(command==0)
	{
	if(coordinate_y!=0)
		coordinate_y--;
	}
	if(command==1)
	{
		if(coordinate_x!=0)
			coordinate_x--;
	}
	if(command==2)
	{
		if(coordinate_y!=board_size_y-1)
			coordinate_y++;
	}
	if(command==3)
	{
		if(coordinate_x!=board_size_x-1)
			coordinate_x++;
	}
	
	return 0;
}
