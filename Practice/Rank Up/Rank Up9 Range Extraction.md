# Rank Up 9: Range Extraction
A format for expressing an ordered list of integers is to use a comma separated list of either

1. individual integers
2. or a range of integers denoted by the starting integer separated from the end integer in the range by a dash, '-'. The range includes all integers in the interval including both endpoints. It is not considered a range unless it spans at least 3 numbers. For example "12,13,15-17"

Complete the solution so that it takes a list of integers in increasing order and returns a correctly formatted string in the range format.

Example:
```c
range_extraction({-10, -9, -8, -6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20});
// returns "-10--8,-6,-3-1,3-5,7-11,14,15,17-20"
```

## Solution: 
```cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 解题思路：
 * 1. 遍历vector，检查当前元素往后数是否能连城3个以上。若能，返回长度，若不能返回-1
 * 2. 检查长度，若长度大于等于3，将对应的范围放入ret。index i+= n
*/

// 检查是否能连成一个范围
size_t checkConnect(size_t startPoint, vector<int>& vec) {
  int length = 1;
  for(size_t i = startPoint; i < vec.size() - 1; ++i) {
    // 检查当前元素+1是否等于下一个元素
    if(vec[i] + 1 == vec[i + 1])
      ++length;
    // 若不等于，退出循环
    else
      break;
  }
  // 当能形成循环时返回长度，否则返回-1
  return length >= 3 ? length : -1;
}


// 将数字变为字符
string convertNumber(int input) {
  // 若input为0，直接返回0
  if(!input)
    return "0";
  
  string ret;
  bool neg = false;
  
  // 若input小于0，将其变为正
  if(input < 0) {
    neg = true;
    input = ~input + 1;
  }
  
  // 将input变为字符串
  while(input) {
    int digit = input % 10;
    input /= 10;
    ret = string(1, digit + '0') + ret;
  }
  
  // 若input为负数，在最前面加上负号
  if(neg)
    ret = "-" + ret;
  
  return ret;
}

std::string range_extraction(std::vector<int> args) {
  string ret;


  for(size_t i = 0; i < args.size(); ++i) {
    int connectLength = 0;
    // 若能连成范围
    if((connectLength = checkConnect(i, args)) != -1) {
      // 生成范围
      string range = convertNumber(args[i]) + "-" + convertNumber(args[i + connectLength - 1]);
      ret += range + ",";

      // 更新i的位置
      i += connectLength - 1;
    } else {
      string elem = convertNumber(args[i]);
      ret+= elem + ",";
    }
  }
  ret.pop_back();
  return ret;
}
```

## Solution 2: Using iterators
```cpp
std::string range_extraction(const std::vector<int> &args) {
    auto fast = args.begin(), slow = args.begin();
    std::string ans;
    while (fast != args.end()) {
        while (fast + 1 != args.end() && *(fast + 1) == *fast + 1) ++fast;
        if (fast - slow >= 2) {
            ans += std::to_string(*slow) + "-" + std::to_string(*fast) + ",";
            slow = fast + 1;
            ++fast;
        } else {
            ans += std::to_string(*slow) + ",";
            fast = slow + 1;
            ++slow;
        }
    }
    if (!ans.empty()) ans.pop_back();
    return ans;
}
```