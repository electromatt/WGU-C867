#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include "student.h"
#include "softwareStudent.h"
#include "roster.h"
#include <regex>

using namespace std;

Roster::Roster() {
	this->numStudents = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int numStudents) {
	this->numStudents = numStudents;
	this->lastIndex = -1;
	this->classRosterArray = new Student * [numStudents];
}

Roster::~Roster() {
}

void Roster::parseThenAdd(string row) {
	try {
		if (lastIndex < numStudents) {
			lastIndex++;
			Degree degreeType;

			//Parse through students delimiting on comma
			//Student ID
			int rhs = row.find(",");
			string sID = row.substr(0, rhs);

			//First name
			int lhs = rhs + 1;
			rhs = row.find(",", lhs);
			string sFirst = row.substr(lhs, rhs - lhs);

			//Last name
			lhs = rhs + 1;
			rhs = row.find(",", lhs);
			string sLast = row.substr(lhs, rhs - lhs);

			//Email
			lhs = rhs + 1;
			rhs = row.find(",", lhs);
			string sEmail = row.substr(lhs, rhs - lhs);

			//Age
			lhs = rhs + 1;
			rhs = row.find(",", lhs);
			int sAge = stoi(row.substr(lhs, rhs - lhs));

			//courseCompletionDays
			lhs = rhs + 1;
			rhs = row.find(",", lhs);
			int sDay1 = stoi(row.substr(lhs, rhs - lhs));

			lhs = rhs + 1;
			rhs = row.find(",", lhs);
			int sDay2 = stoi(row.substr(lhs, rhs - lhs));

			lhs = rhs + 1;
			rhs = row.find(",", lhs);
			int sDay3 = stoi(row.substr(lhs, rhs - lhs));

			//Degree
			lhs = rhs + 1;
			rhs = row.find(",", lhs);
			if (row.substr(lhs, rhs - lhs) == "SOFTWARE") { degreeType = SOFTWARE; }
			else if (row.substr(lhs, rhs - lhs) == "NETWORK") { degreeType = NETWORK; }
			else if (row.substr(lhs, rhs - lhs) == "SECURITY") { degreeType = SECURITY; }
			else {
				throw runtime_error("Not a valid degree type.");
			}

			add(sID, sFirst, sLast, sEmail, sAge, sDay1, sDay2, sDay3, degreeType);
		}
	}
	catch (runtime_error & excpt) {
		cout << excpt.what();
		cout << "Cannot parse data. Exiting." << endl;
		exit(1);
	}

}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram) {
	int daysInCourse[Student::courseCompletionDaysSize];
	daysInCourse[0] = daysInCourse1;
	daysInCourse[1] = daysInCourse2;
	daysInCourse[2] = daysInCourse3;
	switch (degreeProgram) {
		case SOFTWARE:
			classRosterArray[lastIndex] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
			break;
		case NETWORK:
			classRosterArray[lastIndex] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
			break;
		case SECURITY:
			classRosterArray[lastIndex] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
			break;
		default:
			break;
	}
}

void Roster::remove(string studentID) {
	bool found = false;
	cout << "Removing " << studentID << "." << endl;
	for (int i = 0; i <= lastIndex && !found; ++i) {
		if (this->classRosterArray[i]->getStudentID() == studentID) {
			found = true;
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			lastIndex--;
		}
		else if(i >= this->lastIndex && !found){
			cout << "Could not find " << studentID << "." << endl;
		}
	}
}

void Roster::printAll() {
	for (int i = 0; i <= this->lastIndex; ++i) {
		(this->classRosterArray)[i]->print();
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	bool found = false;
	for (int i = 0; i <= lastIndex && !found; ++i) {
		if (this->classRosterArray[i]->getStudentID() == studentID) {
			found = true;
			int* days = this->classRosterArray[i]->getCourseCompletionDays();
			cout << "Average days in course for studentID: " << studentID << " is " << (days[0] + days[1] + days[2]) / 3 << endl;
		}
		else if (i >= this->lastIndex && !found) {
			cout << "Could not find " << studentID << "." << endl;
		}
	}
}

void Roster::printInvalidEmails() {
	const regex pattern("(\\w.+)@(\\w+\\.(\\w+))");
	cout << "Invalid Emails: " << endl;
	for (int i = 0; i <= lastIndex; ++i) {
		string email = this->classRosterArray[i]->getEmailAddress();
		if (!regex_match(email, pattern)) {
			cout << email << endl;
		}
	}
}

void Roster::printByDegreeProgram(Degree degreeProgram) {
	for (int i = 0; i <= lastIndex; ++i) {
		if (this->classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			(this->classRosterArray)[i]->print();
		}
	}
}

Student* Roster::getStudentAt(int index) {
	return classRosterArray[index];
}



int main() {
	cout << "Course Title: Scripting and Programming - Applications – C867" << endl;
	cout << "Programming language used: C++" << endl;
	cout << "Student ID: 000928567" << endl;
	cout << "Name: Matthew Druckhammer" << endl << endl;

	int numStudentData = 5;
	const string studentData[5] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Matthew,Druckhammer,mdruck6@wgu.edu,31,15,10,20,SOFTWARE"
	};

	Roster* classRoster = new Roster(numStudentData);
	for (int i = 0; i < numStudentData; ++i) {
		classRoster->parseThenAdd(studentData[i]);
	}

	classRoster->printAll();
	classRoster->printInvalidEmails();
	//loop through classRosterArray and for each element:
	for (int i = 0; i < numStudentData; ++i) {
		classRoster->printAverageDaysInCourse(classRoster->getStudentAt(i)->getStudentID());
	}
	classRoster->printByDegreeProgram(SOFTWARE);
	classRoster->remove("A3");
	classRoster->remove("A3");

	classRoster->~Roster();
}


