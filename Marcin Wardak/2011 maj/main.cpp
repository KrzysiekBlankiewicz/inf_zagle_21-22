#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int two_to_ten (string input)
{
	int output = 0;
	for (short x = 0; x < input.length(); x ++)
	{
		if (input[x] == '1')
			output += pow (2, input.length()-x-1);
	}
	return output;
}

string ten_to_two (int input)
{
	string output = "";
	while (input > 0)
	{
		if (input%2 == 0)
			output.insert(0, "0");
		else output.insert(0, "1");
		input /= 2;
	}
	return output;
}
int main(int argc, char** argv)
{
	fstream input ("liczby.txt", ios::in);
	string x;
	int x_10, current;
	short counter_1 = 0;
	int max = 0;
	int sum = 0;
	string max_2;
	while (input >> x)
	{
		if (x[x.length()-1] == '0')
			++counter_1;
		current = two_to_ten (x);
		if (current > max)
		{
			max = current;
			max_2 = x;
		}
		if (x.length() == 9)
			sum += current;
	}
//	cout << two_to_ten("1010");
//	cout << ten_to_two (100);
	cout << "1. " << counter_1 << "\n2. " << max << " " << max_2 << "\n3. " << ten_to_two(sum);
	return 0;
}
