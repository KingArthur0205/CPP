#include <iostream>
#include <string>
#include <list>
#include <vector>

using std::string;

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