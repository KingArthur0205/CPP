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
    for(auto r_itr = vec.crbegin(); r_itr != vec.crend(); ++r_itr)
        std::cout << *r_itr << std::endl;
    return 0;
}