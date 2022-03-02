#include <fstream>
#include <cassert>
#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>

class StringComp {
public:
    StringComp(size_t low,  size_t high) : low(low), high(high) {}
    bool operator()(const std::string &str) const {
        return str.size() >= low && str.size() <= high;
    }

private:
    size_t low, high;
};

int main(int argc, char* argv[]) {
    assert(argc == 2);

    std::ifstream inf(argv[1]);
    if(!inf.is_open()) {
        std::cerr << "File not opened" << std::endl;
        return -1;
    }

    std::istream_iterator<std::string> ifs(inf), eof;
    std::cout << std::count_if(ifs, eof, StringComp(1, 1)) << std::endl;

    return 0;
}