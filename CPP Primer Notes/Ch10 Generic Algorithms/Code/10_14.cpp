#include <iostream>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;


int main(int argc, char* argv[]) {
    auto sum = [] (const int &a, const int &b) -> int { return a + b; };
    std::cout << "The sum of 1 and 2 is " << sum(1, 2) << std::endl;
    return 0;
}