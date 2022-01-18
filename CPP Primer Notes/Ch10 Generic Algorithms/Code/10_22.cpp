#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

using std::string;
using std::vector;

bool shorterThan(const string &str, string::size_type sz) {
    return str.size() <= sz;
}

int main(int argc, char* argv[]) {
    vector<string> vec{"Arthur", "Cici", "Guanzhong", "Pan"};
    std::cout << count_if(vec.begin(), vec.end(), bind(shorterThan, std::placeholders::_1, 6));


    return 0;
}