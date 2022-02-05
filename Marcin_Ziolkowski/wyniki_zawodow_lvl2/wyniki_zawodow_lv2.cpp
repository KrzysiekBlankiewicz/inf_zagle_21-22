#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int binarny(string kod)
{
	int suma=0;
	for(int i=(kod.length()-1); i>=0; i--)
	{
		int potegowanie;
		if(kod[i]=='1')
		suma+=pow((2*(kod[i]-48)), potegowanie);
		potegowanie++;
	}
	return suma;
}

int main()
{
	string dane;
	int numer, five;
	float suma;
	fstream File;
	File.open("wyniki.txt", ios::in);
	
	while(!File.eof())
	{
		File>>numer;
		File>>dane;
		if(binarny(dane)%5==0)
		five++;
		suma+=binarny(dane);
		
	}
	
	cout<<"Srednia wynosi "<<suma/10<<", a liczba zawodnikow ktorych okraznenia sa podzielne przez 5 jest "<<five;
	
	return 0;
}
