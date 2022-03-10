#include <iostream>
using namespace std;

int zlicz(string ile)
{
	int liczba=0;
	for(int i; ile[i]!='w'; i+=1)
	{
		if(ile[i]=='p' && ile[i+1]=='r' && ile[i+2]=='a')
			liczba++;
	}
	return liczba;
}

double wnuk(int liczba)
{
	if(liczba==0)
	{
		return 3.5;
	}else
	return (wnuk(liczba-1)*2)/3;
}
	
bool ostatnie(string ile)
{
	int dlugosc=ile.length();
	if(ile[dlugosc-4]=='w' && ile[dlugosc-3]=='n' && ile[dlugosc-2]=='u' && ile[dlugosc-1]=='k')
		return true;
	else
		return false;
}

int main()
{
	string ile;
	int liczba;
	double dlugosc;
	cout<<"Podaj do ktorego potomka: ";
	cin>>ile;
	liczba=zlicz(ile);
	if(liczba>0)
	{
		if(ile.length()==liczba*3+4 && ostatnie(ile)==1)
		{
			dlugosc=wnuk(liczba);
			cout<<liczba<<endl;
 			cout<<dlugosc;			
		}else
			cout<<"Proba wlamania, usuwanie danych...";

	}else
		cout<<"BRAK";

	return 0;
}
