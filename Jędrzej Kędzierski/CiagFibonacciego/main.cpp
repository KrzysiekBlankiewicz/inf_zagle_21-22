#include <iostream>
using namespace std;

int fib(int n)
{
	if(n<3)
		return 1;
	else
		return fib(n-2)+fib(n-1);
}

int main(int argc, char** argv) {
	
	int n;
	cin>>n;
	cout<<fib(n)<<endl;
	
	return 0;
}
