#include<iostream>
#include<string>
#include"classes/student.hpp"

using namespace std;

int main()
{
   
    Student* student;

    student = new Student;
    student->setCode(1)->setName("ali")->setAvarage(20)->add();    
    student->setCode(2)->setName("reza")->setAvarage(19)->add();
    student->setCode(3)->setName("hossien")->setAvarage(10)->add();
    student->list(); 
     student->setCode(2)->remove()->list();
    if (student->setCode(2)->remove()->fail())
    {
        cout << student->getError() << endl;
    }

    
    /*
    if ( !student->setCode(10)->setName("Masoud")->setAverage(17)->add()->fail() )
    {
        cout << "Success" << endl;
    } 
    else 
    {
        cout << student->getError() << endl;
    }

    if ( student->setName("Omid")->find(Field::Name) )
    {
        student->debug();
    } 
    else
    {
        cout << "NOT FOUND!" << endl;
    }

    if ( student->setAverage(17)->find(Field::Average) )
    {
        student->debug();
    } 
    else
    {
        cout << "NOT FOUND!" << endl;
    }
    */

    delete student;
}   