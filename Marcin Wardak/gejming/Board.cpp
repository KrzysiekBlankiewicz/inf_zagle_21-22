#include <string>
#include <conio.h>
#include <windows.h>
#include "Board.h"

bool Board::set_up_game()
{	
	std::cout << "wprowadz ilosc przeciwnikow: ";
	while (!(std::cin >> enemy_number))
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "nieprawidlowa ilosc\n";
	}
	enemy = new Player[enemy_number];
	std::cout << "wprowadz rozmiar planszy: ";
	do
	{
		if (!(std::cin >> size))
		{
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cout << "nieprawidlowa ilosc\n";
			continue;
		}
		if ((int)(size*(size-1))>INT_MAX)
			std::cout << "zbyt duza plansza\n";
		else if (enemy_number>size*(size-1)-1)
			std::cout << "zbyt mala plansza\n";
		else break;
	} while (true);
	
	system("CLS");
	mainPlayer.cord_x = rand()%size;
	mainPlayer.cord_y = size-1;
	win_cords = (rand()%(size<3?1:size/3)+1)*(size*2+2) + rand()%size*2+1; // koordynaty mety
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
	return 0;
}

bool Board::display_board()
{
	bool game_has_ended = 0;
	if (mainPlayer.cord_x >= size || mainPlayer.cord_y >= size)
		return 1;
	COORD cord;
	cord.X = 0;
	cord.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord); // kursor na (0, 0)
	short string_size = 2*size+2; // szerokosc = 2*size+1 + nowa linia, wysokosc = 2*size+1
	std::string output ((string_size)*(size+1), '_');
	for (int x = 0; x < output.size(); x ++)
	{
		if ((x%(string_size))%2==0) // dodawanie spacji [pierwsza linijka] / œcian [reszta]
			output[x] = x/(string_size-1)?'|':' ';
		if (x%(string_size) == string_size-1) // dodawanie enterów
			output[x] = '\n';
	}
	for (short x = 0; x < enemy_number; x ++) // wyœwietlanie przeciwników
		output[(enemy[x].cord_y)*(string_size)+string_size+enemy[x].cord_x*2+1] = 'O';
	if (output[(mainPlayer.cord_y)*(string_size)+string_size+mainPlayer.cord_x*2+1] == 'O') // nastapienie na przeciwnika
	{
		output[(mainPlayer.cord_y)*(string_size)+string_size+mainPlayer.cord_x*2+1] = '*';
		game_has_ended = 1; // informuje o koncu gry
	}
	else 
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		output[(mainPlayer.cord_y)*(string_size)+string_size+mainPlayer.cord_x*2+1] = 'X'; // wyœwietlanie gracza
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

	if (output[win_cords] == 'X') // jeœli gra zakoñczy³a siê wygran¹
	{
		anim_handling.game_over_anim (output, mainPlayer.cord_x, mainPlayer.cord_y, size, true);
		return 1;
	}
	else output[win_cords] = char(219);
	if (game_has_ended == true) // jeœli gra zakonczy³a siê przegran¹
		anim_handling.game_over_anim (output, mainPlayer.cord_x, mainPlayer.cord_y, size, false);
	else std::cout << output;
	return game_has_ended;
}

bool Board::set_enemy_start_position()
{
	int opt_left = size*(size-1);
	int current_number;
	std::set<int> chosen_ones;
	chosen_ones.insert(win_cords/(size*2+2)*size-size+(win_cords%(size*2+2)-1)/2);  // blokujemy koordynaty mety dla spawnuj¹cych siê przeciwników
	--opt_left; 																	// jako ¿e meta zajmuje ju¿ jedno miejsce, musimy zmniejszyæ liczbê miejsc dostêpnych
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
	bool layout[size*size], enemies_left[size*size];
	for (short x = 0; x < size; ++x)
		for (short y = 0; y < size; ++y)
		{
			layout[y*size+x] = false;
			enemies_left[y*size+x] = false;
		}
	layout[win_cords/(size*2+2)*size-size+(win_cords%(size*2+2)-1)/2] = true; // blokujemy koordynaty mety
	for (short x = 0; x < enemy_number; ++x)
		enemies_left[enemy[x].cord_y*size+enemy[x].cord_x] = true;
	for (short x = 0; x < enemy_number; ++x)
	{
		std::string options = which_directions_possible(x, layout, enemies_left); // nie mog³em stworzyc tablicy o zerowej d³ugoœci
		short decision;
		if (options.length() > 0)					// Jeœli mo¿esz siê ruszyæ...
		{
			decision = rand()%options.length(); // ruch bierzemy z dostêpnych opcji - ze zmiennej options
			enemy[x].move_enemy(options[decision]); // to to zrób
		}
		layout[enemy[x].cord_y*size+enemy[x].cord_x] = true;
	}
}

bool Board::will_cover_sb(int cords, bool layout[], short x, bool enemies_left[])
{
	if (enemies_left[cords] == true && can_move(cords, layout) == false) 			// jesli ktos tam jest i nie moze sie ruszyc
		return true;
	if (cords/size != 0 && enemies_left[cords-size] == 1 && can_move(cords-size, layout) == false) // jesli ktos nad nami jest i naszym ruchem go zablokujemy
		return true;
	if (cords%size != 0 && enemies_left[cords-1] == 1 && can_move(cords-1, layout) == false) // jesli ktos na lewo od nas jest i naszym ruchem go zablokujemy
		return true;
	if (cords/size != size-1 && enemies_left[cords+size] == 1 && can_move(cords+size, layout) == false) // pod nami
		return true;
	if (cords%size != size-1 && enemies_left[cords+1] == 1 && can_move(cords+1, layout) == false) // na prawo
		return true;
	return false;
}

bool Board::can_move (int cords, bool layout[])
{
	if (cords/size != 0 && layout[cords-size] == false)
		return true;
	if (cords%size != 0 && layout[cords-1] == false)
		return true;
	if (cords/size != size-1 && layout[cords+size] == false)
		return true;
	if (cords%size != size-1 && layout[cords+1] == false)
		return true;
	return false;
}
std::string Board::which_directions_possible(short x, bool layout[], bool enemies_left[])
{
	std::string output = "";
	int cords = enemy[x].cord_y*size+enemy[x].cord_x;
	enemies_left[enemy[x].cord_y*size+enemy[x].cord_x] = false;
	if (enemy[x].cord_x != 0 && layout[cords-1] == false)
	{
		layout [cords-1] = true; // chwilowo oznaczamy sprawdzane miejsce jako zajete, co ulatwia sprawdzenie czy kogos blokujemy
		if (will_cover_sb (cords-1, layout, x, enemies_left) == false)
			output += (char)0; // jesli wszystkie warunki sa spelnione, do opcji dodajemy ten kierunek
		layout [cords-1] = false;
	}
	if (enemy[x].cord_y != 0 && layout[cords-size] == false)
	{
		layout [cords-size] = true;
		if (will_cover_sb (cords-size, layout, x, enemies_left) == false)
			output += (char)1;
		layout [cords-size] = false;
	}
	if (enemy[x].cord_x != size-1 && layout[cords+1] == false)
	{
		layout [cords+1] = true;
		if (will_cover_sb (cords+1, layout, x, enemies_left) == false)
			output += (char)2;
		layout [cords+1] = false;
	}
	if (enemy[x].cord_y != size-1 && layout[cords+size] == false)
	{
		layout [cords+size] = true;
		if (will_cover_sb (cords+size, layout, x, enemies_left) == false)
			output += (char)3;
		layout [cords+size] = false;
	}
	return output;
}
