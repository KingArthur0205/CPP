#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>

int main() {
    std::map<int, int> mp {{3, 3}};
    int a = mp.begin()->second;
    std::cout << a << std::endl;
    return 0;
}