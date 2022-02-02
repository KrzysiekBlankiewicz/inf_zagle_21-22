#include <iostream>
#include <fstream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
string szyfrowanie (string slowo, short klucz)
{
	klucz %= 26; //26 - liczba liter w alfabecie
	for (short x = 0; x < slowo.length(); x ++)
	{
		if (slowo[x]+klucz>'Z')
			slowo[x]-=26;
		slowo[x]+=klucz;
	}
	return slowo;
}
int main(int argc, char** argv)
{
	fstream input ("dane_6_1.txt", ios::in);
	string slowo;
	while (input >> slowo)
		cout << szyfrowanie(slowo, 107) << endl;
	return 0;
}
