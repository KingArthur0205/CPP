#include <iostream>
#include <string>
#include <list>
#include <vector>

using std::string;

string &addTitle(string &name, const string &prefix, const string &suffix) {
    name.insert(0, prefix);
    return name.append(suffix);
}

int main(int argc, char* argv[]) {
    string name = "Arthur", prefix = "Dr. ", suffix = " I";
    std::cout << addTitle(name, prefix, suffix);
    return 0;
}