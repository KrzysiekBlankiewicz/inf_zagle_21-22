#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
string dwojkowe( int liczba){
    
  
  int reszta=0;
 string liczba2;
while(liczba>0){
	
  if(liczba%2==0){
liczba2='0'+liczba2;
    }
      
  else{
    liczba2='1'+liczba2;
    }
  liczba=liczba/2;
 }

return liczba2;
}
int main() {
 fstream plik;
	string a;
	int x;
	int max=0;
	char cyfra;
	string max2;
	int potega=0;
  long long int suma=0;
int dlugosc;
	int licznik=0;
  int licznik2=0;
	plik.open("liczby.txt", ios::in);
	int liczba;
	
	
	while(plik>>a)
	{
    liczba=0;
		potega=0;
		x=a.length()-1;
    dlugosc=a.length();
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
		 if(dlugosc==9){
      licznik2++;
       suma=suma+liczba;
       
     }

	}
	
	cout<<licznik<<endl;
	cout<<max<<" "<<max2<<endl;
  
	
  cout<<licznik2<<" "<<dwojkowe(suma)<<" "<<suma;
		
}
