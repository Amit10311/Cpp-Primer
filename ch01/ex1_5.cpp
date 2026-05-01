// Write a program that uses the multiplication operator, *, to print the product, use a separate statement to print each operand.

#include <iostream>

int main()
{

  std::cout << "Enter two numbers" << std::endl;
  float v1 = 0, v2 = 0;

  std::cin >> v1 >> v2;

  std::cout << "The product of the ";
  std::cout << v1;
  std::cout << " and ";
  std::cout << v2;
  std::cout << " is ";
  std::cout << v1 * v2;
  std::cout << std::endl;

  return 0;
}