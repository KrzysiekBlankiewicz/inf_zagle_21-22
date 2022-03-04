#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

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

bool pierwsza_i_ostatnia(int liczba)
{
	int najw=liczba;
	while(najw>=10)
	{
		najw/=10;
	}
	if((liczba%10)==najw)
	return true;
	
	return false;
}

int main()
{
	int cyfra;
	string liczba;
	int licznik=0;
	fstream plik;
	plik.open("dane.txt", ios::in);
	
	while(!plik.eof())
	{
		plik>>liczba;
		cyfra=zamiana(liczba);
		if(pierwsza_i_ostatnia(cyfra)==true)
			licznik+=1;
	}
	
	cout<<licznik;
	
	return 0;
}
