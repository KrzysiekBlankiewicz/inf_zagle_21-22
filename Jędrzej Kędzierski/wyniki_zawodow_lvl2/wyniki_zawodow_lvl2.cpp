#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int konwertuj_na_10(string s)
{
    int wynik = 0;
    for(int i = s.length() - 1; i >= 0; --i)
    {
        if(s[i] == '1')
        {
            wynik += pow(2, s.length()-1-i);
        }
    }
    return wynik;
}
 
double oblicz_srednia(int a, int x[])
{
	double suma=0;
	
	for(int i=0; i<a; ++i)
	{
		suma+=x[i];
	}
	
	return suma/a;
}
 
main()
{	
	fstream file;
	file.open("wyniki.txt", ios::in);
	
	int a=10;//do zamiany na 50
	
	string dane[a], dane2[a];
	int okrazenia[a];
	int licznik=0;
	
	for(int i=0; i<a; ++i)
	{
		file>>dane[i];
		file>>dane2[i];
		okrazenia[i]=konwertuj_na_10(dane2[i]);
		
		if(okrazenia[i]%5==0)
		{
			licznik++;
		}
	}
	
	file.close();
	
	cout<<"srednia: "<<oblicz_srednia(a, okrazenia)<<endl;
	
	int y=oblicz_srednia(a, okrazenia)+1;
	
	cout<<"liczba zawodnikow, ktorzy pokonali liczbe okrazen podzielna przez 5: "<<licznik<<endl;
	
	return 0;
}
