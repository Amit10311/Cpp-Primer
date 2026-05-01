/*
 * Use the decrement operator to write a while that prints the numbers from ten down to zero. (use while)
 */
#include <iostream>

int main()
{
  int num = 10;
  while (num >= 0) // Condition true when num >= 0 , then the while will work.
  {
    std::cout << num-- << " ";
  }
  std::cout << std::endl;
  std::cout << "The last number is :" << num << std::endl;
  return 0;
}