# C++11 New Features (from C++ Primer 5th Edition)

## Index

- [New Types and Type Features](#new-types-and-type-features)
- [Auto and Decltype](#auto-and-decltype)
- [Containers and Iterators](#containers-and-iterators)
- [Initialization](#initialization)
- [Functions](#functions)
- [Classes and Constructors](#classes-and-constructors)
- [Smart Pointers and Memory](#smart-pointers-and-memory)
- [Range-based for Loop](#range-based-for-loop)

---

## 1. New Types and Type Features

### `long long` Type
- **Guaranteed** to be at least 64 bits (at least 8 bytes)
- Provides larger integer storage than `int` or `long`

### `nullptr` Literal
- **Null pointer constant** (replaces `NULL` macro)
- Type-safe: has type `std::nullptr_t`
- Works with pointers of any type
```cpp
int* p = nullptr;  // Better than NULL or 0
```

### Type Alias Declarations
- **`using` keyword** for type aliases (new syntax)
```cpp
using pstring = string*;  // Alias for string pointer
using int_array = array<int, 4>;  // Alias for array type
```

---

## 2. Auto and Decltype

### `auto` Type Specifier
- **Compiler deduces type** from initializer
- Simplifies declarations, especially for complex types
```cpp
auto val = 3.14;        // double
auto it = v.begin();    // iterator type
auto sz = v.size();     // size_t
```

### `decltype` Type Specifier
- **Returns the type** of an expression (without evaluating it)
- Useful for template programming and complex type declarations
```cpp
decltype(f()) result;   // Type of f()'s return value
auto add(int x, int y) -> decltype(x + y) { return x + y; }
```

---

## 3. Containers and Iterators

### New Container: `array<T, N>`
- **Fixed-size array** with STL interface
- Faster than `vector` (no dynamic allocation)
```cpp
array<int, 4> arr = {1, 2, 3, 4};
```

### New Container: `forward_list<T>`
- **Singly-linked list** (lighter than `list`)
- No `rbegin()`, `rend()`, or `size()` member

### Container `cbegin()` and `cend()`
- **Constant iterators** (even on non-const containers)
- Guaranteed to return `const_iterator`
```cpp
auto it = v.cbegin();  // const_iterator, not iterator
```

### Library `begin()` and `end()` Functions
- **Non-member versions** of `begin()` and `end()`
- Work on arrays and containers uniformly
```cpp
int arr[] = {1, 2, 3};
auto first = begin(arr);  // Works on plain arrays too
```

### Container `emplace` Members
- **Construct elements in-place** (more efficient than `insert`/`push_back`)
- Avoids temporary copies
```cpp
v.emplace_back(args);    // Constructs directly in vector
v.emplace(it, args);     // Constructs in middle
```

### `initializer_list<T>` Class
- **Container of const values** initialized from braced list
- Allows constructors to accept `{...}` syntax
```cpp
vector<int> v = {1, 2, 3, 4};  // Uses initializer_list
```

---

## 4. Initialization

### List Initialization (Braced Initialization)
- **Uniform initialization syntax** using `{...}`
- Works with any type; prevents narrowing conversions
```cpp
int a = 5;           // Old style
int a{5};            // New: list initialization
vector<int> v{1, 2, 3};
```

### In-Class Initializers
- **Initialize members inside class definition**
- Used as default if constructor doesn't initialize
```cpp
class X {
    int val = 10;  // In-class initializer
};
```

### Assignment from Braced List
- **Assign values using braced list** to containers
```cpp
vector<int> v;
v = {1, 2, 3};  // Replaces v with {1, 2, 3}
```

---

## 5. Functions

### Trailing Return Type
- **Return type after parameter list** (especially useful with `decltype`)
```cpp
auto func(int x, int y) -> decltype(x + y) { return x + y; }
```

### `constexpr` Functions
- **Function evaluated at compile-time** if arguments are constants
- Enables constant expressions in more contexts
```cpp
constexpr int square(int x) { return x * x; }
int arr[square(5)];  // Size 25 (compile-time)
```

### Library `initializer_list` Parameter
- **Functions can accept braced lists**
```cpp
void print(initializer_list<int> il) { ... }
print({1, 2, 3});
```

### Return Type Deduction with `auto`
- **Return type deduced from return statement** (C++14 and later)
```cpp
auto add(int x, int y) { return x + y; }
```

---

## 6. Classes and Constructors

### Default Constructor with `= default`
- **Explicitly request compiler-generated default constructor**
```cpp
class X {
public:
    X() = default;  // Use synthesized default constructor
};
```

### Delegating Constructors
- **One constructor calls another** to avoid code duplication
```cpp
class X {
public:
    X() : X(0) {}           // Delegates to X(int)
    X(int val) { ... }      // Target constructor
};
```

### In-class Initializers for Members
- **Default initialize class members** in the class body
```cpp
class Account {
    string owner = "";      // In-class initializer
    double balance = 0.0;
};
```

### `constexpr` Constructors
- **Constructor that can run at compile-time**
- Allows creation of `constexpr` objects
```cpp
constexpr Point(int x, int y) : xval(x), yval(y) {}
constexpr Point p(1, 2);  // Compile-time object
```

---

## Smart Pointers and Memory

### `unique_ptr<T>`
- **Exclusive ownership** of dynamically allocated object
- Cannot copy, can move
```cpp
unique_ptr<int> p(new int(10));
unique_ptr<int> q = move(p);  // Transfer ownership
```

### `shared_ptr<T>`
- **Shared ownership** via reference counting
- Object destroyed when last `shared_ptr` is destroyed
```cpp
shared_ptr<int> p(new int(10));
shared_ptr<int> q = p;  // Both own the object
```

### `nullptr` Literal
- **Type-safe null pointer** (replaces NULL)
```cpp
int* p = nullptr;
shared_ptr<int> sp = nullptr;
```

### Using `auto` or `decltype` for Type Abbreviation
- **Simplify declarations** of complex pointer/iterator types
```cpp
vector<int> v;
auto it = v.begin();  // auto deduces iterator type
auto ptr = make_shared<int>(10);  // Cleaner than explicit type
```

---

## 7. Range-based for Loop

### Range for Statement
- **Iterate over container elements** without explicit iterator
- Works on arrays, containers, and `initializer_list`
```cpp
vector<int> v = {1, 2, 3};
for (int val : v) {
    cout << val << " ";  // 1 2 3
}

for (auto& elem : v) {   // Reference to avoid copy
    elem *= 2;
}
```

### Range for with Containers
- **Automatically calls `begin()` and `end()`**
- Works with `array`, `vector`, `list`, all STL containers
```cpp
for (const auto& x : my_container) { ... }
```

---

## 8. Move Semantics (Related to C++11)

### Move Semantics Basics
- **Rvalue references (`T&&`)** enable efficient resource transfer
- Avoid expensive copies for temporary objects
```cpp
vector<int> v1 = {1, 2, 3};
vector<int> v2 = move(v1);  // Move instead of copy
```

### Rule of Five
- In C++11, define (or delete) all five:
  1. Destructor
  2. Copy constructor
  3. Copy assignment operator
  4. Move constructor
  5. Move assignment operator

---

## 9.  Notable C++11 Features

### `using` for Type Aliases
- Modern alternative to `typedef`
```cpp
using pint = int*;
using map_t = map<string, int>;
```

### Rounding Rules for Division
- **Truncation towards zero** (consistent behavior)
```cpp
-7 / 4 = -1  // Not -2 in C++11
```

### `sizeof` Applied to Class Members
- **Get size without creating object instance**
```cpp
sizeof(Sales_item::units_sold);
```

### `nullptr` in Function Overloads
- **Distinguish pointer parameters from integer parameters**
```cpp
void f(int);         // Called with 0
void f(int*);        // Called with nullptr
f(nullptr);  // Calls f(int*), not f(int)
```

---

## Summary of Key Benefits

1. **Type Safety**: `auto`, `decltype`, `nullptr` reduce errors
2. **Performance**: Move semantics, `emplace`, `constexpr` avoid unnecessary copies
3. **Readability**: Range-for, list initialization, delegating constructors simplify code
4. **Memory**: Smart pointers (`unique_ptr`, `shared_ptr`) for safer dynamic allocation
5. **Flexibility**: Trailing return types, `constexpr` for compile-time computation
