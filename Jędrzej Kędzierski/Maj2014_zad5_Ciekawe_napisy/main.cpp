#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool prime(int a)
{
	if(a==1)
		return 0;
		
	if(a==2)
		return 1;
	
	for(int i=2; i<a; i++)
	{
		if(a%i==0)
			return 0;
	}
	
	return 1;
}

int sum(string napis)
{
	int sum=0;
	
	for(int i=0; i<napis.length(); i++)
	{
		sum+=(int)napis[i];
	}
	
	return sum;
}

bool ascending(string napis)
{
	for(int i=1; i<napis.length(); i++)
	{
		if(napis[i]<napis[i-1])
			return 0;
	}
	
	return 1;
}

int main(int argc, char** argv) {
	
	fstream infile("NAPIS.txt", ios::in);
	fstream outfile("wyniki5.txt", ios::out);
	
	string writing[1000];
	int counter=0;
	
	for(int i=0; i<1000; i++)
	{
		infile>>writing[i];
		
		if(prime(sum(writing[i])))
			counter++;
	}
	
	outfile<<"a)"<<endl<<endl<<counter<<endl<<endl;
	outfile<<"b)"<<endl<<endl;
	
	for(int i=0; i<1000; i++)
	{
		if(ascending(writing[i]))
			outfile<<writing[i]<<endl;
	}
	
	outfile<<endl<<endl;
	outfile<<"c)"<<endl<<endl;
	
	for(int i=0; i<1000; i++)
	{
		int counter2=0;
		
		if(writing[i]=="")
			continue;
		
		for(int j=i+1; j<1000; j++)
			if(writing[i]==writing[j])
			{
				counter2++;
				writing[j].resize(0);
			}
		
		if(counter2>0)
			outfile<<writing[i]<<endl;
	}
	
	/*for(int i=0; i<1000; i++)
	{
		for(int j=i+1; j<1000; j++)
			if (napis[i].length()>0&&napis[i]==napis[j])
			{
				cout<<napis[i]<<endl;
				napis[i].resize(0);
				napis[j].resize(0);
			}
	}*/
	
	infile.close();
	outfile.close();
	
	return 0;
}
