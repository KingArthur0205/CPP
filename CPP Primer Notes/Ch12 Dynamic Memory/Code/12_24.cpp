#include <string>
#include <vector>
#include <memory>
#include <iostream>

using namespace std;

int main() {
    string input;
    if(getline(std::cin, input)) {
        char *inputArr = new char[input.length()];
        for(int i = 0; i < input.length(); ++i) {
            inputArr[i] = input[i];
        }

        for(int i = 0; i < input.length(); ++i) {
            std::cout << inputArr[i];
        }
    }
    return 0;
}