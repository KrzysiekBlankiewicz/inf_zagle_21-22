#include <iostream>
using namespace std;

int fibonacii(int pozycja)
{
	if(pozycja==2)
		return 1;
	if(pozycja==1)
		return 1;
		
		return fibonacii(pozycja - 1) + fibonacii(pozycja -2);
}

int main()
{
	int pozycja;
	cout<<"Podaj numer: ";
	cin>>pozycja;
	
	cout<<fibonacii(pozycja);
	return 0;
}
