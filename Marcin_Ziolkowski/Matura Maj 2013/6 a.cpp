#include <iostream>
#include <fstream>
using namespace std;

bool pierwsza_i_ostatnia(string liczba)
{
	if(liczba[0]==liczba[liczba.length()-1])
	return true;
	
	return false;
}

int main()
{
	string liczba;
	int licznik;
	fstream plik;
	plik.open("dane.txt", ios::in);
	
	while(!plik.eof())
	{
		plik>>liczba;
		if(pierwsza_i_ostatnia(liczba)==true)
		licznik++;
	}
	
	cout<<licznik;
	
	return 0;
}
