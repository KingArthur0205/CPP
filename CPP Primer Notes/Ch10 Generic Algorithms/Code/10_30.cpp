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
    vector<int> vec;
    std::istream_iterator<int> in_s(std::cin), eof;
    while(in_s != eof)
        vec.push_back(*in_s++);
    
    sort(vec.begin(), vec.end(), [] (const int &num1, const int &num2) ->bool { return num1 < num2; });

    std::ostream_iterator<int> ot_s(std::cout, " ");
    for(auto &elem : vec)
        *ot_s++ = elem;
    std::cout << std::endl;
    return 0;
}