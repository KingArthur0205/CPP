#include <string>
#include <iostream>

class Sales_data;
std::istream &read(std::istream &, Sales_data &);

class Sales_data {
  friend Sales_data add(const Sales_data &, const Sales_data &);
  friend std::istream &read(std::istream &, Sales_data &);
  friend std::ostream &print(std::ostream &, const Sales_data &);

public:
  //nondelegating constructors
  Sales_data() : bookNo(""), units_sold(0), revenue(0.0) {}
  Sales_data(const std::string &no) : bookNo(no) {}
  Sales_data(const std::string &no, unsigned us, double price)
      : bookNo(no), units_sold(us), revenue(price * us) {}
  Sales_data(std::istream &is) {
    read(is, *this);
  }

  //delegating constructors
  Sales_data(const unsigned u_sold) : Sales_data() { 
    units_sold = u_sold;
    std::cout << "This is a delegating constructor" << std::endl; 
  }

  std::string isbn() const { return bookNo; }
  Sales_data &combine(const Sales_data &);

private:
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

Sales_data &Sales_data::combine(const Sales_data &rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data sum = lhs;  // Use default copy constructor
  sum.combine(rhs);
  return sum;
}

std::istream &read(std::istream &is, Sales_data &item) {
  double price;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = item.units_sold * price;
  return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
  os << item.isbn() << " " << item.units_sold << " " << item.revenue;
  return os;
}

int main() {
  Sales_data d1;
  Sales_data d2("0-201-78345-X");
  Sales_data d3("0-201-78345-X", 5, 2.5);
  //Sales_data d4(std::cin);
  Sales_data d5(3);

  print(std::cout, d1) << std::endl;
  print(std::cout, d2) << std::endl;
  print(std::cout, d3) << std::endl;
  //print(std::cout, d4) << std::endl;
  print(std::cout, d5) << std::endl;

  

  return 0;
}