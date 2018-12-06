/*
* Main.cpp
*
* Version information v0.1
* Author: Dr. Shane Wilson
* Date: 8/10/2017
* Description: Driver to test the student class
* Copyright notice
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "Student.h"
#include "Module.h"
#include "Person.h"
#include "Lecturer.h"

using namespace std;


bool WriteStudentDetails(std::vector<Student> &data) {

	ofstream outFile{ "studentData.txt", ios::out };
	if (!outFile) {
		cout << "file not found" << endl;
		outFile.close();
		return false;
	}
	else {
		for (int i = 0; i < data.size(); i++) {
			outFile << quoted(data.at(i).GetName()) << "\t" << quoted(data.at(i).GetRegistrationID()) << "\t" << quoted(data.at(i).GetCourse()) << "\t" << data.at(i).GetYearofStudy() << endl;
		}
		outFile.close();
		return true;
	}
}

std::vector<Student> ReadStudentDetails(std::string dataFile) {
	ifstream inFile{ dataFile, ios::in };
	std::string name, regNo, course, temp;
	int year;
	vector<Student> data;
	if (!inFile) {
		cout << "file not found" << endl;
	}
	else {
		while (!inFile.eof()) {
			inFile >> quoted(name) >> quoted(regNo) >> quoted(course) >> year;
			data.push_back(Student(name, regNo, course, year));
		}
	}

	inFile.close();
	return data;
}



int main() {
	Student stu1("Jeni Watt", "B004568656", "BSc Computing", 1);
	Student stu2("Eoin Porter", "B00898989", "BSc Computer Science", 1);
	Student stu3("Ryan Grant", "B00438247", "BSc FGC", 1);

	vector<Student> students, fromFile;
	students.push_back(stu1);
	students.push_back(stu2);
	students.push_back(stu3);

	WriteStudentDetails(students);

	fromFile = ReadStudentDetails("studentData.txt");

	for (int i = 0; i < fromFile.size(); i++) {
		cout << fromFile.at(i).GetName() << "\t" << fromFile.at(i).GetRegistrationID() << "\t" << quoted(fromFile.at(i).GetCourse()) << "\t" << fromFile.at(i).GetYearofStudy() << endl;
	}
	//Create a lecturer object
	//Lecturer him{ "David Marsh", "dangermouse@io.com", "11009555", "Dangerology" };
	//
	//Create a pointer of person class and point it at the Lecturer object
	//Person* pPtr = &him;
	//
	//Call to String. 
	//cout << pPtr->ToString();
	//With virtual functions the version called is based on the type of the object, not the pointer

	//Create a pointer of person class and point it at the student object
	//Student stu1("Jeni Watt", "B004568656", "BSc Computing", 1);
	//
	//pPtr = &stu1;
	//cout << pPtr->ToString();

	//Always set pointers to nullptr when you are finished using them
	//pPtr = nullptr;

	return 0;
}

