#include "functions.h"
#include <direct.h>
#include <errno.h>
#include <fstream>
#include <string>
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
bool new_task()
{
	string prev_proj, layout, prev_elements;
	string task, due_date, done, upload_date, description;
	short nr = 1; // nr_projektu
	fstream tasks ("Marcin Wardak/tasks.txt", ios::in);
	if (errno) // blad otwierania pliku z danymi
	{
		cout << endl << strerror(errno) << endl;
		return 0;
	}
	getline (tasks, layout);
	cout << layout;
	for (;getline (tasks, prev_proj); nr ++) // wypisywanie dotychczasowych projektów
		cout << endl << prev_proj;
	task = "task_";
	task += (!(nr/10)?'0':'\0') + to_string(nr);
	cout << endl << task << '\t'; //obecne task_id
	prev_elements = task + '\t'; // dodawanie task do dotychcz. danych
	cin >> due_date; // input due_date
	while (!is_date_correct(due_date))
	{
		cout << "\nNiepoprawna data (poprawny format: dd/mm/rrrr)\n" << layout << endl << prev_elements;
		cin >> due_date;
	}
	prev_elements += due_date + '\t';
	cin >> done; // input done
	while (done != "no" && done != "yes")
	{
		cout << "\nNiepoprawny status (poprawny: no/yes)\n" << layout << endl << prev_elements;
		cin >> done;
	}
	prev_elements += done + '\t';
	cin >> upload_date; // input due_date
	while (!is_date_correct(upload_date))
	{
		cout << "\nNiepoprawna data (poprawny format: dd/mm/rrrr)\n" << layout << endl << prev_elements;
		cin >> upload_date;
	}
	prev_elements += upload_date + '\t';
	getline (cin, description); // zakoñczono wczytywanie danych
	prev_elements += description;
	string path = "Marcin Wardak/";
	path.append(task);
	if (!mkdir (path.c_str()));
    else
		cout << "Folder istnieje\n";
	ofstream readme (path + "/readme.txt");
	readme << description << endl;
	readme.close();
	tasks.close();
	tasks.open ("Marcin Wardak/tasks.txt", ios::out | ios::app);
	tasks << endl << prev_elements;
	tasks.close();
	return !errno;
}
