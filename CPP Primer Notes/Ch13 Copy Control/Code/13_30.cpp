#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class HasPtr {
    friend void swap(HasPtr&, HasPtr&);
public:
    HasPtr(const string& inputStr = string(), int inputInt = 0) : ps(new string(inputStr)), i(inputInt) {}

    string getStr() {
        return *ps;
    }
    int getI() {
        return i;
    }

    bool operator<(const HasPtr&);
private:
    string* ps;
    int i;
};

inline void swap(HasPtr& v1, HasPtr& v2) {
    cout << "Swap called" << endl;
    swap(v1.ps, v2.ps);
    swap(v1.i, v2.i);
}

bool HasPtr::operator<(const HasPtr& input) {
    return i < input.i;
}

int main(int argc, char* argv[]) {
    HasPtr v1("Arthur", 1), v2("Cici", 2), v3("King", -10);
    vector<HasPtr> vec;
    vec.push_back(v1);
    vec.push_back(v2);
    vec.push_back(v3);
    sort(vec.begin(), vec.end());

    for(auto &elem: vec)
        cout << elem.getStr() << " " << elem.getI() << endl;
    return 0;
}