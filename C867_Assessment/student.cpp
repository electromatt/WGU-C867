#include <iostream>
#include <iomanip>
#include "student.h"
using namespace std;

Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = -1;
	for (int i = 0; i < courseCompletionDaysSize; ++i) { this->courseCompletionDays[i] = -1; }
	this->degreeType = Degree::none;
};
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int courseCompletionDays[]) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < courseCompletionDaysSize; ++i) { this->courseCompletionDays[i] = courseCompletionDays[i]; }
}
Student::~Student() {}

string Student::getStudentID() {return this->studentID;}
string Student::getFirstName() {return firstName;}
string Student::getLastName() {return lastName;}
string Student::getEmailAddress() {return emailAddress;}
int Student::getAge() {return age;}
int* Student::getCourseCompletionDays() { return courseCompletionDays; }
string Student::getStringCourseCompletionDays() {
	string s = "";
	for (int i = 0; i < courseCompletionDaysSize - 1; ++i) {
		s += to_string(this->courseCompletionDays[i]) + ", ";
	}
	s += to_string(courseCompletionDays[courseCompletionDaysSize - 1]);
	return s;
}

void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int resage) { this->age = age; }
void Student::setCourseCompletionDays(int courseCompletionDays[]) { 
	for (int i = 0; i < courseCompletionDaysSize; ++i) { 
		this->courseCompletionDays[i] = courseCompletionDays[i]; 
	}
}

void Student::print() {
	cout << this->getStudentID() << "\t";
	cout << "First Name: " << this->getFirstName() << "\t";
	cout << "Last Name: " << this->getLastName() << "\t";
	cout << "Age: " << this->getAge() << "\t";
	cout << "daysInCourse: {" << this->getStringCourseCompletionDays() << "} \t";
	cout << "Degree Program: ";
}
