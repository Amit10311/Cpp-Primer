/*
 * Write a program that prompts the user for two integers. Print each number in the range specified by those two integers.
 *
 */
#include <iostream>

int main()
{
  std::cout << "Please enter two integers" << std::endl;
  int num1 = 0, num2 = 0;
  std::cin >> num1 >> num2;

  if (num1 > num2)
  {
    std::cout << "Range [" << num2 << ", " << num1 << "]: ";
    while (num1 >= num2)
    {
      std::cout << num2 << " ";
      ++num2;
    }
  }
else
  {
    std::cout << "Range [" << num1 << ", " << num2 << "]: ";
    while (num1 <= num2)
    {
      std::cout << num1 << " ";
      ++num1;
    }
  }
  return 0;
}