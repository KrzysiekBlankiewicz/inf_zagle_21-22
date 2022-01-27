#include <iostream>
#include <math.h>
#include <string>
#include <fstream>

int konwertuj_na_10(std::string s)
{
	int wynik = 0;
	for(int i = s.length() - 1; i >= 0; --i)
	{
		if(s[i] == '1')
		{
			wynik += pow(2, s.length() - 1 - i);
		}
	}
	return wynik;
}

double oblicz_srednia(std::string wyniki[10])
{
	double suma = 0;
	for(int i = 0; i < 10; ++i)
	{
		suma += konwertuj_na_10(wyniki[i]);
	}	
	return suma/10;
}

int wybierz_zawodnika(std::string wyniki[10])
{
	for(int i = 0; i < 10; ++i)
	{
		if(wyniki[i] == "1001")
			return i;
	}
	return -1;	
}

bool wczytaj_dane(std::string wyniki[10], const std::string nazwaPliku)
{
	std::fstream plik;
	plik.open(nazwaPliku.c_str());
	
	for(int i = 0; i < 10; ++i)
	{
		plik >> wyniki[i];
		plik >> wyniki[i];
		std::cout << wyniki[i] << std::endl;
	}
	
	return true;
}

main()
{
	std::string wyniki[10];
	const std::string nazwaPliku = "wyniki.txt";
	
	wczytaj_dane(wyniki, nazwaPliku);
	
	std::cout << oblicz_srednia(wyniki) << std::endl;
	
	int x = wybierz_zawodnika(wyniki);
	if(x != -1)
		std::cout << x + 1 << std::endl;
	else
		std::cout << "brak takiego zawodnika";
	
}


