#ifndef BOARD_H
#define BOARD_H
#include "Player.h"

class Board
{
	public:

	const static int numberOfEnemies = 2;
	int boardSize;
	char* content;
	Player player;
	Player enemies[numberOfEnemies];
	
	Board(int requestedBoardSize);
	void displayBoard();
	void displaySingleRaw();
	void displayTopRaw();
	void setUpGame();
	void setOpponentPosition(int id);
	void play();
};

#endif
