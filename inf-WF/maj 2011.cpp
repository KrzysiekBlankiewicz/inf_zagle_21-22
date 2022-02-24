#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	fstream plik;
	string a;
	int x;
	int max=0;
	char cyfra;
	string max2;
	int potega=0;

	int licznik=0;
	plik.open("liczby.txt", ios::in);
	int liczba;
	
	
	while(plik>>a)
	{
		potega=0;
		x=a.length()-1;
		if(a[x]=='0')
		{
			licznik++;
		}
		
		for(int i=a.length();i>0;i--)
		{
		  if(a[i-1]=='1'){
		  	liczba=liczba+pow(2, potega);
		  	
		  }
		 
		  potega++;
			
			
		}
		if(max<liczba){
			
			max=liczba;
			max2=a;
		}
		

	}
	
	
	cout<<max<<endl;
	cout<<licznik;
		
		

	return 0;
}
