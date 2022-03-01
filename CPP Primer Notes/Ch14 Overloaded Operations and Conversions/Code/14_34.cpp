#include <string>
#include <iostream>

using namespace std;

class IfElseTester{
public:
    bool operator()(bool fstArg, bool sndArg, bool thirdArg) {
        return fstArg ? sndArg : thirdArg;
    }
};

int main(int argc, char* argv[]) {
    IfElseTester tester;
    std::cout << tester(false, true, false) << std::endl;
    return 0;
}