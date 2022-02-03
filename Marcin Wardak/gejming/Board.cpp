#include "Board.h"
#include <string>
bool Board::display_board(short cord_x, short cord_y, short size)
{
	if (cord_x >= size || cord_y >= size)
		return 1;
//	system("CLS");
//	for (short x = 0; x < size; x ++)
//		std::cout << " _";
//	for (short y = 0; y < size; y ++)
//	{
//		std::cout << "\n|";
//		for (short x = 0; x < size; x ++)
//			std::cout << ((y==cord_y&&x==cord_x)?'X':'_') << "|";
//	}
	std::string output [2*size+1] = "";
	system("CLS");
	for (short x = 0; x < size; x ++)
		output.push_back(' ');
		output.push_back('_');
	for (short y = 0; y < size; y ++)
	{
		std::cout << output << ("\n|");
		for (short x = 0; x < size; x ++)
		{
			std::output.push_back((char)((y==cord_y&&x==cord_x)?'X':'_'));
			std::string.push_back('|');
		}
	}
	std::cout << output;
	return 0;
}
