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

void elimDupsList(std::list<int> &lst) {
    lst.sort([] (const int &num1, const int &num2) -> bool { return num1 < num2; });
    lst.unique(); //unique() calls erase() to delete all of the duplicated elements
}

int main(int argc, char* argv[]) {
    std::list<int> lst{3, 10, 3, -10, 7, -10};
    elimDupsList(lst);
    for(auto &elem : lst)
        std::cout << elem << " ";
    return 0;