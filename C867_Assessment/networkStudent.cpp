#include <iostream>
#include "networkStudent.h"

using namespace std;

NetworkStudent::NetworkStudent():Student() {
	degreeType = NETWORK;
}

NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int courseCompletionDays[], Degree degreeProgram)
	: Student(studentID, firstName, lastName, emailAddress, age, courseCompletionDays) {
		degreeType = NETWORK;
}

Degree NetworkStudent::getDegreeProgram() {
	return NETWORK;
}

void NetworkStudent::print() {
	this->Student::print();
	cout << left << "Network" << "\n";
}

NetworkStudent::~NetworkStudent() {
	Student::~Student();
}
