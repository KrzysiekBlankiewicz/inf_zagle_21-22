#ifndef BOARD_H
#define BOARD_H
#include "Player.h"

class Board
{
	public:
	int boardSize;
	Player player;
	
	void displayBoard();
	void displaySingleRaw();
	void displayTopRaw();
	void setUpGame(int requestedBoardSize);
	void play();
};

#endif
