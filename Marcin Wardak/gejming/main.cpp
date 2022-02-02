#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
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
	while (true)
	{
		command = getchar();
		if ()
	}
	return 0;
}
