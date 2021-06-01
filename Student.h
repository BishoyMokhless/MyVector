#pragma once
#include <string>
#include "Course.h"
#include "FciVector.h"


using namespace std;

class Student
{
private:
	string sName;
	int sID;
	string sDepartment;
	int numOfCourses;
	FciVector<Course> sCourses;
public:
	Student();
	void setStudent();
	void printInfo();
	friend istream& operator >>(istream& in, Student &s);
	friend ostream& operator<<(ostream& out, Student &s);
	Student& operator =(Student &b);

};
Student::Student()
{
	sName = " ";
	sID = 0;
	sDepartment = " ";
}
void Student::setStudent()
{
	cout << endl << "Enter Student name : ";
	cin.ignore();
	getline(cin,sName);
	cout << "Enter Student ID : ";
	cin >> sID;
	cout << "Enter Student Department : ";
	cin.ignore();
	getline(cin, sDepartment);
 

	cout << "Enter Number of Student's Courses  : ";
	cin >> numOfCourses;
	for (int i = 0; i < numOfCourses; i++)
	{
		Course test;
		test.setCourse();
		sCourses.push_back(test);
	}

}
void Student::printInfo()
{
	cout << endl << "------------------------------" << endl;
	cout << "Student information : " << endl;
	cout << "Student name : " << sName << endl;
	cout << "Student ID : " << sID << endl;
	cout << "Student Department : " << sDepartment << endl;
	cout << "------------------------------" << endl;
	for (int i = 0; i < numOfCourses; i++)
	{
		cout << "------------------------------" << endl;
		cout << "Course [" << i + 1 << "] information : " << endl;
		sCourses[i].printCourseInfo();
	}


}
istream& operator >>(istream& in, Student &s)
{
	s.setStudent();
	return in;
}
ostream& operator<<(ostream& out, Student &s)
{
	s.printInfo();
	 
	return out;
}
Student& Student :: operator =(Student &b) {

	sName = b.sName;
	sID = b.sID;
	sDepartment = b.sDepartment;
	numOfCourses = b.numOfCourses;
	for (int i = 0; i < numOfCourses; i++)
	{
		Course test;
		test = b.sCourses[i];
		sCourses.push_back(test);
	}
	return *this;
}





