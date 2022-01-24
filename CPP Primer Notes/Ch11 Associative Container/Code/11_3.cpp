#include <iostream>
#include <string>
#include <map>


int main(int argc, char* argv[]) {
    std::map<std::string, std::string::size_type> word_count;
    std::string buffer;
    while(std::cin >> buffer)
        ++word_count[buffer];
    for(const auto &elem : word_count)
        std::cout << elem.first << " occurs " << elem.second << " times" << std::endl;
    return 0;
}