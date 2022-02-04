#include "Board.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

bool Board::define_board()
{
	cout<<"Type in size of the board (min 4)"<<endl;
	cin>>size_x;
	size_y=size_x;//wielkosc planszy (minimum 4)
	
	return 1;
}

bool Board::spawn_my_player()
{
	my_player.coordinate_x=rand()%size_x;
	my_player.coordinate_y=size_y-1;//my_player pojawia sie w losowym miejscu, ale tylko w dolnym wierszu
	
	return 1;
}

bool Board::spawn_enemy()
{
	enemy.coordinate_x=rand()%size_x;
	enemy.coordinate_y=rand()%(size_y-2);//enemy pojawia sie oddalony od my_player o conajmniej dwa wiersze w gore
	
	return 1;
}

bool Board::spawn_enemies()
{
	for(int i=0; i<enemies_number; i++)
	{
		enemies[i].coordinate_x=rand()%size_x;
		enemies[i].coordinate_y=rand()%(size_y-2);//enemies pojawiaja sie oddaleni od my_player o conajmniej dwa wiersze w gore
	}
	
	return 1;
}

bool Board::display_board()
{
	if(my_player.coordinate_x>=size_x ||my_player.coordinate_y>=size_y || my_player.coordinate_x<0 ||my_player.coordinate_y<0)//useless
		return 1;
	
	system("CLS");
	
	cout<<"Type direction [WASD] or x to exit"<<endl;
	
	for(int i=0; i<size_x; i++)
	{
		cout<<" _";
	}
	
	cout<<endl;
	
	bool not_game_over=1;//wartosc prawda oznacza, ze gracz gra dalej, falsz - ze zginal
	
	for(int i=0; i<size_y; i++)
	{
		for(int j=0; j<size_x; j++)
		{
			if(my_player.coordinate_x==j && my_player.coordinate_y==i)//wyswietlanie my_player
			{
				if(my_player.coordinate_x==enemy.coordinate_x && my_player.coordinate_y==enemy.coordinate_y)//sprawdzenie czy na danej pozycji nie stoi enemy
				{
					cout<<"|*";
					not_game_over=0;
				}
				else
				{
					cout<<"|X";
				}
			}
			else if(enemy.coordinate_x==j && enemy.coordinate_y==i)//wyswietlanie enemy
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

bool Board::set_up_game()
{
	srand(time(NULL));
	
	define_board();
	spawn_my_player();
	spawn_enemy();
	spawn_enemies();
	display_board();
	
	return 1;
}

bool Board::play()
{
	char command;
	
	while(true)
	{
		command=getch();
		
		if(command=='x')
			break;
		
		my_player.move(command, size_x, size_y);
		enemy.move_enemy(size_x, size_y);
		
		if(display_board()==0)//jezeli gracz przegral (not_game_over==false)
		{
			cout<<"GAME OVER"<<endl;
			return 0;
		}
		else if(my_player.coordinate_y==0)//jezeli my_player stanal na koncowym wierszu
		{
			cout<<"WIN"<<endl;
			return 1;
		}
	}
	
	return 0;
}
