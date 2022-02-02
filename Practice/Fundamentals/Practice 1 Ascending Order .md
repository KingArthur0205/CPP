# Practice 1: Ascending Order

Your task is to make a function that can take any non-negative integer as an argument and return it with its digits in descending order. Essentially, rearrange the digits to create the highest possible number.

Examples:
Input: 42145 Output: 54421

Input: 145263 Output: 654321

Input: 123456789 Output: 987654321

## Solution 1:
1. Store every digit of the number into a vector
2. Sort the vector in descending order.
3. Reassemble all of the digits into a number.
``` cpp
#include <cinttypes>
#include <iostream>
#include <vector>


bool desc(uint64_t a, uint64_t b) {
  return a > b;
}

uint64_t descendingOrder(uint64_t a)
{
  std::vector<uint64_t> vec;
  do {
    vec.push_back(a % 10);
    a /= 10;
  } while (a);
  
  uint64_t ret = 0;
  sort(vec.begin(), vec.end(), desc);
  for(auto &digit : vec)
    ret = ret * 10 + digit;
  return ret;
}
```
## Solution 2:
1. Convert the unsigned number into a string.
2. Sort the string according to the ASCII code of characters.('9' is greater than '0')
3. Convert the string back to a number using stoul() or stoull()
``` cpp
#include <cinttypes>
#include <string>

bool desc(char a, char b) {
  return a > b;
}

uint64_t descendingOrder(uint64_t a)
{
  std::string num = std::to_string(a);
  sort(num.begin(), num.end(), desc);
  return std::stoul(num);
}
```
