#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	string dane;
	fstream File;
	File.open("pary.txt", ios::in);
	int ile, ilemax;
	char literka, literkamax;
	
	while (getline(File, dane))
	{
		int dlugosc = dane.length();
		int spacja = dane.find(" ");
		string wyraz= dane.substr(spacja+1, dlugosc - 1);
		
		cout<<wyraz<<endl;
		
		ilemax=0;
		ile=1;
		
		for(int i=0; i<wyraz.length(); i++)
		{
			literka=wyraz[i];

			if(wyraz[i+1]==wyraz[i])
			{
				ile++;	
			}
			else
			{
				
				if(ile>ilemax)
				{
					ilemax=ile;
					literkamax=literka;
				}

				ile=1;
			}
			if(ile>ilemax)
			{
				ilemax=ile;
				literkamax=literka;
			}
		}
		
		int x=1;
		do{
			cout<<literkamax;
			x++;
		}while(x<=ilemax);
		cout<<" "<<ilemax<<endl;
		
	}
	
	return 0;
}
