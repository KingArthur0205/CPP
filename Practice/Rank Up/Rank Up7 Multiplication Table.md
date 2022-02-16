# Rank Up 6: Multiplication Table
Your task, is to create NxN multiplication table, of size provided in parameter.

for example, when given size is 3:
```c
1 2 3
2 4 6
3 6 9
```

## Solution 1:
```cpp
#include <vector>

using namespace std;
vector<vector<int>> multiplication_table(int n){
  vector<vector<int>> table(n, vector<int>(n));
  for(int i = 1; i <= n ;++i) {
    for(int j = 1; j <= n; ++j) {
      table[i-1][j-1] = i * j;
    }
  }
  return table;
}
```