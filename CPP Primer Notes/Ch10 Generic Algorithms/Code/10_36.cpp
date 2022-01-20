#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <numeric>
#include <list>

using std::string;
using std::vector;


int main(int argc, char* argv[]) {
    std::list<int> lst{1, 2, 3, 4, 0, 7};
    auto lastZero = find(lst.crbegin(), lst.crend(), 0);
    while(lastZero != lst.crend())
        std::cout << *lastZero++ << std::endl;
    return 0;
}