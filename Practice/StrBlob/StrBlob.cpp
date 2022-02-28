#include "StrBlob.h"

//Definition of check
void StrBlob::check(size_type i, const std::string message) const {
    if(i >= data->size())
        throw std::out_of_range(message);
}


// Constructor Definition
StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
StrBlob::StrBlob(std::initializer_list<std::string> il) 
    : data(std::make_shared<std::vector<std::string>>(il)) {}

StrBlob::StrBlob(const StrBlob& sb) : data(std::make_shared<std::vector<std::string>>(*sb.data)) {}


// Definition of Member function
void StrBlob::push_back(const std::string &str) {
    // Use vector's built-in push_back function
    data->push_back(str);
}

const std::string &StrBlob::front() const {
    check(0, "StrBlob is empty");
    return data->front();
}

std::string &StrBlob::front() {
    check(0, "StrBlob is empty");
    return data->front();
}

const std::string &StrBlob::back() const {
    check(0, "StrBlob is empty");
    return data->back();
}

std::string &StrBlob::back() {
    check(0, "StrBlob is empty");
    return data->back();
}


// Definition of Non-member public operators
StrBlob &StrBlob::operator=(const StrBlob &sb) {
    data = std::make_shared<std::vector<std::string>>(*sb.data);
    return *this;
}

std::ostream &operator<<(std::ostream &os, const StrBlob& rhs) {
    for(auto &elem : *rhs.data)
        os << elem << " ";
    return os;
}

bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
    // compare value
    return *lhs.data == *rhs.data;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs) {
    return !(lhs == rhs);
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs) {
  return *lhs.data < *rhs.data;  // compare value
}

bool operator>(const StrBlob &lhs, const StrBlob &rhs) {
  return rhs < lhs;
}

bool operator<=(const StrBlob &lhs, const StrBlob &rhs) {
  return !(lhs > rhs);
}

bool operator>=(const StrBlob &lhs, const StrBlob &rhs) {
  return !(lhs < rhs);
}

int main(int argc, char* argv[]) {
    StrBlob a({"Arthur", "cici"}), b(a);
    a.push_back("Arthur2");
    std::cout << a << std::endl;
    std::cout << a.front() << std::endl;

    return 0;
}