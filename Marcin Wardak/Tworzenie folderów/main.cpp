#include <iostream>
#include "functions.h"
using namespace std;

int main()
{
	short option;
	cout << "Wybierz ponizsze opcje:\n"
	<< "1 - Nowa struktura plikow\n"
	<< "2 - Nowy projekt\n"
	<< "!={1, 2} - Wyjscie\n";
	cin >> option;
	while (option == 1 || option == 2)
	{
		if (option==1)
			cout << (new_structure()?"poprawnie utworzono strukture\n":"blad\n");
		else if (option==2)
			cout << (new_task()?"poprawnie dodano projekt\n":"blad\n");
		else cout << "???\n";
		cin >> option;
	}
		
	return 0;
}
