#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	fstream File;
	File.open("pary.txt", ios::in);
	
	int x, y, i, liczba, najm_liczba=100;
	string slowo, najm_slowo;
	char a,b;
	
	while(!File.eof())
	{
		File>>liczba;
		File>>slowo;
		
		if(liczba==slowo.length())
		{
			if(liczba<najm_liczba)
			{
				najm_liczba=liczba;
				najm_slowo=slowo;
			}
			if(liczba==najm_liczba)
			{
				i=0;
				while(i<slowo.length())
				{
					a=slowo[i];
					b=najm_slowo[i];
					x=a;
					y=b;

					if(x<y)
					{
						najm_liczba=liczba;
						najm_slowo=slowo;
					}
					i++;
				}
			}
		}	
	}
	
	cout<<najm_liczba<<" "<<najm_slowo;
	
	return 0;
}
