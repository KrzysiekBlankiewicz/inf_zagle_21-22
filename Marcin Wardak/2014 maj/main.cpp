#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int sum (string input)
{
	int output = 0;
	for (char i : input)
		output += (int)i;
	return output;
}

bool is_prime (int input)
{
	if (input == 1 || input == 0)
		return 0;
	for (short x = 2; x < input; ++x)
		if (input%x==0) return 0;
	return 1;
}

bool is_asc (string input)
{
	for (short x = 1; x < input.size(); ++x)
		if (input[x] <= input[x-1])
			return 0;
	return 1;
			
}
int main(int argc, char** argv)
{
	string word[1000];
	short counter1 = 0;
	ifstream file ("NAPIS.txt");
	for (short x = 0; file >> word[x]; ++x)
	{
		counter1 += is_prime(sum(word[x])); // 1.
		if (is_asc(word[x]))
			cout << word[x] << endl; // 2.
	}
	
	cout << counter1;
	cout << "\n\n\n\n\n";
	for (short x = 0; x < 1000; ++x)
	{
		for (short y = x+1; y < 1000; ++y)
			if (word[x].length()>0&&word[x] == word[y])
			{
				cout << word[x] << endl;
				word[x].resize(0);
				word[y].resize(0);
			}
	}
	return 0;
}
