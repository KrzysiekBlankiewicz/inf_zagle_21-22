#include <iostream>
#include "Board.h"


int main(int argc, char** argv) 
{
	Board board;
	
	int boardSize;
	std::cout << "Type in size of the board" << std::endl;
	std::cin >> boardSize;
	
	board.setUpGame(boardSize);
	
	board.displayBoard();
	
	board.play();
	
	return 0;
}
