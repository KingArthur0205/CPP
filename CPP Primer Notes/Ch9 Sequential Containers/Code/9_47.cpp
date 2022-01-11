#include <iostream>
#include <string>
#include <list>
#include <vector>

using std::string;

void searchFV(const string &input, const string &condition) {
    for(auto pos = 0; (pos = input.find_first_of(condition, pos)) != string::npos; ++pos) {
        std::cout << "Find satisfiable character " << input[pos] << " at " << pos << std::endl;
    }
}

void searchSV(const string &input, const string &condition) {
    string::size_type last_pos = 0;
    //1. 找到第一个不满足condition的字符
    for(auto pos = 0; (pos = input.find_first_not_of(condition, pos)) != string::npos; ++pos) {
    //2. 遍历前面所有的字符，就是满足condition的字符
        for(auto i = last_pos; i != pos; ++i) {
            std::cout << "Find satisfiable character " << input[i] << " at " << i << std::endl;
        }
        last_pos = pos + 1;
    }
    //3. 最后再遍历一遍（因为我们while退出条件为npos），有可能有满足条件的字符在'\0'和最后的pos之间
    for(auto i = last_pos; i < input.size(); ++i) {
        std::cout << "Find satisfiable character " << input[i] << " at " << i << std::endl;
    }
}

void searchStr(const string &input) {
    const string nums {"0123456789"};
    const string alphas {"abcdefghijklmnopqrstuvwxyz"
                            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    
    std::cout << "First version: " << std::endl;
    std::cout << "Find numbers in the string: " << std::endl;
    searchFV(input, nums);
    std::cout << "Find alphas in the string: " << std::endl;
    searchFV(input, alphas);
    
    std::cout << std::endl << std::endl << "Second version: " << std::endl;
    std::cout << "Find numbers in the string: " << std::endl;
    searchSV(input, nums);
    std::cout << "Find alphas in the string: " << std::endl;
    searchSV(input, alphas);
}

int main(int argc, char* argv[]) {
    string input;
    if(getline(std::cin, input)) {}

    searchStr(input);
    return 0;
}