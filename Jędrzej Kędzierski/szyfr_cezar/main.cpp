#include <iostream>
#include <fstream>

using namespace std;

string szyfrowanie(string slowo, int klucz)
{
	klucz=klucz%26;//26 - liczba liter w alfabecie
	
	for(int i=0; i<slowo.length(); i++)
	{
		if(slowo[i]+klucz>'Z')
		{
			slowo[i]=slowo[i]-26;
		}
		
		slowo[i]=slowo[i]+klucz;
	}
	
	return slowo;
}

string rozszyfrowywanie(string slowo, int klucz)
{
	klucz=klucz%26;
	
	for(int i=0; i<slowo.length(); i++)
	{
		if(slowo[i]-klucz<'A')
		{
			slowo[i]=slowo[i]+26;
		}
		
		slowo[i]=slowo[i]-klucz;
	}
	
	return slowo;
}

bool czy_blad(string slowo, string slowo_zakodowane)
{
	int klucz1;
	int klucz2;
	
	for(int i=0; i<slowo.length(); i++)
	{
		if(slowo[i]<slowo_zakodowane[i])
		{
			klucz1=slowo_zakodowane[i]-slowo[i];
		}
		else
		{
			klucz1=('Z'-slowo[i])+1+(slowo_zakodowane[i]-'A');
		}
		
		if(i>0)
		{
			if(klucz1!=klucz2)
			{
				return 1;
			}
		}
		
		klucz2=klucz1;
	}
	
	return 0;
}

int main(int argc, char** argv) {
	
	fstream infile;
	fstream outfile;
	
	//Rozwiazanie 6_1
	
	infile.open("dane_6_1.txt",ios::in);
	outfile.open("wyniki_6_1.txt",ios::out);
	
	string slowo, slowo_zakodowane;
	int klucz=107;
	
	while(infile>>slowo)
	{
		infile>>slowo;
		outfile<<szyfrowanie(slowo, klucz)<<endl;
	}
	
	infile.close();
	outfile.close();
	
	//Rozwiazanie 6_2
	
	infile.open("dane_6_2.txt",ios::in);
	outfile.open("wyniki_6_2.txt",ios::out);
	
	while(infile>>slowo_zakodowane && infile>>klucz)
	{
		outfile<<rozszyfrowywanie(slowo_zakodowane, klucz)<<endl;
	}
	
	infile.close();
	outfile.close();
	
	//Rozwiazanie 6_3
	
	infile.open("dane_6_3.txt",ios::in);
	outfile.open("wyniki_6_3.txt",ios::out);
	
	while(infile>>slowo && infile>>slowo_zakodowane)
	{
		if(czy_blad(slowo, slowo_zakodowane)==1)
		{
			outfile<<slowo<<endl;
		}
	}
	
	infile.close();
	outfile.close();
	
	return 0;
}
