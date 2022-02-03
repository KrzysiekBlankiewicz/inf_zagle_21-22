#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool display_board(int s, int x, int y)
{
	if(x>=s ||y>=s)
	{
		return 1;
	}
	
	for(int i=0; i<s; i++)
	{
		cout<<" _";
	}
	
	cout<<endl;
	
	for(int i=0; i<s; i++)
	{
		for(int j=0; j<s; j++)
		{
			if(x==j && y==i)
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

int main(int argc, char** argv) {
	
	int size=10;//wielkosc planszy
	
	srand(time(NULL));
	
	int coordinate_x=rand()%size;
	int coordinate_y=size-1;
	
	display_board(size, coordinate_x, coordinate_y);
	
	char command;
	
	while(true)
	{
		cin>>command;
		
		if(command=='w')
		{
			if(coordinate_y!=0)
			{
				coordinate_y--;
			}
		}
		else if(command=='a')
		{
			if(coordinate_x!=0)
			{
				coordinate_x--;
			}
		}
		else if(command='d')
		{
			if(coordinate_x!=size-1)
			{
				coordinate_x++;
			}
		}
		else if(command='s')
		{
			if(coordinate_y!=size-1)
			{
				coordinate_y++;
			}
		}
		
		display_board(size, coordinate_x, coordinate_y);
	}
	
	return 0;
}
