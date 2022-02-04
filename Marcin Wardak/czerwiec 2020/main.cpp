#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

bool is_prime (int x)
{
	for (short i = 2; i < x; i ++)
	{
		if (x%i == 0)
			return 0;
	}
	return 1;
}

short goldbach (short liczba)
{
	for (short x = 3; x < liczba/2; x ++)
	{
		if (liczba > 4 && liczba %2 == 0)
		{
			if (is_prime(x)==1&&is_prime(liczba-x) == 1)
				return x;
		}
	}
	return 0;
}

string find_longest (string ciag)
{
	short count = 1;
	string output = "";
	short max = 0;
	char max_char = ciag[0];
	for (short x = 1; x < ciag.length(); x ++)
	{
		if (ciag[x] != ciag[x-1])
		{
			if (max < count) 
			{
				max = count;
				max_char = ciag[x-1];
			}
			count = 1;
		}
		else
			count ++;
	}
	for (short x = 0; x < max; x ++)
	{
		output.push_back(max_char);
	}
	return output;
}
bool is_smaller (short liczba1, string ciag1, short liczba2, string ciag2)
{
	if ()
}
int main(int argc, char** argv)
{
	fstream input ("pary.txt", ios::in);
	short is_goldbach;
	string longest_string;
	fstream output_1 ("odp1.txt", ios::out);
	fstream output_2 ("odp2.txt", ios::out);
	fstream output_3 ("odp3.txt", ios::out);
	short liczba[100];
	string ciag[100];
	short min_liczba = SHORT_MAX;
	string min_string = "";
	for (short x = 0; x < 100; x ++)
	{
		input >> liczba[x] >> ciag[x];
		is_goldbach = goldbach(liczba[x]);
		if (is_goldbach) //1111
			output_1 << liczba[x] << " " << is_goldbach << " " << liczba[x] - is_goldbach << endl;
		longest_string = find_longest (ciag[x]); //2222
		output_2 << longest_string << " " << longest_string.length() << endl;
		if (ciag[x].length()==liczba[x]) //3333
		{
			if (min_liczba==SHORT_MAX)
			{
				min_liczba = liczba[x];
				min_string = ciag[x];
			}
			else
			{
				if (is_smaller(liczba[x], ciag[x], min_liczba, min_string) == 1)
				{
					min_liczba = liczba[x];
					min_string = ciag[x];
				}
			}
		}
	}
	return 0;
}
