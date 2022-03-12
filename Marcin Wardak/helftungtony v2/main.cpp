#include <iostream>
using namespace std;

double dlugosc_samica (short pokolenie);

double dlugosc_samiec(short pokolenie)
{
	if (pokolenie == 1)
		return 3.5;
	else return dlugosc_samiec(pokolenie-1)*2.0/3.0 + dlugosc_samica(pokolenie-1)/10.0;
}

double dlugosc_samica(short pokolenie)
{
	if (pokolenie == 1)
		return 14.0;
	else return dlugosc_samica(pokolenie-1)*2.0/3.0 + dlugosc_samiec(pokolenie-1)/10.0;
}

int main()
{	
	short input = cin>>input?input:-1;
	if (input <= 0) return 13;
	cout << "samiec: " << dlugosc_samiec(input) << "\tsamica: " << dlugosc_samica(input);
	return 0;
}
