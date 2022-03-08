#include <string>
#include <iostream>

class Quote {
public:
    Quote() = default;
    Quote(const std::string &book, const double sales_price) : bookNo(book), price(sales_price) {}
    
    std::string isbn() const { return bookNo; }
    virtual double total_price(std::size_t numSold) const { return numSold * price; }
    virtual ~Quote() = default;

private:
    std::string bookNo;
protected:
    double price = 0.0;
};

int main(int argc, char* argv[]) {

    return 0;
}