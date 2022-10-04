#include <iostream>

using namespace std;

double samica(short pokolenie);

double samiec(short pokolenie)
{
	if(pokolenie==1)
		return 3.5;
	else
		return samiec(pokolenie-1)*2/3+samica(pokolenie-1)/10;
}

double samica(short pokolenie)
{
	if(pokolenie==1)
		return 14;
	else
		return samica(pokolenie-1)*2/3+samiec(pokolenie-1)/10;
}

int main(int argc, char** argv) {
	
	cout<<"Podaj pokolenie w postaci liczby: ";
	short pokolenie=cin>>pokolenie?pokolenie:-1;
	
	if(pokolenie<=0)
		cout<<"Niepoprawne pokolenie\n";
	else
	{
		cout<<"Dlugosc traby\n";
		cout<<"Samiec: "<<samiec(pokolenie)<<"\tSamica: "<<samica(pokolenie)<<endl;
	
	}
	
	return 0;
}
