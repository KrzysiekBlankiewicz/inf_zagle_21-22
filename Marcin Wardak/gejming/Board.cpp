#include "Board.h"
#include <string>
#include <conio.h>
#include <windows.h>
#include <vector>
bool Board::set_up_game()
{
	std::cout << "wprowadz rozmiar planszy: ";
	while (std::cin >> size && enemy_number>size*(size-1))
		std::cout << "zbyt mala plansza\n";
	
	mainPlayer.cord_x = rand()%size;
	mainPlayer.cord_y = size-1;
	set_enemy_start_position();
	display_board();
	return 0;
}

bool Board::gameplay()
{
	char command;
	while (true)
	{
		command = getch();
		move_all_enemies();
		if (!mainPlayer.move(command, size)) // jeœli player mo¿e poruszyæ siê w danym kierunku, to wyœwietl planszê
		{
			if (display_board()) // jeœli gra siê skoñczy
			{
				getch();
				return 1;
			}
		}
		else Beep (220, 75); 				// w przeciwnym wypadku wydaj dŸwiêk
	}
	return 0;
}
bool Board::display_board()
{
	bool game_has_ended = 0;
	if (mainPlayer.cord_x >= size || mainPlayer.cord_y >= size)
		return 1;							
	//system("CLS");
	short string_size = 2*size+2; // szerokosc = 2*size+1 + nowa linia, wysokosc = 2*size+1
	std::string output ((string_size)*(size+1), '_');
	for (short x = 0; x < output.size(); x ++)
	{
		if ((x%(string_size))%2==0) // dodawanie spacji [pierwsza linijka] / œcian [reszta]
			output[x] = x/(string_size-1)?'|':' ';
		if (x%(string_size) == string_size-1) // dodawanie enterów
			output[x] = '\n';
	}
	for (short x = 0; x < enemy_number; x ++) // wyœwietlanie przeciwników
	{
		output[(enemy[x].cord_y)*(string_size)+string_size+enemy[x].cord_x*2+1] = (char)(x%10+48);
	}
	if (output[(mainPlayer.cord_y)*(string_size)+string_size+mainPlayer.cord_x*2+1] == 'O') // nastapienie na przeciwnika
	{
		output[(mainPlayer.cord_y)*(string_size)+string_size+mainPlayer.cord_x*2+1] = '*';
		game_has_ended = 1; // informuje o koncu gry
		output.append(game_over());
	}
	else output[(mainPlayer.cord_y)*(string_size)+string_size+mainPlayer.cord_x*2+1] = 'X'; // wyœwietlanie gracza
	std::cout << output;
	return game_has_ended;
}

//bool Board::set_enemy_start_position()
//{
//	for (short x = 0; x < enemy_number; x ++)
//	{
//		enemy[x].cord_x = rand()%(size);
//		enemy[x].cord_y = rand()%(size-1);
//	}
//	return 0;
//}

bool Board::set_enemy_start_position()
{
	short opt_left = size*(size-1);
	short current_number;
	std::set<short> chosen_ones;
	for (short x = 0; x < enemy_number; ++x)
	{
		current_number = rand()%opt_left;
		--opt_left;
		current_number += distance(chosen_ones.begin(), chosen_ones.lower_bound(current_number)); // ile przeciwnikow wczeœniej wylosowanych ma <= numer ni¿ on
		while (chosen_ones.insert(current_number).second==false) // jeœli ktoœ ju¿ siedzi na wylosowanym miejscu,
			++current_number;									 // przesuñ siê dalej
		current_number %= (size-1)*size; // tak na wszelki wypadek
		enemy[x].cord_x = current_number%size; // konwersja na wspó³rzêdne
		enemy[x].cord_y = current_number/size;
	}
	return 0; 
}

bool Board::move_all_enemies()
{
	bool layout[size][size];
	for (short x = 0; x < size; ++x)
		for (short y = 0; y < size; ++y)
			layout[x][y] = false;
	for (short x = 0; x < enemy_number; ++x)
	{
		std::cout << "nr: " << x;
		std::string options = which_directions_possible(x, layout, ); // nie mog³em zrobiæ tablicy o zerowej d³ugoœci
		short decision;
		if (options.length() > 0)
		{
			decision = options[rand()%options.length()];
			enemy[x].move_enemy(decision);
		}
		else decision = -1;
		std::cout << " decyzja: " << decision;
		std::cout << std::endl;
		layout[enemy[x].cord_x][enemy[x].cord_y] = true;
	}
}
//
//bool Board::will_block_someone(short x, bool &layout [size][size], short direction)
//{
//	switch (direction)
//	{
//		case 0:
//			for (cnt+=1; cnt < enemy_number; cnt ++)
//			{
//				if (enemy[x].cord_x - 1 == enemy[cnt].cord_x && enemy[x].cord_y == enemy[cnt].cord_y) // jeœli ktoœ ju¿ tam jest, a jeszcze siê nie ruszy³
//				{
//					if (layout[enemy[x].cord_x-1][enemy[x].cord_y-1]==1&&layout[enemy[x].cord_x-1][enemy[x].cord_y+1]==1&&layout[enemy[x].cord_x][enemy[x].cord_y]==1) // czy ktoœ otacza tamt¹ osobê
//					{
//						if (enemy[x].cord_x)
//					}
//				}
//			}
//		case 1:
//		case 2:
//		case 3:
//	}
//}
std::string Board::which_directions_possible(short x)
{
	std::string output = "";
	if (enemy[x].cord_x != 0) // je¿eli nie jest na krawêdzi
	{
		if (layout[enemy[x].cord_x-1][enemy[x].cord_y] == false) // je¿eli nie stoi tam ktoœ inny
			if (will_block_someone(x, &layout, 0) == false) // je¿eli ten ruch nie spowoduje nast¹pienia na zablokowanych graczy
				output += (char)0;
		else std::cout << " Problem: przeciwnik lewo ";
	}
	else std::cout << " Problem: sciana lewo ";
	if (enemy[x].cord_y != 0)
	{
		if (layout[enemy[x].cord_x][enemy[x].cord_y-1] == false)
			output += (char)1;
		else std::cout << " Problem: przeciwnik gora ";
	}
	else std::cout << " Problem: sciana gora ";
	if (enemy[x].cord_x != size-1)
	{
		if (layout[enemy[x].cord_x+1][enemy[x].cord_y] == false)
			output += (char)2;
		else std::cout << " Problem: przeciwnik prawo ";
	}
	else std::cout << " Problem: sciana prawo ";
	if (enemy[x].cord_y != size-1)
	{
		if (layout[enemy[x].cord_x][enemy[x].cord_y+1] == false)
			output += (char)3;
		else std::cout << " Problem: przeciwnik dol ";
	}
	else std::cout << " Problem: sciana dol ";
	return output;
}
std::string Board::game_over()
{
	return "\nGAME OVER";
}
