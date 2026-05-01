#include <iostream>
/*
 * While loop
 * We can use a while to write a program to sum the numbers from 1 through 10
 * inclusive.
 */
int main()
{

  int sum = 0, val = 1;
  // keep executing the whi leas long as val is less than or equal to 10
  while (val <= 10) {
    sum += val;    //  assigns sum + val to sum
    // std::cout << "val " << val << std::endl;

    ++val;         // add 1 to val
    // std::cout << "sum " << sum << std::endl;
  }

  std::cout << "Sum of the numbers from 1 through 10 inclusive " << sum
            << std::endl;

  return 0;
}
