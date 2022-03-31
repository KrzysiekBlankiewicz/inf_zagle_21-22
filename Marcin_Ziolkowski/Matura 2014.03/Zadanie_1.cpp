#include <iostream>
#include <fstream>
using namespace std;

int suma(string litery)
{
	int a, wynik=0;
	for(int i=0; i<litery.length(); i++)
	{
		a=(int)litery[i];
		wynik+=a;
		
	}
	return wynik;
}

bool czy_pierwsza(int pierwsza)
{
	for(int i=2; i<=pierwsza/2; i++)
	{
		if(pierwsza%i==0)
			return false;
	}
	return true;
}

int main()
{
	string litery;
	int pierwsza, ilosc=0;
	fstream plik;
	plik.open("NAPIS.txt", ios::in);
	
	while(!plik.eof())
	{
		plik>>litery;
		pierwsza=suma(litery);
		if(czy_pierwsza(pierwsza)==true)
			ilosc++;
	}
	
	plik.close();
	
	cout<<ilosc;
	
	return 0;
}
