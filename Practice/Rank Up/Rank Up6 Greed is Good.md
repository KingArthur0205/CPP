# Rank Up6: Greed is Good
Greed is a dice game played with five six-sided dice. Your mission, should you choose to accept it, is to score a throw according to these rules. You will always be given an array with five six-sided dice values.

```
 Three 1's => 1000 points
 Three 6's =>  600 points
 Three 5's =>  500 points
 Three 4's =>  400 points
 Three 3's =>  300 points
 Three 2's =>  200 points
 One   1   =>  100 points
 One   5   =>   50 point
```

A single die can only be counted once in each roll. For example, a given "5" can only count as part of a triplet (contributing to the 500 points) or as a single 50 points, but not both in the same roll.

Example scoring
```

 Throw       Score
 ---------   ------------------
 5 1 3 4 1   250:  50 (for the 5) + 2 * 100 (for the 1s)
 1 1 1 3 1   1100: 1000 (for three 1s) + 100 (for the other 1)
 2 4 4 5 4   450:  400 (for three 4s) + 50 (for the 5)
```
In some languages, it is possible to mutate the input to the function. This is something that you should never do. If you mutate the input, you will not be able to pass all the tests.

## Solution 1:
```cpp
#include <vector>
#include <map>

using namespace std;

int score(const std::vector<int>& dice) {
  map<int, int> occurence;
  for(auto &elem : dice)
    occurence[elem]++;
  
  
  int score = 0;
  for(auto &elem : occurence) {
    if(elem.first == 1 || elem.first == 5) {
      if(elem.first == 1) {
        score += elem.second >=3 ? 1000 + (elem.second - 3) * 100 : elem.second * 100;
      }else {
        score += elem.second >= 3 ? 500 + (elem.second - 3) * 50 : elem.second * 50;
      }
    } else {
      if(elem.second >= 3)
        score += elem.first * 100;
    }
  }
  
  return score;
}
```

## Solution 2:
```cpp
#include <vector>

int score(const std::vector<int>& dice) {
  unsigned cs[7] = {};
  for (auto d : dice)
    cs[d]++;
  return
    cs[1] / 3 * 1000 + cs[6] / 3 * 600 + cs[5] / 3 * 500 +
    cs[4] / 3 * 400 + cs[3] / 3 * 300 + cs[2] / 3 * 200 +
    cs[1] % 3 * 100 + cs[5] % 3 * 50;
}
```