#include <string>
#include <iostream>

using namespace std;

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr&);
private:
    std::string *ps; 
    int i;
};

HasPtr::HasPtr(const HasPtr &org) : ps(new string(*org.ps)), i(org.i) {};

int main(int argc, char* args[]) {
    HasPtr a("Arthur");
    HasPtr b(a);

    return 0;
}