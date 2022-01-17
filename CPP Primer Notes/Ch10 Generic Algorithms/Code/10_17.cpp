#include <iostream>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

void elimDups(vector<string> &vec) {
    sort(vec.begin(), vec.end());
    auto unique_end = unique(vec.begin(), vec.end());
    vec.erase(unique_end, vec.end());
}

void biggies(vector<string> &vec, vector<string>::size_type sz) {
    //1.去除vec中的重复元素
    elimDups(vec);
    //2.找到最后一个不符合条件的元素
    auto last = partition(vec.begin(), vec.end(), [sz] (const string &str) -> bool { return str.size() > sz; });
    //3.打印
    for_each(vec.begin(), last, [] (const string &str)-> void { std::cout << str << " "; });
}

int main(int argc, char* argv[]) {
    vector<string> vec;
    string buff;
    while(std::cin >> buff)
        vec.push_back(buff);
    
    biggies(vec, 5);

    return 0;
}