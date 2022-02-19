#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int dziesietny(string liczba, int dlugosc)
{
	int wynik=0, x=0;
	for(int i=dlugosc-1; i>=0; i--)
	{
		if(liczba[i]=='1')
		{
			wynik+=pow(2,x);
		}
		x++;
	}
	return wynik;
}

string sumabinarna(int suma)
{
	string zapis, wynik;
	
	do{
		if(suma%2==0)
			zapis+='0';
		else
			zapis+='1';
		suma/=2;
	}while(suma>0);

	for(int i=zapis.length()-1; i>=0; i--)
	{
		wynik+=zapis[i];
	}
	
	return wynik;
}

int main()
{
	string liczba, najwieksza2, nazwa;
	int dlugosc, parzyste, najwieksza10=0, suma=0, ile9;
	fstream File;
	File.open("liczby.txt", ios::in);
	
	while(!File.eof())
	{
		File>>liczba;
		dlugosc=liczba.length();
		if(liczba[dlugosc-1]=='0')
		parzyste++;
		int wynik = dziesietny(liczba, dlugosc);
		if(wynik>najwieksza10)
		{
			najwieksza10=wynik;
			najwieksza2=liczba;			
		}
		if(dlugosc==9)
		{
			ile9++;
			suma+=wynik;
		}
		
	}
	File.close();
	
	cout<<"1. "<<parzyste<<endl;
	cout<<"2. "<<najwieksza10<<" "<<najwieksza2<<endl;
	cout<<"3. "<<ile9<<" "<<sumabinarna(suma)<<endl;
	
	return 0;
}
