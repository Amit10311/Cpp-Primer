/*
*/
#include <iostream>

int main()
{
    // Accumulates the total of all integers read from standard input.
    int sum = 0;

    // Keep reading integers until input ends; each successful read adds to sum.
    // The semicolon means the loop body is empty on purpose.
    for (int val; std::cin >> val; sum += val);

    // Print the final total.
    std::cout << sum << std::endl;

    return 0;
}