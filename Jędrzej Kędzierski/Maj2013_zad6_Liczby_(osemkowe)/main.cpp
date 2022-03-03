#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

bool czy_pierwsza_ostatnia_ta_sama(string number)
{
	if(number[0]==number[number.length()-1])
		return true;
	else
		return false;
}



int conversion_to_10(string number_8)
{
	int number_10=0;
	int cyfra;
	
	for(int i=0; i<number_8.length(); i++)
	{
		cyfra=number_8[number_8.length()-1-i]-48;
		number_10+=8*pow(8, i);
	}
	
	return number_10;
}

int main(int argc, char** argv) {
	
	string number_8;
	fstream infile("dane.txt", ios::in);
	
	int licznik_a=0;
	int licznik_b=0;
	
	while(infile>>number_8)
	{
		if(czy_pierwsza_ostatnia_ta_sama(number_8))
			licznik_a++;
		
	}
	
	cout<<licznik_a<<endl<<licznik_b<<endl;
	
	return 0;
}
