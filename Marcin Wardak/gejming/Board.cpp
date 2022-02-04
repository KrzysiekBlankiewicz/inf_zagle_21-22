#include "Board.h"
#include <string>
bool Board::display_board(short cord_x, short cord_y, short size)
{
	if (cord_x >= size || cord_y >= size)
		return 1;							
	system("CLS");
	short string_size = 2*size+1; // szerokosc = 2*size+1 + nowa linia, wysokosc = 2*size+1
	std::string output ((string_size+1)*(size+1), '_');
	for (short x = 0; x < output.size(); x ++)
	{
		if ((x%(string_size+1))%2==0) // dodawanie spacji [pierwsza linijka] / œcian [reszta]
			output[x] = x/string_size?'|':' ';
		if (x%(string_size+1) == string_size) // dodawanie enterów
			output[x] = '\n';
	}
	output[(cord_y)*(string_size+1)+string_size+cord_x*2+2] = 'X'; // wyswietlanie playera
	for (short x = 0; x < enemy_number; x ++)
	{
		output[(enemy[x].cord_y)*(string_size+1)+string_size+enemy[x].cord_x*2+2] = 'O';
	}
	std::cout << output;
	return 0;
}

	bool Board::set_enemy_start_position()
	{
		for (short x = 0; x < enemy_number; x ++)
		{
			enemy[x].cord_x = rand()%(size);
			enemy[x].cord_y = rand()%(size-1);
		}
	}
