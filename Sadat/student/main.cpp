#include <iostream>
#include <list>
#include <fstream>
#include "models/student.hpp"

using namespace std;

int main()
{
    Student* student;
    student = new Student;

    student->setCode(1)->setName("ali")->setAverage(15.8)->add();

    if (student->setCode(1)->setName("reza")->setAverage(18.5)->add()->fail())
    {
        SetConsoleTextAttribute(console, 4);
        cout << student->getError() << endl;
        SetConsoleTextAttribute(console, 7);
    }
    else
    {
        SetConsoleTextAttribute(console, 2);
        cout << "Student information was added successfuly" << endl;
        SetConsoleTextAttribute(console, 7);
    }
    
    student->setCode(2)->setName("pouya")->setAverage(18)->add();
    student->setCode(3)->setName("mohsen")->setAverage(19)->add();
    student->list();
    cout << endl;
    student->remove(2)->list();
    cout << endl;

    if (student->setName("pouya")->find(Field::Name))
    {
        student->debug();
    }
    else
    {
        SetConsoleTextAttribute(console, 4);
        cout << "NOT FOUND!" << endl;
        SetConsoleTextAttribute(console, 7);
    }
    

    delete student;
}