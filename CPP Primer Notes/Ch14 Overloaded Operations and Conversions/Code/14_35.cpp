#include <string>
#include <iostream>

using namespace std;

class ReadString {
public:
    ReadString(std::istream &is = std::cin) : is(is) {}
    string operator()() {
        string ret;
        is >> ret;
        if(is)
            return ret;
        return "";
    }

private:
    istream &is;

};

int main(int argc, char* argv[]) {
    ReadString tester;
    cout << tester() << endl;
    return 0;
}