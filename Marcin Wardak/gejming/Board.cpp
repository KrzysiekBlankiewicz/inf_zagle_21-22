#include "Board.h"
#include <string>
bool Board::display_board(short cord_x, short cord_y, short size)
{
	bool game_has_ended = 0;
	if (mainPlayer.cord_x >= size || mainPlayer.cord_y >= size)
		return 1;							
	system("CLS");
	short string_size = 2*size+2; // szerokosc = 2*size+1 + nowa linia, wysokosc = 2*size+1
	std::string output ((string_size)*(size+1), '_');
	for (short x = 0; x < output.size(); x ++)
	{
		if ((x%(string_size))%2==0) // dodawanie spacji [pierwsza linijka] / �cian [reszta]
			output[x] = x/(string_size-1)?'|':' ';
		if (x%(string_size) == string_size-1) // dodawanie enter�w
			output[x] = '\n';
	}
	for (short x = 0; x < enemy_number; x ++) // wy�wietlanie przeciwnik�w
	{
		output[(enemy[x].cord_y)*(string_size)+string_size+enemy[x].cord_x*2+1] = 'O';
	}
	if (output[(mainPlayer.cord_y)*(string_size)+string_size+mainPlayer.cord_x*2+1] == 'O') // nastapienie na przeciwnika
	{
		output[(mainPlayer.cord_y)*(string_size)+string_size+mainPlayer.cord_x*2+1] = '*';
		game_has_ended = 1; // informuje o koncu gry
		output.append(game_over());
	}
	else output[(mainPlayer.cord_y)*(string_size)+string_size+mainPlayer.cord_x*2+1] = 'X'; // wy�wietlanie gracza
	std::cout << output;
	return game_has_ended;
}

bool Board::set_enemy_start_position()
{
	for (short x = 0; x < enemy_number; x ++)
	{
		enemy[x].cord_x = rand()%(size);
		enemy[x].cord_y = rand()%(size-1);
	}
	return 0;
}

bool Board::move_all_enemies()
{
	for (short x = 0; x < enemy_number; x ++)
	{
		if (enemy[x].cord_y == 0) // g�ra
		{
			if (enemy[x].cord_x== 0) // LG r�g - 2/3
				enemy[x].move_enemy(rand()%2+2, size);
			else if (enemy[x].cord_x == size-1) // PG r�g - 0/3
				enemy[x].move_enemy((rand()%2)*3, size);
			else
				enemy[x].move_enemy((rand()%3+2)%4, size); // G kraw�d� - 0/2/3
		}
		else if (enemy[x].cord_y == size-1) // d�
		{
			if (enemy[x].cord_x == 0) // LD r�g - 1/2
				enemy[x].move_enemy(rand()%2+1, size);
			else if (enemy[x].cord_x == size-1) // PD r�g - 0/1
				enemy[x].move_enemy(rand()%2, size);
			else
				enemy[x].move_enemy(rand()%3, size); // D kraw�d� - 0/1/2
		}
		else if (enemy[x].cord_x == 0) //lewo
			enemy[x].move_enemy(rand()%3+1, size); // L kraw�d� - 1/2/3
		else if (enemy[x].cord_x == size-1) //prawo
			enemy[x].move_enemy((rand()%3+3)%4, size); // P kraw�d� - 0/1/3
		else 								
			enemy[x].move_enemy(rand()%4, size); // z dala od kraw�dzi - 0/1/2/3
	}
	return 0;
}

std::string Board::game_over()
{
	return "\nGAME OVER";
}
