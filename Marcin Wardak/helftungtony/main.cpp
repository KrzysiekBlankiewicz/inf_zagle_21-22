#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

double dlugosc (int pokolenie)
{
	if (pokolenie == 1)
		return 3.5;
	return 2.0/3 * dlugosc (pokolenie-1);
}

int main(int argc, char** argv)
{
	srand (time(NULL));
	string input;
	short counter;
	cin >> input;
	cout << "pewnie poprawnie\n";
	counter = rand()%10;
	cout << counter << endl;
	cout << dlugosc (counter);
	return 0;
}\
