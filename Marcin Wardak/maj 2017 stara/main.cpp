#include <iostream>
#include <fstream>
using namespace std;
bool isCykliczny (string binary)
{
	short pol_dlugosci = binary.length()/2;
	for (short x = 0; x < (pol_dlugosci); x ++)
	{
		if (binary[x] != binary[x+pol_dlugosci])
			return 0;
	}
	return 1;
}
bool isGreater9 (string binary)
{
	if (binary[0]=='1')
	{
		if (binary[1]=='1')
			return 1;
		if (binary[2]=='1')
			return 1;
	}
	return 0;
}
bool isBCD(string binary)
{
	string tmp = "";
	for (short x = 0; x < binary.length(); x += 4)
	{
		tmp.push_back(binary[x]);
		tmp.push_back(binary[x+1]);
		tmp.push_back(binary[x+2]);
		tmp.push_back(binary[x+3]);
		if (isGreater9(tmp))
			return 0;
		tmp.clear();
	}
	return 1;
}
int main(int argc, char** argv)
{
	string binary, max_binary;
	short max_1 = 0;
	short min_2 = INT_MAX;
	short licznik_1 = 0;
	short licznik_2 = 0;
	fstream input ("binarne.txt", ios::in);
	while (input >> binary)
	{
		if (!isCykliczny(binary))
		{
			licznik_1++;
			if (max_1 < binary.length())
			{
				max_1 = binary.length();
				max_binary = binary;
			}
		}
		if (!isBCD(binary))
		{
			licznik_2++;
			if (binary.length()<min_2)
				min_2 = binary.length();
		}
	}
	cout << licznik_1 << " " << max_binary << " " << max_binary.length() << endl;
	cout << licznik_2 << " " << min_2 << endl;
	return 0;
}
