#include <iostream>
#include <string>
#include <list>
#include <vector>

using std::string;

/*
    1. 下标遍历字符串s，到s.size() - oldVal.size() + 1截至，++index
    2. 创建辅助下标sIndex2 = sIndex, oldIndex = 0。进行遍历，知道oldIndex < oldVal.size()
        a. 若当前sIndex2与oldIndex指向字母不一致，break
    3. 若oldIndex == oldVal.size()，证明找到字符串
        a. 调用replace(sIndex, oldVal.size(), newVal)
*/
void subsValue(string &s, const string &oldVal, const string &newVal) {
    for(auto sIndex = 0; sIndex < s.size() - oldVal.size() + 1; ++sIndex) {
        auto oldIndex = 0;
        for(auto sIndex2 = sIndex; oldIndex < oldVal.size(); ++oldIndex, ++sIndex2) {
            if(oldVal[oldIndex] !=s[sIndex2])
                break;
        }
        if(oldIndex == oldVal.size()) {
            s.replace(sIndex, oldVal.size(), newVal);
        }
    }
}

int main(int argc, char* argv[]) {
    string s = "Although", oldVal = "though", newVal = "tho";
    subsValue(s, oldVal, newVal);
    std::cout << s;
    return 0;
}