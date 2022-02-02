#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <conio.h>
using namespace std;

bool display_board (short a, short b, short size)
{
	if (a >= size || b >= size)
		return 1;
	system("CLS");
	for (short x = 0; x < size; x ++)
		cout << " _";
	for (short y = 0; y < size; y ++)
	{
		cout << "\n|";
		for (short x = 0; x < size; x ++)
			cout << ((y==b&&x==a)?'x':'_') << "|";
	}
	return 0;
}
int main(int argc, char** argv)
{
	srand(clock());
	short size, cord_x, cord_y;
	char command;
	cout << "wprowadz rozmiar planszy: ";
	cin >> size;
	cord_x = rand()%size;
	cord_y = rand()%size;
	display_board(cord_x, cord_y, size);
	while (true)
	{
		command = getch();
//		if (command == 'a')
//			display_board(--cord_x, cord_y, size);
//		if (command == 'w')
//			display_board(cord_x, --cord_y, size);
//		if (command == 's')
//			display_board(cord_x, ++cord_y, size);
//		if (command == 'd')
//			display_board(++cord_x, cord_y, size);
		if (command == 'a'&&cord_x)
			cord_x--;
		if (command == 'w'&&cord_y)
			cord_y--;
		if (command == 's'&&size-cord_y-1)
			cord_y++;
		if (command == 'd'&&size-cord_x-1)
			cord_x++;
		display_board(cord_x, cord_y, size);
	}
	return 0;
}
