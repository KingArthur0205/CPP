#include <iostream>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

bool shorterThanFive(const string &str) {
    return str.size() < 5;
}

int main(int argc, char* argv[]) {
    vector<string> vec;
    string buff;
    while(std::cin >> buff)
        vec.push_back(buff);
    
    auto itrMTFive = partition(vec.begin(), vec.end(), shorterThanFive);

    for(; itrMTFive != vec.end(); ++itrMTFive)
        std::cout << *itrMTFive << std::endl;
    return 0;
}