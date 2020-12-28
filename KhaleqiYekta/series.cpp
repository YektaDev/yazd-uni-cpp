/*
 * Copyright © ۲۰۲۰ Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 * Creation Date: ۲۰۲۰-12-28
 */

/** External Libraries **/
#include <iostream>
#include <string>
#include "console.hpp"

/** Namespaces **/
using namespace std;

/** Function Declarations **/
float getSeries(const float &num);
size_t factorial(const size_t &num);

// Program's Entry Point
int main()
{
    size_t number;
    float seriesResult;

    clearConsole();

    number = askForInt("Enter a number to calculate the series: ");
    seriesResult = getSeries(number);

    // Print the result
    printLine("The result is: " + to_string(seriesResult));

    pauseConsole();

    return 0;
}

float getSeries(const float &num)
{
    return (num > 1) ? (1.0 / (float)factorial(num)) + getSeries(num - 1.0) : num;
}

size_t factorial(const size_t &num)
{
    return (num > 1) ? num * factorial(num - 1) : num;
}
