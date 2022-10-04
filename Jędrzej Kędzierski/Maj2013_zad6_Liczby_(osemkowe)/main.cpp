#include <iostream>
#include <fstream>

using namespace std;

bool is_ascending(string number)
{
	for(int i=1; i<number.length(); i++)
	{
		if(number[i]<number[i-1])
			return 0;
	}
	
	return 1;
}

int pow(int base, int exponent) // potegowanie bez biblioteki <cmath>
{
	int power=1;
	
	if(exponent==0)
		return power; // power ma wartosc 1
	else
	{
		for(int i=0; i<exponent; i++)
		{
			power*=base;
		}
	}
	
	return power;
}

bool is_first_last_equal(int number)
{
	int last_number=number%10;
	
	while(number>=10)
		number/=10;
	
	return number==last_number;
}

int conversion_from_8_to_10(string number_8)
{
	int number_10=0;
	
	for(int i=0; i<number_8.length(); i++)
	{
		number_10+=(number_8[i]-48)*pow(8, number_8.length()-1-i);
	}
	
	return number_10;
}

int main(int argc, char** argv) {
	
	string number_8;
	int number_10;
	int counter_a=0;
	int counter_b=0;
	int counter_c=0;
	int max_10=0;
	int min_10=INT_MAX;
	string max_8="";
	string min_8="";
	fstream infile("dane.txt", ios::in);
	
	while(infile>>number_8)
	{
		if(number_8[0]==number_8[number_8.length()-1]) // a)
			counter_a++;
			
		/*if(is_first_last_equal(conversion_from_8_to_10(number_8)))
			counter_b++;*/
		
		number_10=conversion_from_8_to_10(number_8); // b)
		counter_b+=is_first_last_equal(number_10);
		
		if(is_ascending(number_8)) // c)
		{
			counter_c++;
			
			if(number_10>max_10)
			{
				max_10=number_10;
				max_8=number_8;
			}
			
			if(number_10<min_10)
			{
				min_10=number_10;
				min_8=number_8;
			}
		}
	}
	
	infile.close();
	
	fstream outfile("wyniki6.txt", ios::out);
	
	outfile<<"a)"<<endl<<counter_a<<endl<<endl<<"b)"<<endl<<counter_b<<endl<<endl<<"c)"<<endl<<counter_c<<" liczb spelnia warunek"<<endl<<"najwieksza liczba: "<<max_10<<"(10), "<<max_8<<"(8)"<<endl<<"najmniejsza liczba: "<<min_10<<"(10), "<<min_8<<"(8)"<<endl;
	
	outfile.close();
	
	return 0;
}
