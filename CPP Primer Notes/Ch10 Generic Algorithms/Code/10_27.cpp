#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <list>

using std::string;
using std::vector;
using std::list;


int main(int argc, char* argv[]) {
    vector<int> vec{1, 1, 2, 3, 4, 5, 5};
    list<int> lst;
    //or we can use back_inserter(lst)
    unique_copy(vec.begin(), vec.end(), inserter(lst, lst.begin()));
    for(auto &a: lst)
        std::cout << a << " ";
    return 0;
}