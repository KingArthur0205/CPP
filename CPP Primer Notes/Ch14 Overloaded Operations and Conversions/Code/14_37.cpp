#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Equal {
public:
    Equal(int input = 0) : value(input) {}
    bool operator()(int rhs) { return value == rhs; }

private:
    int value;
};

int main(int argc, char* argv[]) {
    vector<int> vec{1, 2, 3, 4, 5, 6};

    int oldVal, newVal;
    cin >> oldVal >> newVal;
    replace_if(vec.begin(), vec.end(), Equal(oldVal), newVal);

    for(auto &elem : vec)
        std::cout << elem << " ";
    cout << endl;
    return 0;
}