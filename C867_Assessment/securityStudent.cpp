#include <iostream>
#include "securityStudent.h"

using namespace std;

SecurityStudent::SecurityStudent():Student() {
	degreeType = SECURITY;
}

SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int courseCompletionDays[], Degree degreeProgram) 
	: Student(studentID, firstName, lastName, emailAddress, age, courseCompletionDays) {
		degreeType = SECURITY;
}

Degree SecurityStudent::getDegreeProgram() {
	return SECURITY;
}

void SecurityStudent::print() {
	this->Student::print();
	cout << left << "Security" << "\n";
}

SecurityStudent::~SecurityStudent() {
	Student::~Student();
}
