#include <iostream>
#include <fstream>

using namespace std;

int deszyfracja(string slowo, string klucz);

int main()
{
	string klucz, slowo, odszyfrowane;
	fstream plik1;
	fstream plik2;
	
	plik1.open("tj.txt", ios::in);
	plik2.open("klucze1.txt", ios::in);
	
	while(!plik1.eof())
	{
		plik1>>slowo;
		plik2>>klucz;
		
		odszyfrowane=deszyfracja(slowo,klucz);
		
		
		
	}
	
	
	return 0;
}
