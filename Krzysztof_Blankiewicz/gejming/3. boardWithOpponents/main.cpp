#include <iostream>
#include "Board.h"


int main() 
{
	
	int boardSize;
	std::cout << "Type in size of the board" << std::endl;
	std::cin >> boardSize;
	
	Board board(boardSize);
	
	board.setUpGame();
	
	board.displayBoard();
	
	board.play();
	
	return 0;
}
