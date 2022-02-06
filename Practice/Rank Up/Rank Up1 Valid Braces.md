# Rank Up 1: Valid Braces
Write a function that takes a string of braces, and determines if the order of the braces is valid. It should return true if the string is valid, and false if it's invalid.

This Kata is similar to the Valid Parentheses Kata, but introduces new characters: brackets [], and curly braces {}. Thanks to @arnedag for the idea!

All input strings will be nonempty, and will only consist of parentheses, brackets and curly braces: ()[]{}.

What is considered Valid?
A string of braces is considered valid if all braces are matched with the correct brace.

Examples
```
"(){}[]"   =>  True
"([{}])"   =>  True
"(}"       =>  False
"[(])"     =>  False
"[({})](]" =>  False
```

## Solution: Use Stack
解题思路：用栈和map解决
1.首先创建一个辅助vector以及map(dict)，vector中存入三种左括号，map中以左括号为key，右括号做value，用来查找
2.遍历字符串:
  a. 查找vector，若当前字符为左括号，压入栈中
  b. 若为右括号(else)，则判断栈中是否有元素且dict[top]是否等于当前元素，若是，则将栈顶元素出栈
  c. else若栈为空，或dict[top] != elem，返回false
```cpp
bool valid_braces(std::string braces) {
    //字典
  map<char, char> mapBraces = { {'(', ')'}, {'[', ']'}, {'{', '}'} };
  vector<char> leftBraces = { '(', '[', '{'};
  stack<char> storage;
  
  for(char elem : braces) {
    //若在左括号vector中找到，则将其放入栈中
    if(find(leftBraces.begin(), leftBraces.end(), elem) != leftBraces.end()) {
      storage.push(elem);
    }
    //若栈不为空，且栈顶括号与当前括号对应，出栈栈顶元素
    else if(!storage.empty() && elem == mapBraces[storage.top()]) {
      storage.pop();
    }
    //若栈顶为空，或栈顶括号与当前括号不匹配，返回false
    else if(storage.empty() || elem != mapBraces[storage.top()]) {
      return false;
    }
  }
  //若栈为空，说明所有字符找到了匹配
  return storage.empty();
}
```