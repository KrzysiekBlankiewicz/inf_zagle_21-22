#include <iostream>
#include <conio.h>
#include "Player.h"
#include "Board.h"

using namespace std;

int main(int argc, char** argv) {
	
	Board main_board;
	
	main_board.set_up_game();
	main_board.play();
	
	system("pause");
	
	return 0;
}
