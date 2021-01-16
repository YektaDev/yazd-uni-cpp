/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

/**
 * @file display.cpp
 * @brief A program which displays some text to user.
 */

/** External Libraries **/
#include <iostream>
#include <string>
#include "console.hpp"

/** Namespaces **/
using namespace std;

/** Function Declarations **/
void display(string str);
void display(string str, bool newLine);

// Program's Entry Point
int main()
{
    clearConsole();

    // Test cases
    display("Hello World!", true);
    display("Hello Class!", false);
    display("Hello Teacher!");

    return 0;
}

// Displays a text to user
void display(string str)
{
    cout << str;
}

// Displays a text to user
void display(string str, bool newLine)
{
    display(str);

    if (newLine)
    {
        cout << endl;
    }
}
