#include "Board.h"
#include <string>
bool Board::display_board(short cord_x, short cord_y, short size)
{
	if (cord_x >= size || cord_y >= size)
		return 1;							
	system("CLS");					//v1
	for (short x = 0; x < size; x ++)
		std::cout << " _";
	for (short y = 0; y < size; y ++)
	{
		std::cout << "\n|";
		for (short x = 0; x < size; x ++)
			std::cout << ((y==cord_y&&x==cord_x)?'X':'_') << "|";
	}

	std::cout << "\n\n";
	std::string output1 = "";										//v2
	for (short x = 0; x < size; x ++)
	{
		output1.append(" _");
	}
	for (short y = 0; y < size; y ++)
	{
		output1.append("\n|");
		for (short x = 0; x < size; x ++)
		{
			output1.push_back((char)((y==cord_y&&x==cord_x)?'X':'_'));
			output1.push_back('|');
		}
	}
	std::cout << output1;
	std::cout << "\n\n";
	short string_size = 2*size+1; // szerokosc = 2*size+1 + nowa linia, wysokosc = 2*size+1
	std::string output ((string_size+1)*(size+1), '_');
	for (short x = 0; x < output.size(); x ++)
	{
		if ((x%(string_size+1))%2==0) // dodawanie spacji [pierwsza linijka] / œcian [reszta]
			output[x] = x/string_size?'|':' ';
		if (x%(string_size+1) == string_size) // dodawanie enterów
			output[x] = '\n';
	}
	output[(cord_y)*(string_size+1)+string_size+cord_x*2+2] = 'X';
	std::cout << output;
	return 0;
}
