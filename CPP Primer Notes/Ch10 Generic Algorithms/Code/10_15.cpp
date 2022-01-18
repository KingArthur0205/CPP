#include <iostream>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

int func(int a) {
    auto sum = [a] (int b) -> int { return a + b ;};
    return sum(3);
}

int main(int argc, char* argv[]) {
    int temp;
    std::cin >> temp;
    std::cout << "The sum of 3 and given number is " << func(temp) << std::endl;
    return 0;
}