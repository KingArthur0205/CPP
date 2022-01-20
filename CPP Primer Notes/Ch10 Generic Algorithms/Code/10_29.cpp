#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>

using std::string;
using std::vector;


int main(int argc, char* argv[]) {
    vector<string> vec;
    std::ifstream input_file_s(argv[1]);
    std::istream_iterator<string> in_s(input_file_s), eof;
    while(in_s != eof)
        vec.push_back(*in_s++);

    std::ostream_iterator<string> o_s(std::cout, " ");
    for(auto &elem : vec)
        *o_s++ = elem;
    std::cout << std::endl;
    return 0;
}