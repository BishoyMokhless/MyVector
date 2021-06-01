#pragma once
#include <iostream>
#include "FciVector.h"
#include <string>

using namespace std;
template <class T>
class FciVector
{
private:
	int numberOfElements;
	int capacity;
	T* elements;
 
public:
	 

	FciVector()
	{
		capacity = 1;
		elements = new T[1];
		numberOfElements = 0;

	}
	int size()
	{
		return numberOfElements;
	}
	int capacityy()
	{
		return capacity;
	}
	bool empty()
	{
		if (numberOfElements == 0)
			return true;
		else
			return false;
	}
	T& operator [](int index)
	{
		return elements[index];
	}
	T* begin()
	{
		return &elements[0];
	}
	T& front()
	{
		return (elements[0]);
	}
	T& back()
	{
		return elements[numberOfElements-1];

	}
	void insert(T *position, T val)
	{ 
		T* copyArr = new T[numberOfElements+1];
		int  i = 0;
		T* start = elements;
		while (i < numberOfElements+1 && position != start && start != &back()+1)
		{
			
			copyArr[i] = elements[i];
 			i++;
			start++;
		}
		copyArr[i++] = val;
		for (i; i < numberOfElements +1; i++)
		{
			copyArr[i] = elements[i-1];
		}
		delete[] elements;
		elements = new T[numberOfElements + 1];
		elements = copyArr;
		numberOfElements++;
 	}
	void push_back(T val)
	{
		if (numberOfElements == capacity)
		{
			capacity = capacity * 2;
			T* copyArr = new T[capacity];
			for (int i = 0; i < numberOfElements; i++)
			{
				copyArr[i] = elements[i];

			}
			delete[] elements;
			elements = new T[numberOfElements + 1];
			elements = copyArr;
		}
		elements[numberOfElements] = val;
		numberOfElements++;
	}
	void pop_back()
	{
		numberOfElements--;
	}
	void clear()
	{
		numberOfElements = 0;
		capacity = 0;
		delete[] elements;
		elements = new T[1];
	}
	void erase(T* position)
	{
		T* copyArr = new T[numberOfElements-1];
		T* ptr = elements;
		int j = 0;
		for (int i = 0; i < numberOfElements; i++)
		{
			if (position != ptr) 
				copyArr[j++] = elements[i];
			ptr++;
		}
		delete[] elements;
		elements = new T[numberOfElements-1];
		elements = copyArr;
		numberOfElements--;
	}
	void display(T* position)
	{
		int newPosition = position - elements;
 		if (newPosition <= numberOfElements)
			cout << elements[newPosition] << endl;
		else
			cout << "Entery out of bound" << endl;

	}
	void menu(FciVector<T>test)
	{
		bool loop = true;
		while (loop)
		{
			cout << "What kind of operation would you like to perform?\n1. Add element.\n";
			cout << "2. Remove last element.\n3. Insert element at certain position.\n4. Erase element from a certain position.\n";
			cout << "5. Clear.\n6. Display first element.\n7. Display last element.\n";
			cout << "8. Display element at certain position.\n9. Display vector size.\n10. Display vector capacity.\n11. Is empty ? \n";

			int ch;
			cin >> ch;
			while (ch < 1 || ch > 11)
			{
				cout << "Entery out of bound." << endl;
				cin >> ch;

			}

			if (ch == 1)//1. Add element.
			{
				T val;
				cout << "Enter the value you want to add : ";
				cin >> val;
				test.push_back(val);
			}

			else if (ch == 2)//2. Remove last element.
			{
				test.pop_back();
				cout << "Last element removed " << endl;
			}
			else if (ch == 3)//3. Insert element at certain position.
			{
				int position;
				T val;
				cout << "Enter the value you want to enter: ";
				cin >> val;
				cout << "Enter its position: ";
				cin >> position;
				test.insert(test.begin() + position, val);

			}
			else if (ch == 4)//4. Erase element from a certain position.
			{
				int position;
				cout << "Enter the position of the value you want to delete: ";
				cin >> position;
				test.erase(test.begin() + position);

			}
			else if (ch == 5)//5. Clear.
			{
				test.clear();
				cout << "Vector deleted." << endl;
				cout << endl;
			}
			else if (ch == 6)//6. Display first element.
			{
				cout << "The First element is : ";
				T val = test.front();
				cout << val << endl;

			}
			else if (ch == 7)//7. Display last element.
			{
				cout << "The Last element is : ";
				cout << test.back();
				cout << endl;

			}
			else if (ch == 8)//8. Display element at certain position.
			{
				int position;
				cout << "Enter the value position you want to view: ";
				cin >> position;
				cout << "The value of the element =  ";
				test.display(test.begin() + position);
				cout << endl;

			}
			else if (ch == 9)//9. Display vector size.
			{
				cout << "The Vector size =  ";
				cout << test.size();
				cout << endl;
			}
			else if (ch == 10)//10. Display vector capacity.
			{
				cout << "The Vector capacity =  ";
				cout << test.capacityy();
				cout << endl;
			}
			else if (ch == 11)//11. Is empty?
			{
				if (test.empty() == true)
					cout << "Yes, the Vector is empty" << endl;
				else
					cout << "No, the Vector is not empty" << endl;
			}
			cout << "Would you like to perform other operations? (Y/N): ";
			char choice;
			cin >> choice;
			bool flag = true;
 			while (flag)
			{
				if (choice == 'Y' || choice == 'y')
				{
					flag = false;
					loop = true;
				}
				else if (choice == 'N' || choice == 'n')
				{
					flag = false;
					loop = false;
					cout << "Exiting from program..." << endl;
					system("exit");
				}
				else
				{
					cout << "Entery out of bound." << endl;
					flag = true;
					cin >> choice;

				}
			}
		}




	}
	


};
 
