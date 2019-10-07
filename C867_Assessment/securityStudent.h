#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H

#include "student.h"

class SecurityStudent : public Student {
public:
	SecurityStudent();
	SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int courseCompletionDays[], Degree degreeProgram);

	Degree getDegreeProgram();
	void print();

	~SecurityStudent();
private:
	Degree degreeType;
};



#endif // !SECURITYSTUDENT_H
