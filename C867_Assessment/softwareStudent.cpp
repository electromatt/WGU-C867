#include <iostream>
#include "softwareStudent.h"

using namespace std;


SoftwareStudent::SoftwareStudent():Student() {
	degreeType = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int courseCompletionDays[], Degree degreeProgram) 
	:Student(studentID, firstName, lastName, emailAddress, age, courseCompletionDays){
		degreeType = SOFTWARE;
}

Degree SoftwareStudent::getDegreeProgram() {
	return SOFTWARE;
}

void SoftwareStudent::print() {
	this->Student::print();
	cout << left << "Software" << "\n";
}

SoftwareStudent::~SoftwareStudent() {
	Student::~Student();
}


