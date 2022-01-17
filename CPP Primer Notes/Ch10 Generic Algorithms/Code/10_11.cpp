#include <iostream>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

bool bySize(const string &a, const string &b) {
    return a.size() < b.size();
}

void elimDups(vector<string> &vec) {
    sort(vec.begin(), vec.end());
    auto unique_end = unique(vec.begin(), vec.end());
    vec.erase(unique_end, vec.end());
}

int main(int argc, char* argv[]) {
    vector<string> vec;
    string buff;
    while(std::cin >> buff)
        vec.push_back(buff);
    
    elimDups(vec);
    stable_sort(vec.begin(), vec.end(), bySize);

    for(auto &str : vec)
        std::cout << str << std::endl;
    return 0;
}