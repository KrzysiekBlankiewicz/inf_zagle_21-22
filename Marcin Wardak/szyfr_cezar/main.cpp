#include <iostream>
#include <fstream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
string szyfrowanie (string slowo, short klucz, bool czy_zaszyfr)
{
	klucz %= 26; //26 - liczba liter w alfabecie
	klucz *= czy_zaszyfr?-1:1;
	for (short x = 0; x < slowo.length(); x ++)
	{
		if (slowo[x]+klucz>'Z' && !czy_zaszyfr)
			slowo[x]-=26;
		if (slowo[x]+klucz<'A' && czy_zaszyfr)
			slowo[x]+=26;
		slowo[x]+=klucz;
	}
	return slowo;
}
bool czy_zle (string slowo, string slowo_zakod)
{
	short klucz = slowo_zakod>slowo?slowo_zakod[0]-slowo[0]:26-slowo[0]+slowo_zakod[0];
	for (short x = 1; x < slowo.length(); x ++)
	{
		if (slowo[x]+klucz>'Z')
			slowo[x]-=26;
		if (slowo_zakod[x] - slowo[x] != klucz)
			return 1;
	}
	return 0;
}
int main(int argc, char** argv)
{
	fstream input ("dane_6_1.txt", ios::in);
	fstream output ("wyniki_6_1.txt", ios::out);
	string slowo, slowo_zakod;
	short klucz = 107;
	while (input >> slowo)
		output << szyfrowanie(slowo, klucz, false) << endl;
	input.close();
	output.close();
	input.open("dane_6_2.txt", ios::in);
	output.open("wyniki_6_2.txt", ios::out);				
	while (input>>slowo&&input>>klucz)
		output << szyfrowanie(slowo, klucz, true) << endl;
	input.close();
	output.close();
	input.open("dane_6_3.txt", ios::in);
	output.open("wyniki_6_3.txt", ios::out);
	while (input>>slowo&&input>>slowo_zakod)
		if (czy_zle(slowo, slowo_zakod))
			output << slowo << endl;
	input.close();
	output.close();
	return 0;
}
