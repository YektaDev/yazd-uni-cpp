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
        bool filtered;
        StudentModel()
        {
            filtered = false;
        }
};

typedef list<StudentModel>::iterator StudentIterator;

class Student
{
    private:
        StudentModel studentModel;
        list<StudentModel> students;

        bool error;

        string errorMassage;    
    protected:
    public:
        Student();
        ~Student();
        void debug();

        Student* setCode(int code);
        int getCode();
        Student* setName(string name);
        string getName();
        Student* setAverage(float avarage);
        float getAverage();

        Student* list();
        Student* add();
        Student* remove();

        bool find(Field searchField);
        Student* filter(Field filterField);
        

        bool fail();
        Student* setError(string errorMessage);
        Student* clearError();
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
void Student:: debug()
{
    cout << endl;
    cout << "***********************************" << endl;
    cout << "Code: " << this->getCode() << endl;
    cout << "Name: " << this->getName() << endl;
    cout << "Avetage: " << this->getAverage() << endl;
    cout << "**********************************" << endl; 
}
bool Student::fail()
{
    return this->error;
}
string Student::getError()
{
    return this->error ? this->errorMassage : "";
}


Student* Student::setCode(int code)
{
    this->studentModel.code = code;
    return this;
}
int Student::getCode()
{
    return this->studentModel.code;
}
Student* Student::setName(string name)
{
    this->studentModel.name = name;
    return this;
}
string Student::getName()
{
    return this->studentModel.name;
}
Student* Student::setAverage(float average)
{
    this->studentModel.average = average;
    return this;
}
float Student::getAverage()
{
    return this->studentModel.average;
}
Student* Student::list()
{
    if (this->students.size() <= 0)
        return this;

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
    this->clearError();
    if ( !this->find(Field::Code) )
        this->students.push_back(this->studentModel);

    else
        this->setError("The record exists!");

    return this;
}
bool Student::find(Field searchField)
{
    bool result = false;

    if (this->students.size() <= 0)
        return result;

    for (StudentIterator it = this->students.begin(); it != this->students.end(); it++)
    {
        if (searchField == Field::Code)
        {
            if (it->code == this->studentModel.code)
            {
                this->studentModel = *it;
                result = true;
                break;
            }
        }
        else if (searchField == Field::Name)
        {
            if (it->name == this->studentModel.name)
            {
                this->studentModel = *it;
                result = true;
                break;
            }
        }
        else
        {
            if (it->average == this->studentModel.average)
            {
                this->studentModel = *it;
                result = true;
                break;
            }
        }
    }
    return result;
}
Student* Student::clearError()
{
    this->error = false;
    this->errorMassage.clear();
    return this;
}
Student* Student::setError(string errorMessage)
{
    this->error = true;
    this->errorMassage = errorMassage;
    return this;
}
Student* Student::remove()
{
    bool result = false;
    this->clearError();
    for (StudentIterator it = this->students.begin(); it != this->students.end(); it++)
    {
        if (it->code == this->studentModel.code)
        {
            this->students.erase(it);
            result = true;
            break;
        }
    }
    if ( !result )
        this->setError("The record not found!");
    return this;
}
Student* Student::filter(Field filterField)
{
    this->clearError();
    for (StudentIterator it = this->students.begin(); it != this->students.end(); it++)
    {
        it->filtered = false;
        if (filterField == Field::Code)
        {
            if (it->code == this->studentModel.code)
                it->filtered = true;
        }
        else if (filterField == Field::Name)
        {
            if (it->name == this->studentModel.name)
                it->filtered = true;
        }
        else if (filterField == Field::Average)
        {
            if (it->average == this->studentModel.average)
                it->filtered = true;
        }
    }
}