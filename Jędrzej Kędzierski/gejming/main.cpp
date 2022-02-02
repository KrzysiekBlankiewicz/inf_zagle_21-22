#include <iostream>

using namespace std;

void wiersz_pierwszy(int l)
{
	for(int i=0; i<l; i++)
	{
		cout<<" _";
	}
	
	cout<<endl;
}

void wiersz(int l)
{
	char znak='_';
	
	for(int i=0; i<l; i++)
	{
		cout<<"|";
		cout<<znak;
	}
	
	cout<<"|"<<endl;
}

void wiersz_z_x(int l, int x)
{
	char znak='_';
	
	for(int i=0; i<l; i++)
	{
		if(i==x)
		{
			cout<<"|";
			cout<<"x";
		}
		else
		{
			cout<<"|";
			cout<<znak;
		}
	}
	
	cout<<"|"<<endl;
}

bool board(int l, int x, int y)
{
	if(x>=l ||y>=l)
	{
		return 1;
	}
	
	wiersz_pierwszy(l);
	
	for(int i=0; i<l; i++)
	{
		if(i==y)
		{
			wiersz_z_x(l, x);
		}
		else
		{
			wiersz(l);
		}
	}
	
	return 0;
}

int main(int argc, char** argv) {
	
	int l=4;
	cout<<"Podaj wspolrzedne"<<endl;
	string a;
	cin>>a;
	
	int x=toupper(a[0])-'A';
	int y=a[1]-'1';
	
	while(x>=l || y>=l)
	{
		cout<<"Niepoprawne wspolrzedne"<<endl<<"Podaj jeszcze raz"<<endl;
		cin>>a;
		
		x=toupper(a[0])-'A';
		y=a[1]-'1';
	}
	
	board(l, x, y);
	
	
	
	
	
	
	return 0;
}
