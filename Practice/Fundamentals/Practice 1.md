# Practice 1: Ascending Order

Your task is to make a function that can take any non-negative integer as an argument and return it with its digits in descending order. Essentially, rearrange the digits to create the highest possible number.

Examples:
Input: 42145 Output: 54421

Input: 145263 Output: 654321

Input: 123456789 Output: 987654321

#Solution 1:
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