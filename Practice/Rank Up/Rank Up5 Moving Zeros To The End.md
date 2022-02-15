# Rank Up5: Moving Zeros To The End
Write an algorithm that takes an array and moves all of the zeros to the end, preserving the order of the other elements.

```cpp
move_zeros({1, 0, 1, 2, 0, 1, 3}) // returns {1, 1, 2, 1, 3, 0, 0}
```

## Solution 1: Double Pointer
```cpp
#include <vector>

using namespace std;

std::vector<int> move_zeroes(const std::vector<int>& input) {
  int startPtr = 0, endPtr = input.size() - 1;
  vector<int> ret(input.size());
  for(auto &elem : input) {
    if(!elem) 
      ret[endPtr--] = 0;
    else
      ret[startPtr++] = elem;
  }
 
  return ret;
}
```

## Solution 2: Use fill and remove
1. Construct a new vector from input
2. remove all of the elements in the new vector using the remove algorithm. The function returns an iterator to the end of non-zero vector
3. Fill the rest of the vector with 0.
```cpp
clude <vector>
#include <algorithm>

using namespace std;

std::vector<int> move_zeroes(const std::vector<int>& input) {
  vector<int> ret(input);
  fill(remove(ret.begin(), ret.end(), 0) , ret.end(), 0);
  return ret;
}
```