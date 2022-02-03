#include <iostream>
#include <fstream>

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

int main(int argc, char** argv) {
	
	string binary;
	int licznik1=0;
	int licznik2=0;
	string napis1;
	int dlugosc1=0;
	int dlugosc2=INT_MAX;
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
		
	}
	
	cout<<licznik1<<" "<<dlugosc1<<" "<<napis1<<endl;
	cout<<licznik2<<" "<<dlugosc2<<endl;
	
	return 0;
}
