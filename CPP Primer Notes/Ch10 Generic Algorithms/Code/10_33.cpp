#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <numeric>

using std::string;
using std::vector;


int main(int argc, char* argv[]) {
    std::cout << argc;
    std::ifstream input_file(argv[1]);
    std::istream_iterator<int> in_s(input_file), eof;
    std::ofstream output_file_odd(argv[2]), output_file_even(argv[3]);
    std::ostream_iterator<int> oi1(output_file_odd, " "), oi2(output_file_even, " ");
    while(in_s != eof) {
        int num = *in_s++;
        if(num % 2)
            *oi1++ = num;
        else
            *oi2++ = num;
    }
    return 0;
}