## C++ Primer 5 Notes and Answers(C++11/14)

[![GitHub issues](https://img.shields.io/github/issues/Mooophy/Cpp-Primer.svg)](https://github.com/Mooophy/Cpp-Primer/issues)
[![GitHub license](https://img.shields.io/badge/license-CC0-blue.svg)](https://raw.githubusercontent.com/Mooophy/Cpp-Primer/master/LICENSE)
[![](https://img.shields.io/badge/%E4%B8%AD%E6%96%87-%E8%AE%A8%E8%AE%BA%E5%8C%BA-yellowgreen.svg)](https://github.com/ReadingLab/Discussion-for-Cpp)
[![](https://img.shields.io/badge/douban-%E5%B0%8F%E7%BB%84-green.svg)](http://www.douban.com/group/532124/)

### Compilers recommended
 * Windows: Visual Studio 2015+ 
 
 * Linux: g++ 5.0+     
```
g++ -std=c++14 some_ex.cpp -o some_ex
```
 
 * Mac: clang++ 3.7+
```
clang++ -std=c++1y some_ex.cpp -o some_ex
```

### Contents

- [Chapter 1. Getting Started](ch01/README.md)
- Part I: The Basics
  - [Chapter 2. Variables and Basic Types](ch02/README.md)
  - [Chapter 3. Strings, Vectors, and Arrays](ch03/README.md)
  - [Chapter 4. Expressions](ch04/README.md)
  - [Chapter 5. Statements](ch05/README.md)
  - [Chapter 6. Functions](ch06/README.md)
  - [Chapter 7. Classes](ch07/README.md)
- Part II: The C++ Library
  - [Chapter 8. The IO Library](ch08/README.md)
  - [Chapter 9. Sequential Containers](ch09/README.md)
  - [Chapter 10. Generic Algorithms](ch10/README.md)
  - [Chapter 11. Associative Containers](ch11/README.md)
  - [Chapter 12. Dynamic Memory](ch12/README.md)
- Part III: Tools for Class Authors
  - [Chapter 13. Copy Control](ch13/README.md)
  - [Chapter 14. Overloaded Operations and Conversions](ch14/README.md)
  - [Chapter 15. Object-Oriented Programming](ch15/README.md)
  - [Chapter 16. Templates and Generic Programming](ch16)
- Part IV:  Advanced Topics
  - [Chapter 17. Specialized Library Facilities](ch17)
  - [Chapter 18. Tools for Large Programs](ch18)
  - [Chapter 19. Specialized Tools and Techniques](ch19)


### Reference
- [C++ Primer 5 Answers(C++11/14)](https://github.com/Mooophy/Cpp-Primer)
- [Cpp Primer Notes & Answers](https://github.com/applenob/Cpp_Primer_Practice/tree/master)
- [Cpp Primer Notes](https://github.com/czs108/Cpp-Primer-5th-Notes-CN/tree/master)

**When to choose**
- If you are still building fundamentals: start with C++ Primer.
- If you already write C++ comfortably and want production-level skills: use Professional C+

**Depth and scope**
- C++ Primer: fundamentals, core language, STL basics, good foundation.
- Professional C++: larger scope, architecture, advanced techniques, libraries, robustness, professional practices.

Primer teaches you how to speak C++ well; Professional C++ teaches you how to build serious software with it.




----
### ROS2-Oriented Study Roadmap for C++ Primer (5th Edition)

#### Phase A – Core (Must Master)

- Ch 1–7 → Basics, references, const, functions
- **Ch 9** → Sequential containers (`vector`, `deque`, `list`)
- Ch 10 → Generic algorithms
- **Ch 11** → Associative containers (`map`, `unordered_map`)

  ⇒ ROS2 uses STL everywhere.  

#### Phase B – Critical for ROS2

- **Ch 12** → Dynamic memory (VERY IMPORTANT)
    - `shared_ptr`
    - `unique_ptr`
    - RAII
- **Ch 13** → Copy control (move semantics, Rule of 5)
- **Ch 15** → OOP
- **Ch 16** → Templates (basic understanding)






----
### Recommended path for ROS2:

1. **C++ Primer 5th (START HERE)**
    - Foundation: variables, functions, STL, basics
    - Essential for everything that follows
    - Timescale: 3–4 months

2. Programming: Principles and Practice Using C++ 2nd (OPTIONAL)
    - By Bjarne Stroustrup (C++ creator)
    - Good for design thinking & philosophy
    - Can skip if you're comfortable with Primer fundamentals

3. **Professional C++ 4th (AFTER Primer)**
    - Real-world patterns, architecture, best practices
    - Modern C++ (closer to C++17/20)
    - Timescale: 2–3 months

4. **C++ Concurrency in Action 2nd (LAST)**
    - Multithreading, synchronization, parallel programming
    - Important for ROS2 (heavily concurrent)
    - Requires solid C++ foundation first
    - Timescale: 1–2 months