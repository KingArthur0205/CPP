#include <iostream>
#include <map>
#include <string>
#include <functional>

int add(int i, int j) { return i + j; };

struct divide {
    int operator()(int i, int j) { return i / j; }
};

int main() {
    std::map<std::string, std::function<int (int, int)>> binops;
    auto mod = [](int i, int j) -> int { return i % j; };
    binops.insert({"+", add});
    binops.insert({"%", mod});
    binops.insert({"/", divide()});
    binops.insert({"*", [](int i, int j) -> int { return i * j; }});
    binops.insert({"-", std::minus<int>()});

    std::cout << binops["+"](3, 5) << std::endl;
    std::cout << binops["-"](3, 5) << std::endl;
    std::cout << binops["*"](3, 5) << std::endl;
    std::cout << binops["/"](3, 5) << std::endl;
    std::cout << binops["%"](3, 5) << std::endl;
    return 0;
}