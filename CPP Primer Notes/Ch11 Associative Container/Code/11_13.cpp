#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>

int main() {
    int num;
    std::string str;
    std::vector<std::pair<std::string, int>> vec;
    while(std::cin >> str >> num) {
        //vec.push_back(std::pair<std::string, int>{str, num});
        //vec.push_back(make_pair(str, num));
        vec.push_back(std::pair<std::string, int>(str, num));
    }
    for(auto &elem: vec)
        std::cout << elem.first << ": " << elem.second << std::endl;
    return 0;
}