#include <iostream>

using namespace std;

int main()
{
    int number = 100;
    // & = Reference operator     * = Dereference operator
    int *ptr = &number;     
        
    cout << number << endl;
    cout << ptr << endl;
    cout << *ptr << endl;

    number++;
    (*ptr)++;
    cout << *ptr << endl;
}