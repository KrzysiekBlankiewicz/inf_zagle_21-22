#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <conio.h>
#include "Player.h"
#include "Board.h"

using namespace std;

int main(int argc, char** argv)
{
	srand(time(NULL));
	Board board;
	char command;
	cout << "wprowadz rozmiar planszy: ";
	cin >> board.size;
	board.mainPlayer.cord_x = rand()%board.size;
	board.mainPlayer.cord_y = rand()%board.size;
	board.display_board(board.mainPlayer.cord_x, board.mainPlayer.cord_y, board.size);
	while (true)
	{
		command = getch();
		board.mainPlayer.move(command, board.size);
		board.display_board(board.mainPlayer.cord_x, board.mainPlayer.cord_y, board.size);
	}
	return 0;
}
