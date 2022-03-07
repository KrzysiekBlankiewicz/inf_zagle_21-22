#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

bool czy_mniejsza(string liczba)
{	
	for(int i=0; i<liczba.length()-1; i++)
		if(liczba[i]>liczba[i+1])
			return false;
	
	return true;
}

int zamiana(string liczba)
{
	int suma;
	int potega=0;
	
	for(int i=liczba.length()-1; i>=0; i--)
	{
		suma+=pow(8,potega)*(liczba[i]-48);
		potega++;
	}
	return suma;
}

int main()
{
	string liczba;
	int licznik, cyfra, najw=0;
	fstream plik;
	plik.open("dane.txt", ios::in);
	
	while(!plik.eof())
	{
		plik>>liczba;
		if(czy_mniejsza(liczba)==true)
		{
			licznik++;
			cyfra=zamiana(liczba);
			if(cyfra>najw)
			najw=cyfra;
		}
	}
	
	cout<<licznik<<" "<<najw;
	
	return 0;
}
