#include "animations.h"

bool animations::game_over_anim (std::string display, short cord_x, short cord_y, short size, bool has_won)
{
	HANDLE output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cord;
	cord.X = 0;
	cord.Y = 0;
	short string_size = 2*size+2;
	int char_to_player_dist, char_cord, starting_position, num_of_frames;
	short sleep_time = 210.0/sqrt(size);
	if (has_won == false)
		num_of_frames = (int)sqrt((fmax(size-cord_x-1,cord_x)+1)*(fmax(size-cord_x-1,cord_x)+1)+(fmax(size-cord_y-1, cord_y)+1)*(fmax(size-cord_y-1, cord_y)+1))+4; // pitagoras - obliczanie odleg. od najdalszego rogu
	else num_of_frames = (int)(sqrt(fmax(size-cord_x-1,cord_x)*fmax(size-cord_y-1, cord_y)))+5;
	std::cout << display;
	for (int x = 0; x < num_of_frames; ++x)
	{
		if (has_won == false)
		starting_position = size*fmax(cord_y-x, 0)+fmax(cord_x-x, 0);
		else starting_position = fmax(cord_x-x, 0);
		for (int a = starting_position; a <= size*size; ++a)
		{
			char_to_player_dist = has_won?abs(a%size-cord_x)*abs(a/(size)-cord_y):abs(a%size-cord_x)*abs(a%size-cord_x)+abs(a/(size)-cord_y)*abs(a/(size)-cord_y);
			char_cord = (a/size)*(string_size)+string_size+a%size*2+1;
			if (char_to_player_dist <= abs(x-3)*(x-3))
				display[char_cord] = '_';
			else if (char_to_player_dist <= abs(x-2)*(x-2))
				display[char_cord] = char(176);
			else if (char_to_player_dist <= abs(x-1)*(x-1))
				display[char_cord] = char(178);
			else if (char_to_player_dist <= x*x)
				display[char_cord] = char(219);
		}
		Sleep (sleep_time);
		SetConsoleCursorPosition(output_handle, cord);
		std::cout << display;
	}
	SetConsoleTextAttribute(output_handle, has_won?BACKGROUND_GREEN:BACKGROUND_RED);
	std::string game_over = has_won?"\nCONGRATS, YOU'VE WON!":"\nGAME OVER, YOU SUCK..";
	for (short x = 0; x < game_over.length(); ++x)
	{
		std::cout << game_over[x];
		Sleep(59);
	}
	SetConsoleTextAttribute(output_handle, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
	return 0;
}
