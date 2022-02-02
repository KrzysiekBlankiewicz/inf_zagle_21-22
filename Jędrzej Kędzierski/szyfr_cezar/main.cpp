#include <iostream>
#include <fstream>

using namespace std;

string szyfrowanie(string slowo, int klucz)
{
	klucz=klucz%26;//26 - liczba liter w alfabecie
	
	for(int i=0; i<slowo.length(); i++)
	{
		if(slowo[i]+klucz>90)
		{
			slowo[i]=slowo[i]-26;
		}
		
		slowo[i]=slowo[i]+klucz;
	}
	
	return slowo;
}

int main(int argc, char** argv) {
	
	fstream file;
	file.open("dane_6_1.txt",ios::in);
	
	string slowo[100];
	
	for(int i=0; i<100; i++)
	{
		file>>slowo[i];
		cout<<szyfrowanie(slowo[i], 107)<<endl;
	}
	
	return 0;
}
