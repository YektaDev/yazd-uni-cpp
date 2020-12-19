/*
 *  TODO: [PROGRAM NAME]
 * 
 *  By: YektaDev [Ali Khaleqi Yekta]
 *  Website: Yekta.Dev
 *  Email: Me@Yekta.Dev
 */

// External Libraries
#include <iostream>
#include <string>

// Namespaces
using namespace std;

// Constants
const string defaultStringRequestTitle = "Please enter a text: ";
const string defaultIntRequestTitle = "Please enter a number: ";

// Function Declrations
string askForString(string titleToPrint = defaultStringRequestTitle);
int askForInt(string titleToPrint = defaultIntRequestTitle);
void clearConsole();

// Program's Entry Point
int main()
{
    /* TODO: VARIABLES GO HERE */

    clearConsole();

    /* TODO: CODE GOES HERE */
}

/* TODO: PROGRAM FUNCTIONS GO HERE */

// Return a string which is requested from user, then goes to a new line after the procces is done.
string askForString(string titleToPrint)
{
    string data;

    print(titleToPrint);
    getline(cin, data);
    newLine();

    return data;
}

// Return an integer which is requested from user, then goes to a new line after the procces is done.
int askForInt(string titleToPrint)
{
    int data;

    print(titleToPrint);
    cin >> data;
    newLine();

    return data;
}

// Clear the console (on any OS)
void clearConsole()
{ 
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}
