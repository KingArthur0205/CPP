#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <numeric>

using std::string;
using std::vector;


int main(int argc, char* argv[]) {
    vector<int> vec {1, 2, 3, 4, 5, 6, 7};
    for(auto o_itr = vec.cend() - 1; o_itr >= vec.cbegin(); --o_itr)
        std::cout << *o_itr << std::endl;
    return 0;
}