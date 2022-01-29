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
 
double oblicz_srednia(int x[10])
{
	double suma=0;
	
	for(int i=0; i<10; ++i)
	{
		suma+=x[i];
	}
	
	return suma/10.0;
}
 
int wybierz_zawodnika(int x[10], int y)
{
	for(int i=0; i<10; i++)
	{
		if(x[i]==y)
		{
			return i+1;
		}
	}
	
	return 0;
}
 
main()
{	
	fstream file;
	file.open("wyniki.txt", ios::in);
	
	string dane[10];
	int okrazenia[10];
	
	for(int i=0; i<10; ++i)
	{
		file>>dane[i];
		file>>dane[i];
		okrazenia[i]=konwertuj_na_10(dane[i]);
	}
	
	file.close();
	
	cout<<"srednia: "<<oblicz_srednia(okrazenia)<<endl;
	
	int y=oblicz_srednia(okrazenia)+1;
	
	cout<<"miejsce zawodnika, ktory pokonal o jedno okrazenie wiecej niz srednia: "<<wybierz_zawodnika(okrazenia, y)<<endl;
	
	return 0;
}
