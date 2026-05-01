// Sum of two numbers

#include <iostream>

int main()
{
    std::cout << "Enter two integers: ";
    // Define Variables and Assign values
    int v1 = 0, v2 = 0;
    // Statements 
    if (std::cin >> v1 >> v2) {
        std::cout << "The sum of " << v1 << " and " << v2 << " is " << (v1 + v2) << '\n';
        return 0;
    }

    std::cerr << "Invalid input. Please enter two integers.\n";
    return 1;
}