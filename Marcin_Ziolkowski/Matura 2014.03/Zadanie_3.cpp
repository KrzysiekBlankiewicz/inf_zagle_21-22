#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	
	fstream plik;
	plik.open("NAPIS.txt", ios::in);
	
	string tablica[1000];
	
	for(int i=0; i<1000; i++)
	{
		plik>>tablica[i];
	}
	
		for(int i=0; i<1000; i++)
	{
			for(int y=i+1; y<1000; y++)
			if(tablica[i]==tablica[y])
			cout<<tablica[y]<<endl;
	}

	return 0;
}
