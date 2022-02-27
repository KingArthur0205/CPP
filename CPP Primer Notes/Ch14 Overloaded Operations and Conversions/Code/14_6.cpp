#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Sales_data {
public:
    int price;
    int amount;
};

istream& operator>>(istream &is, Sales_data &item) {
    is >> item.price >> item.amount;
    return is;
}

ostream& operator<<(ostream &os, const Sales_data &item) {
    os << item.price << " " << item.amount;
    return os;
}

int main(int argc, char* argv[]) {
    istringstream is("10 20");
    Sales_data item;
    is >> item;
    cout << item << endl;
    return 0;
}