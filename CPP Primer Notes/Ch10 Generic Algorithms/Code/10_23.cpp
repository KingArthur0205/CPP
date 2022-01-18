#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

using std::string;
using std::vector;

bool check_size(const string &str, const string::size_type strLen) {
    return str.size() == strLen;
}

int main(int argc, char* argv[]) {
    string str;
    std::cin >> str;
    vector<int> vec{10, 5, 3, 8, 11};
    std::cout << *find_if(vec.begin(), vec.end(), bind(check_size, str, std::placeholders::_1));
    return 0;
}