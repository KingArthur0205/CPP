#include <string>
#include <vector>
#include <memory>
#include <iostream>

using namespace std;

int main() {
    string a = "Arthur ";
    string b = "loves Cici";
    string c = a + b;
    char* concateArr = new char[c.length()];
    for(int i = 0; i < c.length(); ++i) {
        concateArr[i] = c[i];
    }
    
    for(int i = 0; i < c.length(); ++i) {
        std::cout << concateArr[i];
    }
    delete[] concateArr;
    return 0;
}