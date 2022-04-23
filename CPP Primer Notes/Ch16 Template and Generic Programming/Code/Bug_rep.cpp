#include <sstream>
#include <string>
#include <iostream>

// General version of bug_rep
template <typename T> std::string bug_rep(const T &t) {
    std::ostringstream ret;
    ret << t;
    return ret.str();
}

// Pointer-specific version of bug_rep
template <typename T> std::string bug_rep(T *p) {
    std::ostringstream ret;
    ret << "Pointer: " << p << '\n';
    if(p)
        ret << bug_rep(*p);
    else
        ret << "Null pointer";
    return ret.str();
}

// String-specific version of bug_rep
template <typename T> std::string bug_rep(std::string &str) {
    return '"' + str + '"';
}

int main(int argc, char* argv[]) {
    std::string str("Arthur");
    std::cout << bug_rep(1) << std::endl;
    std::cout << bug_rep(&str) << std::endl;
    std::cout << bug_rep(str) << std::endl;
   return 0; 
}