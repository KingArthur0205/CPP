#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::map<std::string, std::string::size_type> word_count;
    std::set<char> exclude {',', '!', '.', '?'};
    std::string buffer;
    while(std::cin >> buffer) {
        std::string word = buffer;
        for(auto &ch : word)
            ch = tolower(ch);
        word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
        ++word_count[word];

    }
    for(const auto &elem : word_count) 
        std::cout << elem.first << " occurs " << elem.second << " times" << std::endl;
    return 0;
}