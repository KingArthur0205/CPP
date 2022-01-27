#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>

using std::string;
using std::vector;

int main() {
    std::map<string, vector<int>> mp{ {"Arthur", {2, 5, 2002}}, {"Cici", {1, 9, 2003}} };
    std::map<string, vector<int>>::iterator itr = mp.find("Arthur");
    for(auto &elem : itr->second)
        std::cout << elem << std::endl;
    return 0;
}