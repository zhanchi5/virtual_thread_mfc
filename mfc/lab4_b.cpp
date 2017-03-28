
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <mutex>
#include <Windows.h>
#include <thread>


using namespace std;

class my_task {

public:
 unsigned int number;

	struct my_data {
		string name;
		string surname;
		unsigned int age;

	};


	my_data student;
	vector <my_data> data_base;


	virtual void get_data() {

		cout << "Enter number of students:" << endl;
		cin >> number;
		for (unsigned int i = 0; i < number; ++i)
		{
			cout << "Enter name" << endl;
			cin >> student.name;

			cout << "Enter surname" << endl;
			cin >> student.surname;

			cout << "Enter age" << endl;
			cin >> student.age;

			data_base.push_back(student);
		}


	}

virtual void print_data(mutex& mtx) {
	mtx.lock();

	while (1)
	{
		for (unsigned int i = 0; i < number; ++i)
		{
			cout << data_base.at(i).name << " " << data_base.at(i).surname << " " << data_base.at(i).age << endl;
		}
		mtx.unlock();

	}

}

void spoil_db(mutex& mtx) {

	while (1)
	{
		mtx.lock();

		data_base.at(0).name = "Bonny";
		data_base.at(0).surname = "Fisher";
		data_base.at(0).surname = 15;

		mtx.unlock();

	}

}

};


int main()
{
	
	mutex mtx;
	my_task my_student;
	my_student.get_data();
	my_student.print_data(mtx);
		



	system("pause");
	return 0;
}
