#include <iostream>

#include<fstream>
#include<cmath>
using namespace std;


 
int main() {
 	int dlugosc;
	bool czy=true;
	fstream plik("dane.txt", ios::in);
	fstream plik2("dane.txt", ios::in);
  fstream plik3("dane.txt", ios::in);
   string a;
  int licznik3=0;
	int licznik=0;
  int c;
  int min=100000000;
  int max=0;
  int pamiec;
while(plik>>a)
	{
    czy=true;
    pamiec=0;
    plik3>>c;
		dlugosc=a.length();
    
		if(a[0]==a[dlugosc-1])
		{
			licznik++;
		}
    for(int i=1;i<dlugosc;i++){
      int d=a[i-1]-48;
      int w=a[i]-48;
      if(d<=w&&czy==true){
     
     czy=true;
        
        }
      else{
        czy=false;
      }
}
			if(czy==true){

        licznik3++;
        if(c>max){
          max=c;
        }
        if(c<min){
          min=c;
        }
      }
			
	}
  cout<<max<<" "<<min<<" "<<licznik3<<endl;///podpunkt c)
	cout<<licznik<<endl;////podpunkt a)
  
  int liczba10;
		int n;
		int b;
		int reszta;
		int liczbas;
		int dlugosc2;
		int licznik2=0;
	while(plik2>>b)
	{
    n=0;

	  liczba10=0;
		while(b>0)
		{
			reszta=b%10;
			b=b/10;
			liczba10=liczba10+reszta*pow(8, n);
			n++;
		}
		
   liczbas=liczba10;
	
    while(liczbas>=10)
		{
			reszta=liczbas%10;
			liczbas=liczbas/10;
			
		
		}
    
		if(liczbas==liczba10%10)
		{
			licznik2++;
		}
	
		
	}
cout<<licznik2<<endl;///podpunkt b)
  
		
  
}

