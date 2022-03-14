#include <string>
#include <iostream>

class Quote {
public:
    Quote() = default;
    Quote(const std::string &book, const double sales_price) : bookNo(book), price(sales_price) {}
    
    std::string isbn() const { return bookNo; }
    virtual double total_price(std::size_t numSold) const { return numSold * price; }
    virtual ~Quote() = default;

    virtual void debug() const {
        std::cout << "BookNumber: " << bookNo << "\nPrice: "  << price << std::endl;
    }

private:
    std::string bookNo;
protected:
    double price = 0.0;
};

class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string &book, const double sales_price, std::size_t quantity, const double disc_rate) :
        Quote(book, sales_price), qty(quantity), discount_rate(disc_rate) {}

    virtual double total_price(std::size_t) const = 0;

protected:
    std::size_t qty;
    double discount_rate;
};

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, const double sales_price, std::size_t quantity, const double disc_rate) : Disc_quote(book, sales_price, quantity, disc_rate) {}

    double total_price(std::size_t n) const override{
        return n > qty ? n * discount_rate * price : n * price;
    } 
};

class Limited_quote : public Disc_quote {
public:
    Limited_quote() = default;
    Limited_quote(const std::string &book, const double sales_price, std::size_t quantity, const double disc_rate) : Disc_quote(book, sales_price, quantity, disc_rate) {}

    double total_price(std::size_t n) const override {
        return n > qty ? qty * price * discount_rate + (n - qty) * price : n * discount_rate * price;
    }
};

double print_total(std::ostream &os, const Quote &item, std::size_t n) {
    double ret = item.total_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

int main(int argc, char* argv[]) {
    Bulk_quote book1("1-2-3", 10.0, 15, 0.5);
    Limited_quote book2("2-3-4", 5.0, 10, 0.5);
    print_total(std::cout, book1, 30);
    print_total(std::cout, book2, 20);
    return 0;
}