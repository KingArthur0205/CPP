#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Sales_data {
    friend bool operator==(const Sales_data&, const Sales_data&);
public:
    int price;
    int amount;
    Sales_data(int p = 0, int a = 0) : price(p), amount(a) {}
};

bool operator==(const Sales_data& lhs, const Sales_data &rhs) {
    return lhs.price == rhs.price && lhs.amount == rhs.amount;
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs) {
    return !(lhs == rhs);
}

ostream &operator<<(ostream &os, const Sales_data &rhs) {
    os << rhs.amount << " " << rhs.price;
    return os;
}

int main(int argc, char* argv[]) {
    Sales_data a, b;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    if(a == b)
        std::cout<< "A equals b" << std::endl;
    else
        std::cout << "A doesn't equal b" << std::endl;
    return 0;
}