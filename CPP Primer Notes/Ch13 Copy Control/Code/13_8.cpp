#include <string>
#include <iostream>

using namespace std;

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr&);
    HasPtr& operator=(const HasPtr&);
    void print();
private:
    std::string *ps; 
    int i;
};

HasPtr::HasPtr(const HasPtr &org) : ps(new string(*org.ps)), i(org.i) {}

HasPtr& HasPtr::operator=(const HasPtr& org) {
    *ps = *org.ps;
    this->i = org.i;
    return *this;
}

void HasPtr::print() {
    std::cout << this->i << " " << *this->ps << std::endl;
}

int main(int argc, char* args[]) {
    HasPtr a("Arthur");
    HasPtr b = a;
    b.print();

    return 0;
}