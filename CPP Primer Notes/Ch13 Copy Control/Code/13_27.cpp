#include <string>
#include <iostream>

using namespace std;

class HasPtr {
public:
    HasPtr(const string& str = string()) : strPtr(new string(str)), i(0),  user(new size_t(0)) {}
    HasPtr(const HasPtr&);
    HasPtr& operator=(const HasPtr&);
    ~HasPtr();

    string& getName() { return *strPtr; }
    size_t& getUser() { return *user; }

private:
    string *strPtr;
    int i;
    size_t *user;
};

HasPtr::HasPtr(const HasPtr& input) : strPtr(input.strPtr), i(input.i), user(input.user) {
    ++*user;
}

HasPtr& HasPtr::operator=(const HasPtr& input) {
    ++*input.user;
    if(--*user == 0) {
        delete strPtr;
        delete user;
    }
    strPtr = input.strPtr;
    i = input.i;
    user = input.user;
    return *this;
}

HasPtr::~HasPtr() {
    if(--*user == 0) {
        delete strPtr;
        delete user;
    }
}

int main(int argc, char* args[]) {
    HasPtr a("Arthur");
    cout << a.getName() << " " << a.getUser() << endl;
    return 0;
}