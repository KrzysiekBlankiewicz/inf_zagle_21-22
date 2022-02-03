#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

#include "Player.h"
#include "Board.h"

using namespace std;

int main(int argc, char** argv) {
	
	Board main_board;
	
	main_board.size_x=16;//wielkosc planszy
	main_board.size_y=16;
	
	srand(time(NULL));
	
	main_board.my_player.coordinate_x=rand()%main_board.size_x;
	main_board.my_player.coordinate_y=main_board.size_y-1;
	
	main_board.display_board();
	
	char command;
	
	while(true)
	{
		command=getch();
		
		main_board.my_player.move(command, main_board.size_x, main_board.size_y);
		
		main_board.display_board();
	}
	
	return 0;
}
