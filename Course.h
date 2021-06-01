#pragma once
#include<string>
#include "FciVector.h"

using namespace std;

class Course
{
private:
	string courseName;
	string courseCode;
	char courseGrade;
	float coursePoint;
	int courseYear;
	int courseSemester;
public:
	Course();
	void setCourse();
	void printCourseInfo();
	Course& operator =(Course &b);
};

Course::Course()
{
	courseName = " ";
	courseCode = " ";
	courseGrade = ' ';
	coursePoint = 0.0;
	courseYear = 0;
	courseSemester = 0;
}
void Course::setCourse()
{

	cout << "Enter Course Name:  ";
	cin.ignore();
	getline(cin,courseName);
	cout << "Enter Course Code:  ";
	cin.ignore();
	getline(cin,courseCode);
	cout << "Enter Course Grade:  ";
	cin >> courseGrade;
	cout << "Enter Course Point:  ";
	cin >> coursePoint;
	cout << "Enter Course Year:  ";
	cin >> courseYear;
	cout << "Enter Course Semester:  ";
	cin >> courseSemester;
	 
}
void Course::printCourseInfo()
{
	cout << "Course Name : " << courseName << endl;
	cout << "Course Code : " << courseCode << endl;
	cout << "Course Grade : " << courseGrade << endl;
	cout << "Course Point : " << coursePoint << endl;
	cout << "Course Year : " << courseYear << endl;
	cout << "Course Semester : " << courseSemester << endl;
}
Course& Course :: operator =(Course &b) {

	
	courseName = b.courseName;
	courseCode = b.courseCode;
	courseGrade = b.courseGrade;
	coursePoint = b.coursePoint;
	courseYear = b.courseYear;
	courseSemester = b.courseSemester;
	return *this;
}


