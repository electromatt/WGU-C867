#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H

#include "student.h"

class NetworkStudent : public Student {
public:
	NetworkStudent();
	NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int courseCompletionDays[], Degree degreeProgram);

	Degree getDegreeProgram();
	void print();

	~NetworkStudent();
private:
	Degree degreeType;
};



#endif // !NETWORKSTUDENT_H
