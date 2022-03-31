#include <iostream>
#include <fstream>

using namespace std;

bool first(int a)
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
	
	string napis[1000];
	int counter=0;
	
	for(int i=0; i<1000; i++)
	{
		infile>>napis[i];
		
		if(first(sum(napis[i])))
			counter++;
	}
	
	outfile<<counter<<endl;
	
	for(int i=0; i<1000; i++)
	{
		if(ascending(napis[i]))
			outfile<<napis[i]<<endl;
	}
	
	outfile<<endl;
	
	for(int i=0; i<1000; i++)
	{
		int counter2=0;
		
		if(napis[i]=="")
			continue;
		
		for(int j=0; i<1000; j++)
		{
			if(j==i)
				continue;
			
			if(napis[i]==napis[j])
			{
				counter2++;
				napis[j]="";
			}
		}
		
		if(counter2>0)
			outfile<<napis[i]<<endl;
	}
	
	
	return 0;
}
