#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include "Player.h"
#include "Board.h"
using namespace std;

int main(int argc, char** argv)
{
	srand(time(NULL));
	Board board;
	board.set_up_game();
	board.gameplay();
    return 0;
}

