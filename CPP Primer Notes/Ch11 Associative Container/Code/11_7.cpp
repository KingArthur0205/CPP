#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>

void addChildren(std::map<std::string, std::vector<std::string>> &familyTree, const std::string &lName, const std::string &fName) {
    familyTree[lName].push_back(fName);
}

int main(int argc, char* argv[]) {
    std::map<std::string, std::vector<std::string>> familyTree;
    std::string familyName;
    while(std::cin >> familyName) {
        std::cin.clear();
        std::string bufferStr;
        while(std::cin >> bufferStr)
            addChildren(familyTree, familyName, bufferStr);
        std::cin.clear();
    }

    for(auto &elem : familyTree) {
        std::cout << elem.first << " ";
        for(auto &fName : elem.second)
            std::cout << fName << " ";
        std::cout << std::endl;
    }
    return 0;
}