#include "functions.h"
#include <direct.h>
#include <errno.h>
#include <fstream>

bool new_structure()
{
    if (!mkdir ("Marcin Wardak"));
    else
    {
		cout << strerror(errno) << endl;
		return 0;
	}
    ofstream new_file ("./Marcin Wardak/tasks.txt");
    if (!new_file.good())
    	cout << strerror(errno) << endl;
    new_file << "task_id\tdue_date\tdone\tupload_date\tdescription";
    new_file.close();
    return !errno;
}
