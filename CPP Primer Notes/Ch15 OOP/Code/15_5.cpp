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

class Bulk_quote : public Quote {
public:
    Bulk_quote() : Quote() {}
    Bulk_quote(const std::string &book, const double sales_price, std::size_t m_qty, const double disc) : Quote(book, sales_price), min_qty(m_qty), discount(disc) {}

    double total_price(std::size_t numSold) const override {
        if(numSold >= min_qty)
            return price * (1 - discount) * numSold;
        return price * numSold;
    }

private:
    std::size_t min_qty;
    double discount = 0.0;
};

int main(int argc, char* argv[]) {
    Bulk_quote book1("1-22-33", 30.0, 2, 0.5);
    std::cout << book1.total_price(30) << std::endl;
    return 0;
}