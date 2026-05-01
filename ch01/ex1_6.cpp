#include <iostream>
/* Explain whether the following program fragment is legal.
* If the program is legal, what does it do? 
* If the program is not legal, why not? How
*/
int main()
{

  std::cout << "Enter two numbers" << std::endl;
  float v1 = 0, v2 = 0;
  std::cin >> v1 >> v2;

  std::cout << "The sum of the " << v1;
            << " and " << v2 ;
            << " is " << v1 * v2 << std::endl;

  return 0;
}