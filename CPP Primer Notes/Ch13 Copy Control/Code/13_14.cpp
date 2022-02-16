#include <string>
#include <iostream>

using namespace std;

class numbered {
public:
    numbered(const numbered&);
    numbered(int seriesNum = 0) : seriesNum(seriesNum) {}
    int seriesNum;
};

void f(numbered b) {
    std::cout << b.seriesNum << std::endl;
}

numbered::numbered(const numbered& orig) : seriesNum(orig.seriesNum + 1) {}

int main(int argc, char* args[]) {
    numbered a;
    std::cout << a.seriesNum << std::endl;

    f(a);

    return 0;
}