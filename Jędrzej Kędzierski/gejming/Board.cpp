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
	system("CLS");
	
	cout<<"Type direction [WASD] or x to exit"<<endl;
	
	char map[size_x][size_y];
	bool not_game_over=1;//wartosc prawda oznacza, ze gracz gra dalej, falsz - ze zginal
	
	for(int i=0; i<size_y; i++)//zapelnianie mapy pozycjami "_"
	{
		for(int j=0; j<size_x; j++)
		{
			map[j][i]='_';
		}
	}
	map[my_player.coordinate_x][my_player.coordinate_y]='X';//oznaczanie pozycji my_player
	
	for(int i=0; i<enemies_number; i++)
	{
		if(map[enemies[i].coordinate_x][enemies[i].coordinate_y]=='X')//sprawdzenie czy na danej pozycji nie stoi enemy i my_player
		{
			map[enemies[i].coordinate_x][enemies[i].coordinate_y]='*';
			not_game_over=0;
		}
		else
			map[enemies[i].coordinate_x][enemies[i].coordinate_y]='O';//oznaczanie pozycji enemy
	}
	
	for(int i=0; i<size_x; i++)
	{
		cout<<" _";
	}
	
	cout<<endl;
	
	for(int i=0; i<size_y; i++)
	{
		for(int j=0; j<size_x; j++)
		{
			cout<<"|"<<map[j][i];
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
		
		for(int i=0; i<enemies_number; i++)
		{
			enemies[i].move_enemy(size_x, size_y);
		}
		
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
