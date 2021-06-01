/*
Bishoy Mokhless Khela AbdAllah
20180072
*/
#include <iostream>
#include "FciVector.h"
#include "Student.h"
#include "Course.h"

using namespace std;
int main()
{ 	
	
 	cout << "Insert type of vector you would like to create: " << endl;
	cout << "1. list of integer\n2. list of character\n3. list of string\n";
	cout << "4. list of float\n5. list of students\n6. Exit\n";
	int choice;
	cin >> choice;
	while (choice<1||choice > 6)
	{
		cout << "Entery out of bound." << endl;
		cin >> choice;

	}


	if (choice == 1)
	{
		FciVector<int> list1;
		cout << "A vector of integar was created successfully." << endl;
		cout << "----------------------------------------------" << endl;
		list1.menu(list1);
 	}
	else if (choice == 2)
	{
		FciVector<char> list2;
		cout << "A vector of character was created successfully." << endl;
		cout << "----------------------------------------------" << endl;
		list2.menu(list2);
		 

	}
	else if (choice == 3)
	{
		FciVector<string> list3;
		cout << "A vector of string was created successfully." << endl;
		cout << "----------------------------------------------" << endl;
		list3.menu(list3);
 
	}
	else if (choice == 4)
	{
		FciVector<float> list4;
		cout << "A vector of float was created successfully." << endl;
		cout << "----------------------------------------------" << endl;
		list4.menu(list4);
 
	}
	else if (choice == 5)
	{
		FciVector<Student> list5;
		cout << "A vector of students was created successfully." << endl;
		cout << "----------------------------------------------" << endl;
		list5.menu(list5);
 
	}

	else if (choice == 6)
	{
		cout << "Exiting from progtam.." << endl;
		system("exit");
	}
	 
	return 0;
}