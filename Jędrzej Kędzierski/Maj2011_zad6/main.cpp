#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int konwertuj(string x)
{
	int x_10=0;
	
	for(int i=0; i<x.length(); i++)
	{
		if(x[x.length()-i-1]=='1')
		{
			x_10=x_10+pow(2,i);
		}
	}
	
	return x_10;
}

string rekonwertuj(int x_10)
{
	string y="";
	
	while(x_10>0)
	{
		if(x_10%2==0)
		{
			y='0'+y;
		}
		else
		{
			y='1'+y;
		}
		
		x_10=x_10/2;
	}
	
	return y;
}

int main(int argc, char** argv) {
	
	string x;
	int x_10;
	string max;
	int max_10=0;
	int licznik1=0;
	int licznik2=0;
	int suma_10=0;
	string suma;
	
	fstream infile;
	infile.open("liczby.txt", ios::in);
	
	while(infile>>x)
	{
		x_10=konwertuj(x);
		
		if(x[x.length()-1]=='0')
		{
			licznik1++;
		}
		
		if(x_10>max_10)
		{
			max_10=x_10;
			max=x;
		}
		
		if(x.length()==9)
		{
			licznik2++;
			suma_10=suma_10+x_10;
		}
	}
	
	infile.close();
	
	suma=rekonwertuj(suma_10);
	
	cout<<licznik1<<endl;
	cout<<max<<endl;
	cout<<max_10<<endl;
	cout<<licznik2<<endl;
	cout<<suma<<endl;
	
	return 0;
}
