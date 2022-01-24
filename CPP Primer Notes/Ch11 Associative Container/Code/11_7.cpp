#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>

int main(int argc, char* argv[]) {
    std::map<std::string, std::vector<std::string>> familyTree;
    std::string familyName;
    if(std::cin >> familyName) {
        std::vector<std::string> tempVec;
        std::cin.clear();
        std::string bufferStr;
        while(std::cin >> bufferStr)
            tempVec.push_back(bufferStr);
        familyTree[familyName] = tempVec;
    }

    for(auto &elem : familyTree) {
        std::cout << elem.first << " ";
        for(auto &fName : elem.second)
            std::cout << fName << " ";
        std::cout << std::endl;
    }
    return 0;
}