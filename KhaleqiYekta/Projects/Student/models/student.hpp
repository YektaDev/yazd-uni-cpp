/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

#include <iostream>
#include <string>
#include <list>
#include <fstream>

using namespace std;

enum Field {Code, Name, Average};

class StudentModel
{
    public:
        int code;
        string name;
        float average;
};

typedef list<StudentModel>::iterator StudentIterator;

class Student
{
    private:
        StudentModel studentModel;
        list<StudentModel> students;

        bool error;
        string errorMessage;

    protected:
public:
    Student();
        ~Student();

        Student* setCode(int code);
        int getCode();
        Student* setName(string name);
        string getName(int code);
        string getName();
        Student* setAverage(float avg);
        float getAverage();

        Student* list();
        Student* add();

        bool find(Field searchField);

        void debug();

        bool fail();
        string getError();
};

Student::Student()
{
    this->students.clear();
    this->error = false;
}

Student::~Student()
{

}

void Student::debug()
{
    cout << endl;
    cout << "************************************************" << endl;
    cout << "Code: " << this->getCode() << endl;
    cout << "Name: " << this->getName() << endl;
    cout << "Average: " << this->getAverage() << endl;
    cout << "************************************************" << endl;
}

Student* Student::setCode(int code)
{
    this->studentModel.code = code;
    return this;
}

int Student::getCode()
{
    return studentModel.code;
}

Student* Student::setName(string name)
{
    this->studentModel.name = name;
    return this;
}

string Student::getName(int code)
{
    return studentModel.name;
}

bool Student::fail()
{
    return this->error;
}

string Student::getError()
{
    return this->error ? this->errorMessage : "";
}

Student* Student::setAverage(float avg)
{
    this->studentModel.average = avg;
    return this;
}

float Student::getAverage()
{
    return this->studentModel.average;
}

Student* Student::list()
{
    if (this->students.empty())
    {
        return this;
    }

    for (StudentIterator it = this->students.begin(); it != this->students.end(); it++)
    {
        cout << "Code: " << it->code << endl;
        cout << "Name: " << it->name << endl;
        cout << "Average: " << it->average << endl;
        cout << endl;
    }

    return this;
}

Student* Student::add()
{
    if (!this->find(Field::Code))
    {
        this->students.push_back(this->studentModel);
    }
    else
    {
        this->error = true;
        this->errorMessage = "Record already exists!";
    }

    return this;
}

bool Student::find(Field searchField)
{
    bool result = false;

    if (this->students.empty())
    {
        return result;
    }

    for (StudentIterator it = this->students.begin(); it != students.end(); ++it)
    {
        if (searchField == Field::Code)
        {
            if (it->code == this->studentModel.code)
            {
                result = true;
                this->studentModel = *it;

                break;
            }
        }
        else if (searchField == Field::Name)
        {
            result = true;
            this->studentModel = *it;

            break;
        }
        else
        {
            result = true;
            this->studentModel = *it;

            break;
        }
    }

    return result;
}
