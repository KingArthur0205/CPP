# Rank Up4: Stop Spinning My Words
Write a function that takes in a string of one or more words, and returns the same string, but with all five or more letter words reversed (Just like the name of this Kata). Strings passed in will consist of only letters and spaces. Spaces will be included only when more than one word is present.

Examples: spinWords( "Hey fellow warriors" ) => returns "Hey wollef sroirraw" spinWords( "This is a test") => returns "This is a test" spinWords( "This is another test" )=> returns "This is rehtona test"

# Solution:
1. Construct a string stream. Read every string into a buffer.
2. Evaluate if the buffer's length is greater or equal than 5, if yes, call reverse()
3. Concatenate the buffer onto our ret string
4. Pop back the last char of the string as it is a ' '.
```cpp
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

std::string spinWords(const std::string &str) {
  istringstream ss(str);
  string buffer;
  string ret;
  
  while(ss >> buffer) {
    if(buffer.length() >= 5) {
      reverse(buffer.begin(), buffer.end());
    }
    ret += buffer + " ";
  }
  ret.pop_back();
  
  return ret;
}
```