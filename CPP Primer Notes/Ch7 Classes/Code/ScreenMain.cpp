#include "Screen.h"

int main(int argc, char* argv[]) {
    Screen s = Screen(30, 30);
    s.move(20,20);
    s.set('c');
    std::cout << s.get() << std::endl;
    std::cout << s.getCallCount() << std::endl;

    Screen myScreen(5, 5, 'X');
    myScreen.move(4,0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";
    return 0;
}