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
