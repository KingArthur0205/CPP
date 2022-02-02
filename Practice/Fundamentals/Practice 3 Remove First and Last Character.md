# Practice 3: Remove First and Last Character
It's pretty straightforward. Your goal is to create a function that removes the first and last characters of a string. You're given one parameter, the original string. You don't have to worry with strings with less than two characters.

## Solution 1: Construct Another String
```cpp
#include <string>
#include <algorithm>

using namespace std; 

string sliceString (string str ) {
  string ret(str.begin() + 1, str.end() - 1);
  return ret;
}
```

## Solution 2: Use the erase Member
```cpp
#include <string>

using namespace std; 

string sliceString (string str )
{
  str.erase(str.begin());
  str.erase(str.length() - 1);
  return str; 
}
```