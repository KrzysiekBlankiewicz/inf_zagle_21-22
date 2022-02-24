#include "Board.h"
#include <time.h>
#include <math.h>
#include <algorithm>
#include <iostream>

Board::Board(int requestedBoardSize): boardSize(requestedBoardSize)
{
}
	
void Board::displaySingleRaw()
{
	std::cout << "|";
	for(int i = 0; i < boardSize; ++i)
	{
		std::cout << "_|";
	}
	std::cout << std::endl;
}

void Board::displayTopRaw()
{
	for(int i = 0; i < boardSize; ++i)
	{
		std::cout << " _";
	}
	std::cout << std::endl;
}

void Board::displayBoard()
{
	displayTopRaw();
	
	for(int i = 0; i < boardSize; ++i)
	{
		if(i != player.y)
			displaySingleRaw();
		else
		{
			std::cout << "|";
			for(int j = 0; j < boardSize; ++j)
			{
				if(j != player.x)
					std::cout << "_|";
				else
					std::cout << "x|";
			}
			std::cout << std::endl;
		}
	}
	
}

void Board::setUpGame()
{
	std::srand(time(NULL));
	player.setPosition(std::rand()%boardSize, boardSize - 1);	// player always starts on lowest raw
	
	setOpponentPosition(0);
	setOpponentPosition(1);
}

void Board::setOpponentPosition(int id)
{
	
}

void Board::play()
{
	char nextMove;
	while(true)
	{
		std::cout << "Type direction [WASD] or x to exit" << std::endl;
		std::cin >> nextMove;

		if(nextMove == 'x')
			break;
					
		player.move(nextMove, boardSize);

		displayBoard();
	}
}
