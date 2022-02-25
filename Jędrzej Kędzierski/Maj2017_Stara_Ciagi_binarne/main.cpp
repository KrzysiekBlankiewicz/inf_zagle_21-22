#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

bool isCykliczny(string binary)
{
	int dlugosc=binary.length()/2;
	for(int i=0;i<dlugosc;i++)
	{
		if(binary[i]!=binary[i+dlugosc])
		{
			return 0;
		}
	}
	
	return 1;
}

bool isWieksza9(string s)
{
	if(s[0]=='1')
	{
		if(s[2]=='1')//>10
			return 1;
		if(s[1]=='1')//>12
			return 1;
	}
	
	return 0;
}

bool isNiePoprawna(string binary)
{
	string s="";
	
	for(int i=0; i<binary.length(); i=i+4)
	{
		s=s+binary[i]+binary[i+1]+binary[i+2]+binary[i+3];
		if(isWieksza9(s)==1)
		{
			return 1;
		}
		s="";
	}
	
	return 0;
}

int toDecimal(string binary)
{
	int decimal=0;
	
	for(int i=0; i<binary.length(); i++)
	{
		if(binary[i]=='1')
		{
			decimal=decimal+pow(2,binary.length()-i-1);
		}
	}
	
	return decimal;
}

int main(int argc, char** argv) {
	
	string binary;
	int licznik1=0;
	int licznik2=0;
	string napis1;
	int dlugosc1=0;
	int dlugosc2=INT_MAX;
	int max3=0;
	string max_binary3;
	
	fstream infile("binarne.txt", ios::in);
	
	while(infile>>binary)
	{
		if(isCykliczny(binary)==1)
		{
			licznik1++;
			if(binary.length()>dlugosc1)
			{
				dlugosc1=binary.length();
				napis1=binary;
			}
		}
		
		if(isNiePoprawna(binary)==1)
		{
			licznik2++;
			if(binary.length()<dlugosc2)
			{
				dlugosc2=binary.length();
			}
		}
		
		if(binary.length()<17)//1111111111111111(2)=65535(10)
		{
			int current=toDecimal(binary);
			if(current>max3)
			{
				max3=current;
				max_binary3=binary;
			}
		}
		
	}
	
	infile.close();
	
	fstream outfile("zadanie4.txt", ios::out);
	
	outfile<<"4.1"<<endl<<endl<<"liczba napisow dwucyklicznych: "<<licznik1<<endl<<"Najwieksza dlugosc napisu dwucyklicznego: "<<dlugosc1<<endl<<"Najdluzszy napis dwucykliczne: "<<napis1<<endl<<endl;
	outfile<<"4.2"<<endl<<endl<<"liczba slow niepoprawnych: "<<licznik2<<endl<<" dlugosc najkrotszego niepoprawnego napisu: "<<dlugosc2<<endl<<endl;
	outfile<<"4.3"<<endl<<endl<<"Najwieksza liczba w zapisie binarnym: "<<max_binary3<<endl<<"Najwieksza liczba w zapisie dziesietnym: "<<max3<<endl;
	
	outfile.close();
	
	return 0;
}
