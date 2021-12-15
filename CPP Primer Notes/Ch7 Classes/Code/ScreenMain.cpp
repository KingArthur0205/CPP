#include "Screen.h"

int main(int argc, char* argv[]) {
    Screen s = Screen(30, 30);
    s.move(20,20);
    std::cout << s.get() << std::endl;
    std::cout << s.getCallCount() << std::endl;
    return 0;
}