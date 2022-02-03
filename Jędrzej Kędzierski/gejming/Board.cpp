#include "Board.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool Board::define_board()
{
	size_x=10;//wielkosc planszy (minimum 5) problem znikanie przeciwnika
	size_y=10;
	
	return 1;
}

bool Board::spawn_my_player()
{
	srand(time(NULL));
	
	my_player.coordinate_x=rand()%size_x;
	my_player.coordinate_y=size_y-1;
	
	return 1;
}

bool Board::spawn_enemy()
{
	srand(time(NULL));
	
	enemy.coordinate_x=rand()%size_x;
	enemy.coordinate_y=rand()%size_y-2;
	
	return 1;
}

bool Board::display_board()
{
	if(my_player.coordinate_x>=size_x ||my_player.coordinate_y>=size_y || my_player.coordinate_x<0 ||my_player.coordinate_y<0)
		return 1;
	
	system("CLS");
	
	for(int i=0; i<size_x; i++)
	{
		cout<<" _";
	}
	
	cout<<endl;
	
	bool not_game_over=1;
	
	for(int i=0; i<size_y; i++)
	{
		for(int j=0; j<size_x; j++)
		{
			if(my_player.coordinate_x==j && my_player.coordinate_y==i)
			{
				if(my_player.coordinate_x==enemy.coordinate_x && my_player.coordinate_y==enemy.coordinate_y)
				{
					cout<<"|*";
					not_game_over=0;
				}
				else
				{
					cout<<"|X";
				}
			}
			else if(enemy.coordinate_x==j && enemy.coordinate_y==i)
			{
				cout<<"|O";
			}
			else
			{
				cout<<"|_";
			}
		}
		
		cout<<"|"<<endl;
	}
	
	return not_game_over;
}
