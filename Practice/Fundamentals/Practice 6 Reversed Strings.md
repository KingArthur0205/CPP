# Practice 6: Reversed Strings
Complete the solution so that it reverses the string passed into it.

```
'world'  =>  'dlrow'
'word'   =>  'drow'
```

# Solution 1: Double Pointer
Having two variables that point to the left-most and right-most character of the string, swap the characters they hold and have them move towards the center.

```cpp
#include <string>
using namespace std ; 

string reverseString (string str ) {
  string::size_type left = 0, right = str.length() - 1;
  while(right >= left) {
    char temp = str[right];
    str[right] = str[left];
    str[left] = temp;
    ++left, --right;
  }
  return str;
}
```

# Solution 2: Using the reverse algorithm
```cpp
#include <string>
using namespace std ; 

string reverseString (string str ) {
  reverse(str.begin(), str.end());
  return str;
}
```

# Solution 3: Construct a new string using reverse iterators.
```cpp
#include <string>
using namespace std ; 

string reverseString (string str ) {
  return string(str.rbegin(), str.rend());
}
```
