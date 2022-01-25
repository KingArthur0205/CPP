#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>

int main() {
    std::vector<int> vec{10, 3};
    std::multiset<int> ms{5, 20};
    copy(ms.begin(), ms.end(), inserter(vec, vec.end()));
    //copy(ms.begin(), ms.end(), back_inserter(vec));

    for(auto &elem : vec)
        std::cout << elem << std::endl;
    return 0;
}