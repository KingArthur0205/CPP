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
    while((itr = mmp.find("Arthur")) != mmp.end()) {
        mmp.erase(itr);
    }

    std::cout << mmp.size() << std::endl;
    return 0;
}