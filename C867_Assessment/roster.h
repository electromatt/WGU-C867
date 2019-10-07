#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"
#include "softwareStudent.h"
#include "networkStudent.h"
#include "securityStudent.h"

class Roster {

public:
	Roster();
	Roster(int numStudents);
	~Roster();
	void parseThenAdd(string row);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(Degree degreeProgram);
	Student* getStudentAt(int index);

private:
	int lastIndex;
	int numStudents;
	Student** classRosterArray;
};


#endif // !ROSTER_H

int main();
