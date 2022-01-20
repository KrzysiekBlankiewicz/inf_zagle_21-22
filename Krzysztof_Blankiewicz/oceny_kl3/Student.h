#include <string>
class Student
{
	public:
	int index;
	std::string firstName;
	std::string lastName;
	Student* myFriend;
	int mark;

	void changeMark();
};
