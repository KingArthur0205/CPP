#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::cin;
using std::cout;
using std::istream;
using std::ostream;
using std::string;

class Sales_data;

class Sales_data {
	// friend declarations for nonmbmer Sales_data operations added
	friend std::istream &read(std::istream&, Sales_data&);
	friend std::ostream &print(std::ostream&, const Sales_data&);

public: // access specifier added
	Sales_data() = default; 
	Sales_data(const std::string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n) { } 
	Sales_data(const std::string &s): bookNo(s) { } 
	Sales_data(std::istream& is) {
		read(is, *this);
	}
	std::string isbn() const { return bookNo; } 
	Sales_data &combine(const Sales_data&);

private: // access specifier added
	double avg_price() const { return units_sold ? revenue/units_sold : 0; } 
	std::string bookNo; unsigned units_sold = 0; double revenue = 0.0;
};

std::istream &read(std::istream &is, Sales_data &item) {
  double price;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = item.units_sold * price;
  return is;
}

std::ostream &print(ostream& os, const Sales_data &data) {
	os << data.bookNo << "" << data.units_sold << "" << data.revenue;
	return os;
}


int main() {
	Sales_data item = Sales_data();
	Sales_data item2 = Sales_data("243", 3, 12.0);
	cout << item2.isbn() << endl;
	cout << item.isbn() << endl;
	return 0;
}
