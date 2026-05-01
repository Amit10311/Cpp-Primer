/*
 * Write a program that uses a while to sum the numbers from 50 to 100.
 *
 */
#include <iostream>

int main()
{
    int sum = 0, val = 50;
    while (val <= 100)
    {
        sum += val;
        ++val;
    }
    std::cout << "Sum the numbers from 50 to 100 = " << sum << std::endl;
    return 0;
}