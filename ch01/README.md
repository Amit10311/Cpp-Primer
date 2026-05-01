## Section 1.1 Writing a Simple C++ Program.

### Exercise 1.1

> Review the documentation for your compiler and determine what file naming convention it uses.

Compile and run the main program from page 2.

 * [GCC and File Extensions](http://labor-liber.org/en/gnu-linux/development/index.php?diapo=extensions) 
 * [File Types Created for Visual C++ Projects](https://msdn.microsoft.com/en-us/library/3awe4781.aspx)

   ```cpp
   // ex1_1.cpp
   int main()
   {
       return 0;
   }
   ```
  - Ex : `g++ --std=c++14 ex1_1.cpp -o ex1_1` 

### Exercise 1.2

> Exercise 1.2: Change the program to return `-1`. A return value of `-1` is often treated as an indicator that the program failed.

Recompile and rerun your program to see how your system treats a failure indicator from main.

   ```cpp
   // ex1_2.cpp
   int main()
   {
       return -1;
   }
   ```
   - Ex : `g++ --std=c++14 ex1_2.cpp -o ex1_2`
   - Run: `./ex1_2`
   - Check execution status: :` echo $?` => 255 

#### Linux

**255**? why? please look at [Appendix E. Exit Codes With Special Meanings](http://www.tldp.org/LDP/abs/html/exitcodes.html)

* Exit Code Number = 255 => Exit status out of range


## Section 1.2 Input and Output

### Exercise 1.3
> Write a program to print Hello, World on the standard output.

```cpp
// Hello World 

# include <iostream>

int main()
{
    std::cout << "Hello, World"<< std::endl;
    return 0;
}
```

### Exercise 1.4
> Our program used the addition operator, +, to add two numbers. Write a program that uses the multiplication operator, *, to print the product instead.

```cpp
// The product of the two numbers

#include <iostream>

int main()
{
    std::cout << "Enter two numbers" << std::endl;
    // Declaring and initializing an int variable.
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The product of " << v1 << " and " << v2 << " is " << v1 * v2 << std::endl;

    // Return 0 to indicate successful execution
    return 0;
}
```

### Exercise 1.5

> We wrote the output in one large statement. Rewrite the program to use a separate statement to print each operand.

```cpp
// The product of the two numbers, with a seperate statement, to print each oprand. 

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
```

- Ex : `g++ --std=c++14 ex1_5.cpp -o ex1_5`

**Output** 
```bash
Enter two numbers
5 6 
The product of the 5 and 6 is 30
```

### Exercise 1.6
> Explain whether the following program fragment is legal. If the program is legal, what does it do? If the program is not legal, why not? How
would you fix it?

```cpp
int main()
{
  std::cout << "The sum of " << v1;
            << " and " << v2;
            << " is " << v1 + v2 << std::endl;
  return 0;
}
```

**Solution :** It's illegal.

<span style="color:red;font-weight:bold">[ERROR] expected primary-expression before '<<' token</span>

```bash
 error: expected primary-expression before ‘<<’ token
      |             << " and " << v2 ;
      |             ^~
```
```bash       
 error: expected primary-expression before ‘<<’ token
      |             << " is " << v1 * v2 << std::endl;
      |             ^~
```

Fixed it: remove the spare semicolons.

```cpp
std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << std::endl;
```


### Exercise 1.7

> Compile a program that has incorrectly nested comments.
 
```cpp
/*
* comment pairs /* */ cannot nest.
* ''cannot nest'' is considered source code,
* as is the rest of the program
*/
int main()
{
    return 0;
}
```

**Compiled result(g++):**

```bash
error: empty character constant
    3 | * ''cannot nest'' is considered source code,
      |   ^~~~~~~~
error: empty character constant
    3 | * ''cannot nest'' is considered source code,
      |                ^~
error: ‘cannot’ does not name a type
    2 | * comment pairs /* */ cannot nest.
      |                       ^~~~~~
```

### Exercise 1.8

> Indicate which, if any, of the following output statements are legal:
```cpp
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */;
std::cout << /* "*/" /* "/*" */;
```

> After you’ve predicted what will happen, test your answers by compiling a
program with each of these statements. Correct any errors you encounter.

Compiled result(g++):

Corrected? just added a quote:
```cpp
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */";
std::cout << /* "*/" /* "/*" */;
```

**Output:**

    /**/ */ /* 


### [Exercise 1.9](ex1_9.cpp)

> Write a program that uses a while to sum the numbers from 50 to 100 
```cpp
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
```
**Output:**
```bash
Sum the numbers from 50 to 100 = 3825
```

### [Exercise 1.10](ex1_10.cpp)
> In addition to the ++ operator that adds 1 to its operand, there is a decrement operator ( - - ) that subtracts 1. 

> Use the decrement operator to write a while that prints the numbers from ten down to zero.

```cpp
#include <iostream>

int main()
{
  int num = 10;
  while (num >= 0) // Condition true when num >= 0 , then the while will work.
  {
    std::cout << num-- << " ";
  }
  std::cout << std::endl;
  std::cout << "The last number is :" << num ;
  return 0;
}
```

**Output:**
```bash
10 9 8 7 6 5 4 3 2 1 0 
The last number is :-1
```

### [Exercise 1.11](ex1_11.cpp)
> Write a program that prompts the user for two integers. Print each number in the range specified by those two integers.

```cpp
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
```

**Output**
```cpp
Please enter two integers
1 9
Range [1, 9]: 1 2 3 4 5 6 7 8 9
```

### Exercise 1.12
> What does the following for loop do? What is the final value
of sum?
```cpp
int sum = 0;
for (int i = -100; i <= 100; ++i)
    sum += i;
```

the loop sums the numbers from -100 to 100. the final value of sum is zero.

### Exercise 1.13
> Rewrite the exercises from § 1.4.1 (p. 13) using for loops.

Ex1.9:
```cpp
#include <iostream>

int main()
{
    int sum = 0;
    for (int val = 50; val <= 100; ++val) 
    {
    sum += val;
    }
    std::cout << "the sum is: " << sum << std::endl;
    return 0;
}
```

Ex1.10:
```cpp
#include <iostream>

int main()
{
    for (int val = 10; val >= 0; --val)
    {
        std::cout << i << std::endl;
    }
    return 0;
}
```

Ex1.11:
```cpp
#include <iostream>

int main()
{
    std::cout << "please input two integers:\n";
    int small = 0, big = 0;
    std::cin >> small >> big;

    if (small > big)
    {
        int tmp = small;
        small = big;
        big = tmp;
    }

    for (int i = small; i != big; ++i)
        std::cout << i << std::endl;

    return 0;
}
```

```cpp
#include <iostream>

int main()
{
  std::cout << "Please enter two integers" << std::endl;
  int num1 = 0, num2 = 0;
  std::cin >> num1 >> num2;

  if (num1 > num2)
  {
    std::cout << "Range [" << num2 << ", " << num1 << "]: ";
    for (int i = num2; i <= num1; ++i)
        std::cout << i << " ";
  }
else
  {
    std::cout << "Range [" << num1 << ", " << num2 << "]: ";
    for (int i = num1; i <= num2; ++i)
        std::cout << i << " ";
  }
  return 0;
}
```

### Exercise 1.14
> Compare and contrast the loops that used a for with those using a while.

> Are there advantages or disadvantages to using either form?
- [A similar question on Stack Overflow](http://stackoverflow.com/questions/2950931/for-vs-while-in-c-programming)

### Exercise 1.15

> Write programs that contain the common errors discussed in the box on page 16. 

> Familiarize yourself with the messages the compiler generates.

**Syntax Errors**:
```c++
int main(){
    std::cout << "Hello World!" << std::endl // semicolon missed 
    return 0;
}
```

**Type errors**:
```c++
int main(){
    char s = "Hello World!"; // Here char should be std::string
    std::cout << s << endl;
    return 0;
}
```

**Declaration errors**:
```c++
int main(){
    int k = 0;
    std::cout << K << std::endl; // use of undeclared identifier 'K'
    return 0;
}
```


### [Exercise 1.16](ex1_16.cpp)

> Write program that prints the sum of a set of the integers read from `cin`. 

```cpp
#include <iostream>
int main()
{
    int sum = 0;
    for (int val; std::cin >> val; sum += val);
    std::cout << sum << std::endl;

    return 0;
}
```

### Exercise 1.17

> What happens in the program presented in this section if the input values are all equal? What if there are no duplicated values?

If the input values are all equal, it will print a line which shows the count of the number you input.

If there are no duplicated values, when different values input, a new line will be printed if you click `Enter`.

### Exercise 1.18

> Compile and run the program from this section giving it only equal values as input. Run it again giving it values in which no number is repeated.

![run](https://db.tt/F38zExnq)

### Exercise 1.19

> Revise the program you wrote for the exercises in § 1.4.1 (p. 13) that printed a range of numbers so that it handles input in which the first number is smaller than the second.

[code](https://github.com/pezy/Cpp-Primer/blob/master/ch01/ex1_11.cpp)

### Exercise 1.20

> http://www.informit.com/title/032174113 contains a copy of Sales_item.h in the Chapter 1 code directory. Copy that file to your working directory. Use it to write a program that reads a set of book sales transactions, writing each transaction to the standard output.

[Here](ex1_20.cpp) is the code.

Note : C++11 flag need to enable.
For GCC and Clang, this can be done with the `-std=c++11`

### Exercise 1.21
> Write a program that reads two Sales_item objects that have the same ISBN and produces their sum.

The program should check whether the objects have the same ISBN.

[Code](ex1_21.cpp)

### Exercise 1.22

> Write a program that reads several transactions for the same ISBN. Write the sum of all the transactions that were read.

Tips: this program will appear in the section 1.6.

[Here](ex1_22.cpp) is the code.

![run](https://db.tt/UlkuvpAS)

### Exercise 1.23
> Write a program that reads several transactions and counts
how many transactions occur for each ISBN.

Tip: please review the `1.4.4`.

[Here](ex1_23.cpp) is the code.

### Exercise 1.24
> Test the previous program by giving multiple transactions
representing multiple ISBNs. The records for each ISBN should be grouped
together.

`data/book.txt` may be used as the records.

![run](https://db.tt/EeDI7lvN)

### Exercise 1.25
> Using the Sales_item.h header from the Web site,
compile and execute the bookstore program presented in this section.

It is the same as Exercise 1.22.

![run](https://db.tt/C6OOPuzA)
