#include "Board.h"
#include <iostream>

using namespace std;

bool Board::display_board()
{
	if(my_player.coordinate_x>=size_x ||my_player.coordinate_y>=size_y || my_player.coordinate_x<0 ||my_player.coordinate_y<0)
	{
		return 1;
	}
	
	system("CLS");
	
	for(int i=0; i<size_x; i++)
	{
		cout<<" _";
	}
	
	cout<<endl;
	
	for(int i=0; i<size_y; i++)
	{
		for(int j=0; j<size_x; j++)
		{
			if(my_player.coordinate_x==j && my_player.coordinate_y==i)
			{
				cout<<"|X";
			}
			else
			{
				cout<<"|_";
			}
		}
		
		cout<<"|"<<endl;
	}
	
	return 0;
}
