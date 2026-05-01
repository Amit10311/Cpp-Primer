## Preface

You can get an idea of how extensively the new standard has affected C++ by reviewing the New Features Table of Contents, which lists the sections that cover new material and appears on page xxi.

* `auto` - for type inference, are pervasive. 
  - These facilities make the code in this edition easier to read and to understand.
  - Programs (and programmers!) can ignore type details, which makes it easier to concentrate on what the program is intended to do. 

* `smart pointers` and `move-enabled containers`
  - Let us write more sophisticated classes without having to contend with the intricacies of resource management.
  - As a result, we can start to teach how to write your own classes 

  
💻 [C++11]
> **Important Note:** Sections marked with the 💻 icon introduce C++11 features. If your compiler does not fully support C++11, some examples may produce errors. Most core language material remains unchanged and still applies.


### Compiler
A compiler is a program that translates source code (like C or C++) into machine code your computer can run.

1. **GNU Compiler Collection (GCC)**
   * GCC is a collection of compilers, not just one compiler.
   * It supports multiple languages: C, C++, Fortran, etc.
   * For C++, GCC uses the command g++.

2. **g++ compiler**
   * g++ is the GNU C++ compiler driver.
   * You use it to compile C++ files.
   * Example:
    ```bash
     g++ main.cpp -o main
    ```
   * So: `g++` is part of GCC, specialized for C++.
   * `g++` is the command (driver) you use to compile C++ code with GCC — it manages the entire compilation pipeline automatically.

3. **gcc — compiler** command for C files
    ```bash
     gcc main.c -o main   
    ```

4. **GNU compiler**
   * GNU compiler is an informal phrase people use.
   * Usually they mean GCC (or one of its language front-ends like gcc or g++).

5. **Other common compilers**
   * **Clang/LLVM** : Modern compiler toolchain; command for C++ is usually clang++.
   * MSVC (Microsoft Visual C++): Microsoft’s C++ compiler on Windows; command-line tool is cl.

**Summary :**
   * GCC = full compiler suite
   * g++ = the C++ compiler command in GCC
   * “GNU compiler” = usually GCC/g++
   * Clang, MSVC, Intel = alternative compiler families. 


Practical comparison of g++, clang++, and MSVC:

1. Error messages and developer experience
   * **clang++** : Usually the easiest to read error messages, very good suggestions.
   * **g++** : Good diagnostics, sometimes more verbose and harder for beginners.
   * **MSVC** : Improved a lot, especially strong inside Visual Studio.

2. Standards support (C++17, C++20, C++23)
   * **clang++ and g++** : Often adopt new language features quickly on Linux/macOS.
   * **MSVC** : Very strong C++20 support; C++23 support is also progressing fast.
 
3. Compile speed
   * **clang++** : Often fast at compilation, especially in template-heavy code.
   * **g++** : Also fast, sometimes better in some projects, sometimes behind clang.
   * **MSVC** : Can be very fast in Windows projects, especially with precompiled headers and IDE tooling.

4. Tooling and ecosystem
   * **g++** : Common in competitive programming, servers, and GNU/Linux workflows.
   * **clang++** : Excellent static analysis ecosystem (clang-tidy, sanitizers).
   * **MSVC** : Excellent debugger and IDE integration in Visual Studio.



## Why Read This Book?

This book teaches modern C++ from the start, using higher-level language features and the standard library (`string`, `vector`, algorithms) instead of low-level C-style techniques. 

This approach helps you write safer, clearer programs, build good habits early, and understand both what the language does and why it works that way.

Throughout C++ Primer, we emphasize **good style**: We want to help you, the reader, develop good habits immediately and avoid needing to unlearn bad habits as you gain more sophisticated knowledge. 

* We highlight particularly tricky matters and warn about common misconceptions and pitfalls.

<div style="display: flex; align-items: flex-start; gap: 12px;">
   <img src="../images/image_01.png" alt="diagram" width="48"/>
   <aside><strong>Language Fundamentals :</strong> Everyone should read and understand these sections.</aside>
</div>

* **📚** — Marks **advanced or special-purpose** sections. 
    - Safe to skip on a first reading; skim to know the feature exists, *study when needed*.

<div style="display: flex; align-items: flex-start; gap: 12px;">
   <img src="../images/image_02.png" alt="diagram" width="45"/>
   <aside><strong>Tricky but important :</strong> Read these sections carefully, even if their value is not obvious at first.</aside>
</div>

