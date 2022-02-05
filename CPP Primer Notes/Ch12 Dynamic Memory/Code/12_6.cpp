#include <string>
#include <vector>
#include <memory>
#include <iostream>

using std::vector;
using std::string;

vector<int> *createVector() {
    return new vector<int>;
}

void inputValues(vector<int> *vec, std::istream &is) {
    int buffer;
    while(is >> buffer) {
        vec->push_back(buffer);
    }
}

void printValues(vector<int> *vec) {
    for(auto &elem : *vec)
        std::cout << elem << " ";
    std::cout << std::endl;
    delete vec;
}

int main() {
    vector<int> *ptr = createVector();
    inputValues(ptr, std::cin);
    printValues(ptr);
    ptr = nullptr;
    return 0;
}