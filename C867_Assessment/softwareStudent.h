#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H

#include "student.h"

class SoftwareStudent : public Student {
public:
	SoftwareStudent();
	SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int courseCompletionDays[], Degree degreeProgram);
	
	Degree getDegreeProgram();
	void print();

	~SoftwareStudent();
private:
	Degree degreeType;
};


#endif // !SOFTWARESTUDENT_H
