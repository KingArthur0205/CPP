# Practice 4: Sum without Highest and Lowest Number
Sum all the numbers of a given array ( cq. list ), except the highest and the lowest element ( by value, not by index! ).

The highest or lowest element respectively is a single element at each edge, even if there are more than one with the same value.

Mind the input validation:
If an empty value ( null, None, Nothing etc. ) is given instead of an array, or the given array is an empty list or a list with only 1 element, return 0.

## Solution 1: Sort the array
```cpp
#include<vector>
#include <numeric>
#include <algorithm>
using namespace std;

int sum(vector<int> numbers) {
    //If the vector has less than 2 elements, return 0;
    //If delete this, the accumulate algorithm will fail because numbers.begin() + 1 will excede numbers.end() - 1
  if(numbers.size() <= 2)
    return 0;
  
  sort(numbers.begin(), numbers.end());
  return accumulate(numbers.begin() + 1, numbers.end() - 1, 0);
}
```

## Solution 2: Find the lowest and highest while looping
```cpp
#include<vector>
using namespace std;

int sum(vector<int> numbers) {
  if(numbers.size() <= 2)
    return 0;
  //Find the lowest and highest value when looping through the array
  int sum = 0, low = numbers[0], high = numbers[0];
  for(auto &elem : numbers) {
    if(low > elem)
      low = elem;
    if(high < elem)
      high = elem;
    sum += elem;
  }
  //Get rid of the highest and lowest element in the array
  return sum - low - high;
}
```