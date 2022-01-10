#include <iostream>
#include <string>
#include <list>
#include <vector>

using std::string;

/*
    1. sItr遍历s，遍历的范围是从begin到end()-oldVal.size()+1
    2. 创建另外两个辅助iterator，sItr2指向sItr, oldVItr指向oldVal.begin(),进行遍历
        a.若遍历中*sItr2 != *oldVItr,说明当前字符串不为oldVal，退出当前循环
    3. 进行判断，oldVItr是否等于oldVal.end()
        a. 若是，说明当前字符串应该被删除
            1) 算出当前删除字符串的下标，sItr - s.begin()
            2) erase(pos, oldVal.size())
            3) insert(pos, newVal);
*/
void subsValue(string &s, const string &oldVal, const string &newVal) {
    for(auto sItr = s.begin(); sItr < s.end() - oldVal.size() + 1; ) {
        auto oldItr = oldVal.begin();
        for(auto itr3 = sItr; oldItr != oldVal.end(); ++oldItr, ++itr3) {
            if(*itr3 != *oldItr)
                break;
        }
        if(oldItr == oldVal.end()) {
            std::string::size_type pos = sItr - s.begin();
            s.erase(pos, oldVal.size());
            s.insert(pos, newVal);
        } else {
            ++sItr;
        }
    }
}

int main(int argc, char* argv[]) {
    string s = "Although", oldVal = "though", newVal = "tho";
    subsValue(s, oldVal, newVal);
    std::cout << s;
    return 0;
}