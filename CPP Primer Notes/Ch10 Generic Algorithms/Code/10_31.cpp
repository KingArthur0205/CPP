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
    std::ostream_iterator<int> ot_s(std::cout, " ");
    while(in_s != eof)
        vec.push_back(*in_s++);
    
    sort(vec.begin(), vec.end(), [] (const int &num1, const int &num2) ->bool { return num1 < num2; });
    unique_copy(vec.begin(), vec.end(), ot_s);

    std::cout << std::endl;
    return 0;
}