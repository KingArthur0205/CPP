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
    std::multimap<string, vector<string>> mmp{ {"Arthur", {"Hello", "World"}}};
    std::multimap<string, vector<string>>::iterator itr;
    

    for(auto &pair : mmp) {
        std::cout << "Author: " << pair.first << " Work: ";
        for(auto &elem : pair.second) {
            std::cout << " " << elem;
        }
        std::cout << std::endl;
    }

    std::cout << mmp.size() << std::endl;
    return 0;
}