#include <string>
#include <conio.h>
#include <windows.h>
#include "Board.h"

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
		if (!mainPlayer.move(command, size)) // jeœli player mo¿e poruszyæ siê w danym kierunku, to wyœwietl planszê
		{
			move_all_enemies();
			if (display_board()) // jeœli gra siê skoñczy
				return 0;
		}
		else Beep (220, 75); 	// w przeciwnym wypadku wydaj dŸwiêk
	}
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
		output[(enemy[x].cord_y)*(string_size)+string_size+enemy[x].cord_x*2+1] = char(x%10+48);
//	if (output[(mainPlayer.cord_y)*(string_size)+string_size+mainPlayer.cord_x*2+1] == 'O') // nastapienie na przeciwnika
//	{
//		output[(mainPlayer.cord_y)*(string_size)+string_size+mainPlayer.cord_x*2+1] = '*';
//		game_has_ended = 1; // informuje o koncu gry
//		output.append("\nGAME OVER");
//	}
//	else output[(mainPlayer.cord_y)*(string_size)+string_size+mainPlayer.cord_x*2+1] = 'X'; // wyœwietlanie gracza
	std::cout << output;
//	short licznik = 0;
//	for (short x=  0; x < output.length(); x ++)
//		if (output[x] == 'O')
//			++licznik;
//	std::cout << std::endl << licznik;
	return game_has_ended;
}

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
	bool layout[size*size];
	for (short x = 0; x < size; ++x)
		for (short y = 0; y < size; ++y)
			layout[y*size+x] = false;
	for (short x = 0; x < enemy_number; ++x)
	{
		std::cout << "NR: " << x << std::endl;
		std::string options = which_directions_possible(x, layout); // nie mog³em zrobiæ tablicy o zerowej d³ugoœci
		short decision = -1;
		if (options.length() > 0)					// Jeœli mo¿esz siê ruszyæ...
		{
			std::cout << "SA OPCJE\n";
			decision = rand()%options.length();
			enemy[x].move_enemy(options[decision]); // to to zrób
		}
		std::cout << "OPCJE: ";
		for (short a = 0; a < options.length(); a ++)
			//std::cout << (std::string)((options[a]==0)?"lewo":(options[a]==1?"gora":(options[a]==2?"prawo":(options[a]==3?"dol":"nic")))) << " " << (char)(options[a]+48);
			options[a] += 48;
		std::cout << options << "\nDECYZJA: " << (char)(decision+48) << (std::string)((options.length()>0)?((options[decision]==48)?"lewo":(options[decision]==49?"gora":(options[decision]==50?"prawo":(options[decision]==51?"dol":"nic")))):"nic") << std::endl;
		
		std::cout << "cords: " << enemy[x].cord_y*size+enemy[x].cord_x << std::endl;
		layout[enemy[x].cord_y*size+enemy[x].cord_x] = true;
		for (short a = 0; a < size; a ++)
		{
			for (short b = 0; b < size; b ++)
				std::cout << layout [a*size+b] << " ";
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}

bool Board::will_cover_sb(short cords, bool layout[], short x)
{
	if (x == enemy_number - 1)
	{std::cout << "ostatni przeciwnik\n";
	return false;} // jesli to juz ostatni przeciwnik, to na nikogo nie moze nastapic
	else std::cout << "cords " << cords << std::endl;
	for (short a = x+1; a < enemy_number; ++a)
	{
		std::cout << "cordsy przeciwnika: " << enemy[a].cord_y*size+enemy[a].cord_x << std::endl;
		if (enemy[a].cord_y*size+enemy[a].cord_x == cords) // jesli ktos tam siedzi
		{
			if (can_move(cords, layout) == false)
				return true;
		}
		if (cords/size != 0)
		{
			std::cout << "\tsprawdzanie gora gora\n";
			if (can_move(cords-size, layout) == false)
			{
				std::cout << "GÓRA ZABLOKUJE!\n";
				getch();getch();getch();
				return true;
			}
		}
		if (cords%size != 0)
		{
			std::cout << "\tsprawdzanie lewo lewo\n";
			if (can_move(cords-1, layout) == false)
			{
				std::cout << "LEWO ZABLOKUJE!\n";
				getch();getch();getch();
				return true;
			}
		}
		if (cords/size != size-1)
		{
			std::cout << "\tsprawdzanie dol dol\n";
			if (can_move(cords+size, layout) == false)
			{
				std::cout << "DOL ZABLOKUJE!\n";
				getch();getch();getch();
				return true;
			}
		}
		if (cords%size != size-1)
		{
			std::cout << "\tsprawdzanie prawo prawo\n";
			if (can_move(cords+1, layout) == false)
			{
				std::cout << "PRAWO ZABLOKUJE!\n";
				getch();getch();getch();
				return true;
			}
		}
		std::cout << std::endl;
	}
	return false;
}

bool Board::can_move (short cords, bool layout[])
{
	if (cords/size != 0)
		if (layout[cords-size] == false)
			return true;
	if (cords%size != 0)
		if (layout[cords-1] == false)
			return true;
	if (cords/size != size-1)
		if (layout[cords+size] == false)
			return true;
	if (cords%size != size-1)
		if (layout[cords+1] == false)
			return true;
	return false;
}
std::string Board::which_directions_possible(short x, bool layout[])
{
	std::string output = "";
	int cords = enemy[x].cord_y*size+enemy[x].cord_x;
	std::cout << "CORDS: " << cords << std::endl;
	if (enemy[x].cord_x != 0)
	{
		if (layout[cords-1] == false)
		{
			std::cout << "sprawdzanie lewo\n";
			layout [cords-1] = true;
			if (will_cover_sb (cords-1, layout, x) == false)
				output += (char)0;
			layout [cords-1] = false;
		}
		else std::cout << "przec lewo\n";
	}
	else std::cout << "sciana lewo\n";
	if (enemy[x].cord_y != 0)
	{
		if (layout[cords-size] == false)
		{
			std::cout << "sprawdzanie gora\n";
			layout [cords-size] = true;
			if (will_cover_sb (cords-size, layout, x) == false)
				output += (char)1;
			layout [cords-size] = false;
		}
		else std::cout << "przec gora\n";
	}
	else std::cout << "sciana gora\n";
	if (enemy[x].cord_x != size-1)
	{
		if (layout[cords+1] == false)
		{
			std::cout << "sprawdzanie prawo\n";
			layout [cords+1] = true;
			if (will_cover_sb (cords+1, layout, x) == false)
				output += (char)2;
			layout [cords+1] = false;
		}
		else std::cout << "przec prawo\n";
	}
	else std::cout << "sciana prawo\n";
	if (enemy[x].cord_y != size-1)
	{
		if (layout[cords+size] == false)
		{
			std::cout << "sprawdzanie dol\n";
			layout [cords+size] = true;
			if (will_cover_sb (cords+size, layout, x) == false)
				output += (char)3;
			layout [cords+size] = false;
		}
	}
	else std::cout << "sciana dol\n";
	return output;
}
