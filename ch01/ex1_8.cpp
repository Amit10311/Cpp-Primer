#include <iostream>
/*
* Indicate which, if any, of the following output statements are legal:
*/
int main()
{
  std::cout << "/*";
  std::cout << "*/";

  std::cout << /* "*/" */";

  std::cout << /*  "*/"  /* "/*" */;
  return 0;
}