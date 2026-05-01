// Sum of two numbers

#include <iostream>

int main()
{
    std::cout << "Enter two numbers" << std::endl;
    // Declaring and initializing an int variable.
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The sum of " << v1 << "and" << v2 << "is" << v1 + v2 << std::endl;

    // Return 0 to indicate successful execution
    return 0;
}