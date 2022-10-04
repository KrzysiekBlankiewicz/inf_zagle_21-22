#include <iostream>
#include <fstream>
using namespace std;

bool czy_rosnacy(string wyraz)
{
	int a=(int)wyraz[0], b;
	for(int i=1; i<wyraz.length(); i++)
	{
		b=(int)wyraz[i];
		if(a<b)
			a=b;
		else
			return false;
	}
	return true;
}

int main()
{
	string wyraz;
	fstream plik;
	plik.open("NAPIS.txt", ios::in);
	
	while(!plik.eof())
	{
		plik>>wyraz;
		if(czy_rosnacy(wyraz)==true)
			cout<<wyraz<<endl;
	}
	
	
	return 0;
}
