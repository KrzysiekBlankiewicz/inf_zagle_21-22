#include <iostream>
#include <fstream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
bool is_asc (string number)
{
	for (short x = 1; x < number.length(); ++x)
	{
		if (number[x] < number[x-1])
			return 0;
	}
	return 1;
}

int pow (int number, int exponent)
{
	int output = 1;
	if (exponent == 0)
		return 1;
	else
	{
		for (short x = 0; x < exponent; x ++)
		{
			output *= number;
		}
	}
	return output;
}

bool is_equal (int number)
{
	short end = number%10;
	for (; number >= 10; number /= 10);
	return number == end;
	
}
int eight_to_ten (string number)
{
	int output = 0;
	int multiplier = 1;
	for (short x = 0; x < number.length(); ++x)
	{
		output += (number[x]-48) * pow (8, number.length() - x - 1);
	}
	return output;
}

int main(int argc, char** argv)
{
	string number;
	int counter_1 = 0;
	int counter_2 = 0;
	int counter_3 = 0;
	string max = "";
	string min = "";
	int min_conv = INT_MAX;
	int max_conv = 0;
	int number_conv;
	fstream input ("dane.txt",ios::in);
	while (input >> number)
	{
		if (number[0] == number[number.length()-1]) // 1.
			++counter_1;
		number_conv = eight_to_ten(number);
		counter_2 += is_equal (number_conv); // 2.
		if (is_asc (number)) // 3.
		{
			++counter_3;
			if (number_conv > max_conv)
			{
				max_conv = number_conv;
				max = number;
			}
			if (number_conv < min_conv)
			{
				min_conv = number_conv;
				min = number;
			}
		}
		
	}
	cout << "1. " << counter_1 << "\n2. " << counter_2 << "\n3. " << counter_3
	<< "\nmin: " << min << "\tmax: " << max;
	return 0;
}
