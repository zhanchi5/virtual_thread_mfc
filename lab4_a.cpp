
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class my_task {
public:

struct my_data {
        string name;
        string surname;
        unsigned int age;
};


my_data student;


virtual void get_data(){


        cout << "Enter name" << endl;
        cin >> student.name;

        cout << "Enter surname" << endl;
        cin >> student.surname;

        cout << "Enter age" << endl;
        cin >> student.age;

}


virtual void print_data(){

        cout << "Name: " << student.name << endl;
        cout << "Surname: " << student.surname << endl;
        cout << "Age: " << student.age << endl;
}



};


int main()
{

        my_task my_student;

        my_student.get_data();
        my_student.print_data();


        system("pause");
        return 0;
}
