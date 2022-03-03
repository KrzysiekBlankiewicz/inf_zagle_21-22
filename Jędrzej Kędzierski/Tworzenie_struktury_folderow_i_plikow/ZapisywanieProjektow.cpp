#include "Funkcje.hpp"

bool is_date_correct(string date)
{
	if (date.length() != 10)
		return 0;
	for (short x = 0; x < 10; x ++) // sprawdzanie poprawnoœci formatu
	{
		if (!((x+1)%3)&&x%8) // sprawdzanie / na pozycji 2 i 5
		{
			if (date[x]!='/') 
				return 0;
		}
		else if (date[x] < '0' || date[x] > '9') // sprawdzanie liczb
			return 0;
	}
	if (stoi(date.substr(0, 2)) > 31 || stoi(date.substr(0, 2)) < 1) //dzieñ
		return 0;
	if (stoi(date.substr(3, 2)) > 12 || stoi(date.substr(3, 2)) < 1) //miesi¹c
		return 0;
	return 1;
}

bool dzien(string x)
{
	if(x[0]=='0' && x[1]>'0' && x[1]<='9')
	{
		return true;
	}
	else if(x[0]=='0' && x[1]=='0')
	{
		return false;
	}
	else if(x[0]<='2' && x[0]>'0' && x[1]>='0' && x[1]<='9')
	{
		return true;
	}
	else if(x[0]=='3' && (x[1]=='1' || x[1]=='0'))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool miesiac(string x)
{
	if(x[3]=='0' && x[4]>'0' && x[4]<='9')
	{
		return true;
	}
	else if(x[3]=='1' && x[4]>='0' && x[4]<='2')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool rok(string x)
{
	if(x[6]>'0' && x[6]<='9' && x[7]>='0' && x[7]<='9' && x[8]>='0' && x[8]<='9' && x[9]>='0' && x[9]<='9')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool kropki(string x)
{
	if(x[2]=='.' && x[5]=='.')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool FormatDaty(string x)
{
	if(x=="-")
	{
		return true;
	}
	else if(x.length()==10 && dzien(x)==true && miesiac(x)==true && rok(x)==true && kropki(x)==true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool FormatDone(string x)
{
	if(x=="yes" || x=="no")
	{
		return true;
	}
	else
	{
		return false;
	}
}

int ZapisywanieProjektow()
{
	fstream file;
	
	file.open("./Jedrzej_Kedzierski/C++/tasks.txt", ios::in);
	
	if(file.good()==false)
	{
		cout<<"Blad otwarcia pliku do odczytu"<<endl;
		return 0;
	}
	
	string a;
	string b;
	
	while(getline(file, a))
	{
		cout<<a<<endl;
		b=a[5];
		b=b+a[6];
	}
	
	file.close();
	
	string n="00";
	
	if(b=="id")
	{
		n="01";
	}
	else
	{
		n=b[0];
		
		if(b[1]=='9')
		{
			n=b[0]+1;
			n=n+"0";
		}
		else
		{
			b[1]++;
			n=n+b[1];
		}
	}
	
	file.open("./Jedrzej_Kedzierski/C++/tasks.txt", ios::out|ios::app);
	
	if(file.good()==false)
	{
		cout<<"Blad otwarcia pliku do zapisu"<<endl;
		return 0;
	}
	
	cout<<"task_"+n+" ";
	
	file<<"task_"+n+" ";
	
	string x;
	cin>>x;
	
	string y;
	cin>>y;
	
	string z;
	cin>>z;
	
	string v;
	getline(cin, v);
	
	while(FormatDaty(x)==false)
	{
		cout<<"Zly format due_date (dd.mm.rrrr), wpisz ponownie"<<endl;
		cin>>x;
	}
	
	while(FormatDone(y)==false)
	{
		cout<<"Zly format done (yes/no), wpisz ponownie"<<endl;
		cin>>y;
	}
	
	while(FormatDaty(z)==false)
	{
		cout<<"Zly format uploade_date (dd.mm.rrrr), wpisz ponownie"<<endl;
		cin>>z;
	}
	
	file<<x+" ";
	file<<y+" ";
	file<<z+" ";
	file<<v+" ;"<<endl;
	
	file.close();
	
	string f="./Jedrzej_Kedzierski/C++/task_"+n;
	string p=f+"/readme.txt";
	
	mkdir(f.c_str());
	
	file.open(p.c_str(), ios::out);
	
	if(file.good()==false)
	{
		cout<<"Blad otwarcia pliku readme projektu"<<endl;
		return 0;
	}
	
	file<<"task_"+n<<endl;
	
	file.close();
	
	return 0;
}
