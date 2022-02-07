# Rank Up 2: Digital Root
Digital root is the recursive sum of all the digits in a number.

Given n, take the sum of the digits of n. If that value has more than one digit, continue reducing in this way until a single-digit number is produced. The input will be a non-negative integer.

Examples
```
    16  -->  1 + 6 = 7
   942  -->  9 + 4 + 2 = 15  -->  1 + 5 = 6
132189  -->  1 + 3 + 2 + 1 + 8 + 9 = 24  -->  2 + 4 = 6
493193  -->  4 + 9 + 3 + 1 + 9 + 3 = 29  -->  2 + 9 = 11  -->  1 + 1 = 2
```

## Solution 1: 
1. While the input number has more than one digits
2. Sum all of its digits
```cpp
// Determine if the input number has only one digit
bool hasOneDigit(int n) {
  return n / 10 == 0;
}

// Get the sum of digits of the current number
int getDigitSum(int n) {
  int ret = 0;
  while(n) {
    ret += (n % 10);
    n /= 10;
  }
  return ret;
}

int digital_root(int n) {
    while(!hasOneDigit(n)) {
      n = getDigitSum(n);
    }
  return n;
}
```