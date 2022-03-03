#include "Funkcje.hpp"

using namespace std;

main()
{
	cout<<"Wybierz opcje (wpisujac numer)"<<endl;
	cout<<"1. Tworzenie struktury plikow"<<endl;
	cout<<"2. Zapis nowego projektu"<<endl;
	cout<<"3. Zamkniecie programu"<<endl;
	
	int x;
	
	while(true)
	{
		cin>>x;
				
		switch(x)
		{
			case 1:
				TworzenieStruktury();
				cout<<"Wykonano"<<endl;
				cout<<"Wybierz opcje"<<endl;
				break;
			case 2:
				ZapisywanieProjektow();
				cout<<"Wykonano"<<endl;
				cout<<"Wybierz opcje"<<endl;
				break;
			case 3:
				return 0;
			default:
				cout<<"Wprowadzono nieprawidlowy numer"<<endl;
		}
	}
	
	return 0;
}
