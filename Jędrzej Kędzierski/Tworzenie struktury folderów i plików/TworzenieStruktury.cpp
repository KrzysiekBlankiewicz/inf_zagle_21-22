#include "Funkcje.hpp"

int TworzenieStruktury()
{
	mkdir("./Jêdrzej_Kêdzierski");
	mkdir("./Jêdrzej_Kêdzierski/C++");
	
	fstream file;
	
	file.open("./Jêdrzej_Kêdzierski/C++/tasks.txt", ios::out);
	
	if(file.good()==false)
	{
		cout<<"Blad otwarcia pliku"<<endl;
		return 0;
	}
	
	file<<"task_id ";
	file<<"due_date ";
	file<<"done ";
	file<<"uploade_date ";
	file<<"description ;"<<endl;
	
	file.close();
	
	return 0;
}
