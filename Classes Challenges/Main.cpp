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
			outFile << data.at(i).GetName() << "\t" << data.at(i).GetRegistrationID() << "\t" << data.at(i).GetYearofStudy() << endl;
		}
		outFile.close();
		return true;
	}
}

std::vector<Student> ReadStudentDetails(std::string dataFile) {
	ifstream inFile{ dataFile, ios::in };
	vector<Student> data;
	if (!inFile) {
		cout << "file not found" << endl;
	}
	else {
		while (!inFile.eof()) {
			
		}
	}

	inFile.close();
	return data;
}



int main() {
	Student stu1("Jeni Watt", "B004568656", "BSc Computing", 1);
	Student stu2("abba", "B00898989", "dancing", 1);
	Student stu3("eltnum 2", "B00438247", "BSc gun", 1);

	vector<Student> boyos, lads;
	boyos.push_back(stu1);
	boyos.push_back(stu2);
	boyos.push_back(stu3);

	WriteStudentDetails(boyos);

	lads = ReadStudentDetails("studentDetails.txt");

	for (int i = 0; i < lads.size(); i++) {
		cout << lads.at(i).GetName() << "\t" << lads.at(i).GetRegistrationID() << "\t" << lads.at(i).GetYearofStudy() << endl;
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

