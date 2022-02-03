#include <iostream>
#include <conio.h>

#include "Player.h"
#include "Board.h"

using namespace std;

int main(int argc, char** argv) {
	
	Board main_board;
	
	main_board.define_board();
	main_board.spawn_my_player();
	main_board.spawn_enemy();
	main_board.display_board();
	
	char command;
	
	while(true)
	{
		command=getch();
		
		main_board.my_player.move(command, main_board.size_x, main_board.size_y);
		main_board.enemy.move_enemy(main_board.size_x, main_board.size_y);
		
		if(main_board.display_board()==0)
		{
			cout<<"GAME OVER"<<endl;
			return 0;
		}
	}
	
	return 0;
}
