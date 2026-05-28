## C++ Coding Notes

### Vector

Create a vector with fixed size:

```cpp id="mspvr8"
vector<int> v(5);
```

Create a vector with default values:

```cpp id="jzjlwm"
vector<int> v(5, 1);
```

Add element at the end:

```cpp id="dvy3r2"
v.push_back(10);
```

Get vector size:

```cpp id="rwy9jl"
v.size()
```

Check if vector is empty:

```cpp id="0a0g5r"
v.empty()
```


## Dynamic Programming (DP)

Dynamic Programming stores previous results to avoid recomputation.

Example:

```cpp id="qwdmgh"
vector<int> dp(n, 1);
```

Meaning:

* `dp[i]` stores a result for index `i`
* initialized with `1`

Example meaning:

```cpp id="13rz0l"
dp[i]
```

stores:

* longest increasing subsequence ending at index `i`


## Longest Increasing Subsequence (LIS)

Condition for increasing sequence:

```cpp id="dwdjlwm"
if (data[i] > data[j])
```

Update DP value:

```cpp id="ebebya"
dp[i] = max(dp[i], dp[j] + 1);
```

Update global maximum:

```cpp id="q6khbs"
longest = max(longest, dp[i]);
```


## Debugging with `cerr`

Use `cerr` for debug messages.

Example:

```cpp id="m27h1o"
cerr << "Processing value: " << value << endl;
```

Check if vector is empty:

```cpp id="tzbjlwm"
// Debug: check if data is empty
if (data.empty())
{
    cerr << "Error: data is empty" << endl;
    return 0;
}
```

`cerr` is commonly used for:

* debugging
* errors
* checking variable values



## Example Code

```cpp id="ff2omr"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longest_profit(vector<int> data)
{
    // Debug: check if data is empty
    if (data.empty())
    {
        cerr << "Error: data is empty" << endl;
        return 0;
    }

    // dp[i] = longest increasing subsequence ending at i
    vector<int> dp(data.size(), 1);

    int longest = 1;

    for (int i = 1; i < data.size(); i++)
    {
        cerr << "Processing: " << data[i] << endl;

        for (int j = 0; j < i; j++)
        {
            // Check increasing sequence
            if (data[i] > data[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        // Update longest sequence found
        longest = max(longest, dp[i]);
    }

    return longest;
}

int main()
{
    vector<int> data = {-1, 9, 0, 8, -5, 6};

    cout << longest_profit(data) << endl;

    return 0;
}
```


## Example Explanation

Input:

```cpp id="0hzav0"
{-1, 9, 0, 8, -5, 6}
```

One increasing subsequence:

```text id="9fq4hx"
-1, 0, 8
```

Length:

```text id="eqjlwm"
3
```

The program finds the length of the longest increasing subsequence in the vector.


**Que : So, can you tell me the difference between thread and process?**

“A process is an independent running program with its own memory space and resources.
A thread is a lightweight execution unit inside a process. Multiple threads can share the same memory space of the process.

Processes are more isolated and safer, while threads are faster for communication but require synchronization because they share memory.”

“In robotics, we often use multithreading for sensor processing, control loops, perception pipelines, or communication to improve responsiveness and parallelism.”



**Que : Multiprocess computation has pros and cons, What is a thread safety in the multithreading program?** 

“Thread safety means ensuring that multiple threads can access shared resources safely without causing data corruption or unexpected behavior.”

“For example, if two threads modify the same variable simultaneously without synchronization, it can create race conditions. To avoid that, we use mechanisms like mutexes, locks, or atomic operations.”

Simple robotics example:

“For example, if one thread updates sensor data while another thread reads it for motion planning, we need synchronization to avoid inconsistent data.”


**Que : Explain how to define the position of a body in the 3D world? What kind of data structures usually used for that?**

Usually, the position of a body in 3D space is represented using translation and rotation.

Translation is represented with a 3D vector (x,y,z), and orientation can be represented using rotation matrices, Euler angles, or quaternions.

In robotics, we commonly use homogeneous transformation matrices, which are 4x4 matrices combining both rotation and translation.”
For example:

T = R * t 

Where:

R = 3x3 rotation matrix
t = translation vector

You could also mention:


**Que : “Quaternions are often preferred over Euler angles because they avoid gimbal lock and are computationally efficient for interpolation and rotations.”**

And then you can have seven values storage only. So translation is three plus four values of the quaternion. But do you know why it's not commonly used as just three angles? 
 
Why do we need quaternion instead, like four values instead of three angles?
  
It's the problem called the gimbal lock, so-called problem, which is about, because for the rotations, if you just define the rotation.

“Euler angles use three sequential rotations, but they can suffer from gimbal lock, where two rotational axes align and we lose one degree of freedom.

Quaternions avoid this issue and provide smoother and more stable rotation representations, especially for interpolation and continuous 3D rotations.

They are also computationally efficient and commonly used in robotics, ROS, SLAM, and motion planning.”



**Important sorting algorithms commonly asked in C++ interviews:**


| Algorithm        | Avg Time   | Worst Time | Stable | Notes                             |
| ---------------- | ---------- | ---------- | ------ | --------------------------------- |
| Bubble Sort      | O(n²)      | O(n²)      | Yes    | Simple, inefficient               |
| Selection Sort   | O(n²)      | O(n²)      | No     | Minimal swaps                     |
| Insertion Sort   | O(n²)      | O(n²)      | Yes    | Good for small/nearly sorted data |
| Merge Sort       | O(n log n) | O(n log n) | Yes    | Extra memory needed               |
| Quick Sort       | O(n log n) | O(n²)      | No     | Very fast in practice             |
| Heap Sort        | O(n log n) | O(n log n) | No     | Good worst-case guarantee         |
| std::sort        | O(n log n) | O(n log n) | No     | Introsort internally              |
| std::stable_sort | O(n log n) | O(n log n) | Yes    | Preserves order                   |

**Most important for interviews:**

* Quick Sort
* Merge Sort
* Heap Sort
* std::sort