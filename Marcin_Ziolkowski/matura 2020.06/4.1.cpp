#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
	string dane;
	fstream File;
	File.open("pary.txt", ios::in);
	
	while (getline(File, dane))
	{
		//oddzielenie liczby z ca³ej linijki
		int dlugosc = dane.length();
		int spacja = dane.find(" ");
		string numer = dane.substr(0,spacja);
		int liczba;
		stringstream ss;  
 		ss << numer;  
 		ss >> liczba; 
		
		//znalezienie liczb nieparzystych pierwszych
		int d1=3, d2=3;
		if(liczba%2==0 && liczba>=6)
		{
			do
			{
				if(liczba==d1+d2)
				{
					break;
				}else
				{
					d1=d1+2;
				}
			}while (d1+d2<liczba);
			int x=2;
			while (x*x<=d1)
			{
				if (d1%x==0)
				{
					d1=d1-2;
					d2=d2+2;
					break;
				}
				x++;
			}
			int a=2;
			while (a*a<=d1)
			{
				if (d1%a==0)
				{
					d1=d1-2;
					d2=d2+2;
					break;
				}
				a++;
			}
			cout<<d2<<" + "<<d1<<endl;
		}else
		{
			cout<<liczba<<endl;
		}
	}	
	return 0;
}


