#include <string>
#include <vector>
#include <memory>
#include <iostream>

using std::vector;
using std::string;
using std::shared_ptr;
using std::make_shared;

class StrBlob {
public:
    typedef vector<string>::size_type size_type;

    //Constructor
    StrBlob(); //Default Constructor
    StrBlob(std::initializer_list<string> il);

    //Element Access
    string &front() const;
    string &back() const;
    void push_back(string &str);

private:
    shared_ptr<vector<string>> data;
};

StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}

StrBlob::StrBlob(std::initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

string &StrBlob::front() const {
    if(this->data->size() <= 0)
        throw std::out_of_range("Invalid Access");
    return this->data->front();
}

string &StrBlob::back() const {
    if(data->size() <= 0)
        throw std::out_of_range("Invalid Access");
    return data->back();
}

void StrBlob::push_back(string &str) {
    data->push_back(str);
}

int main(int argc, char* argv[]) {
    StrBlob a = StrBlob({"Arthur", "'s baby is'"});
    string str = "Cici";
    a.push_back(str);
    std::cout << a.front() << a.back();
    return 0;
}