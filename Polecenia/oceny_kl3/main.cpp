#include <iostream>
#include "SchoolClass.h"


int main(int argc, char** argv) 
{
	SchoolClass klasa3LOA;
	
	// tu powinien znalezc sie kod ladujacy dane z pliku
	// prawdopodobnie bedzie zawieral miedzy innymi linie:
	// for(...)
	//		...
	// 		file >> klasa3.students[0].firstName;
	// 		file >> klasa3.students[0].lastName;
	//		...
		
	// jezeli ktos czuje sie pewnie, to moze sprobowac napisac w klasie student metode loadData(), 
	// a w klasie SchoolClass metode loadDataForAllStudents
	// i tutaj wywolac jedynie klasa3LOA.loadDataForAllStudents(nazwaPliku.txt);
	
	std::cout << klasa3.calcAverage();
	klasa3.changeMarkForAllStudents();
	std::cout << klasa3.calcAverage();
	
	return 0;
}
