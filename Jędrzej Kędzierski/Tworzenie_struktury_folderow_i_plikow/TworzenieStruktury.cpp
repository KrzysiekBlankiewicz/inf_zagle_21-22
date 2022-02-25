#include "Funkcje.hpp"

int TworzenieStruktury()
{
	mkdir("./Jedrzej_Kedzierski");
	mkdir("./Jedrzej_Kedzierski/C++");
	
	fstream file;
	
	file.open("./Jedrzej_Kedzierski/C++/tasks.txt", ios::out);
	
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
