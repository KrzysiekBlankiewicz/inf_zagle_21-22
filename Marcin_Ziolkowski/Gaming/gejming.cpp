#include <iostream>
using namespace std;

void gameover()
{
	cout<<"GAME OVER"<<endl;
}
char znak(int w, int k, int x, int y)
{
	char znak=' ';
	if(w==y && k==x)
	znak='x';
	
	return znak;
}

int main()
{
	int r,w,k,x,y,petla=0;
	char kierunek;
	cout<<"Podaj rozmiar: ";
	cin>>r;
	cout<<"Podaj swoj� lokalizacj� wedlug osi x ";
	cin>>x;
	cout<<"Podaj swoj� lokalizacj� wedlug osi y ";
	cin>>y;
	w=k;

	do
	{
		int tablica [w] [k];
		for(w=1; w<=r; w++)
		{
			for(k=1; k<=r; k++)
			{
				cout<<"["<<znak(w,k,x,y)<<"]";
			}
			cout<< "\n";
		}
		
		cout<<"Sterujesz wsad"<<endl;
		cout<<"Je�eli chcesz skonczyc wci�nij x"<<endl;
		cin>>kierunek;
		if(kierunek=='w' && !(y-1==0))
		y=y-1;
		if(kierunek=='s' && !(y==r))
		y=y+1;
		if(kierunek=='a' && !(x-1==0))
		x=x-1;
		if(kierunek=='d' && !(x==r))
		x=x+1;
		if(kierunek=='x')
		return 0;
		system("cls");
	}while(true);
		
	return 0;
}
