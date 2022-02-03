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
	int numer, nine;
	float suma;
	fstream File;
	File.open("wyniki.txt", ios::in);
	
	while(!File.eof())
	{
		File>>numer;
		File>>dane;
		if(binarny(dane)==9)
		nine=numer;
		suma+=binarny(dane);
		
	}
	
	cout<<"Srednia wynosi "<<suma/10<<", a 9 okrazen pokonal zawodnik nr. "<<nine;
	
	return 0;
}
