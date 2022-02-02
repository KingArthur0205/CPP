# Practice 2: Two to One
Take 2 strings s1 and s2 including only letters from ato z. Return a new sorted string, the longest possible, containing distinct letters - each taken only once - coming from s1 or s2.

```cpp
class TwoToOne
{
public:
    static std::string longest(const std::string &s1, const std::string &s2);
};
```

# Solution:
1. Put the chars of the two strings into a set, which will filter out all of the repeated chars adn sort the chars.
2. Convert the set back to a string

```cpp
#include <string>
#include <set>

class TwoToOne {
public:
    static std::string longest(const std::string &s1, const std::string &s2);
};

std::string TwoToOne::longest(const std::string &s1, const std::string &s2) {
  std::set<char> buffer_set;
  buffer_set.insert(s1.cbegin(), s1.cend());
  buffer_set.insert(s2.cbegin(), s2.cend());
  std::string ret(buffer_set.cbegin(), buffer_set.cend());
  return ret;
}
```