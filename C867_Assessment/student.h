#ifndef STUDENTH
#define STUDENTH

#include <string>
#include <vector>
#include "degree.h"

using namespace std;

class Student {
public:
	
	const static int courseCompletionDaysSize = 3;

	//Constructor / destructor
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int courseCompletionDays[]);
	~Student();
	
	//Getters
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getCourseCompletionDays();

	virtual Degree getDegreeProgram() = 0;
	virtual void print() = 0;

	//Setters
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setCourseCompletionDays(int courseDays[]);

protected:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int courseCompletionDays[courseCompletionDaysSize];
	Degree degreeType;
};

#endif // !STUDENTH
