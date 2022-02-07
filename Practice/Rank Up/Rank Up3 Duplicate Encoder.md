# Rank Up3: Duplicate Encoder
The goal of this exercise is to convert a string to a new string where each character in the new string is "(" if that character appears only once in the original string, or ")" if that character appears more than once in the original string. Ignore capitalization when determining if a character is a duplicate.

Examples
```
"din"      =>  "((("
"recede"   =>  "()()()"
"Success"  =>  ")())())"
"(( @"     =>  "))((" 
```

## Solution 1: 
解题思路：使用map
1. 遍历数组，将每个char放入map中，每次value + 1
2. 再次遍历数组，每次从map中读取value。若value大于1，则加入')',否则加入'('
```cpp
std::string duplicate_encoder(const std::string& word){
  map<char, int> dict;
  for(auto &elem : word)
    dict[tolower(elem)]++;
  
  string ret;
  for(auto &elem : word) {
    if(dict[tolower(elem)] > 1)
      ret.push_back(')');
    else
      ret.push_back('(');
  }
  return ret;
}
```