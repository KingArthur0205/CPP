#ifndef STRBLOB_H
#define STRBLOB_H

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <initializer_list>

class StrBlob{
    friend std::ostream& operator<<(std::ostream&, const StrBlob&);
    friend bool operator==(const StrBlob&, const StrBlob&);
    friend bool operator!=(const StrBlob&, const StrBlob&);
    friend bool operator<(const StrBlob &, const StrBlob &);
    friend bool operator>(const StrBlob &, const StrBlob &);
    friend bool operator<=(const StrBlob &, const StrBlob &);
    friend bool operator>=(const StrBlob &, const StrBlob &);
public:
    typedef std::vector<std::string>::size_type size_type;

    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    StrBlob(const StrBlob&);

    size_type size() { return data->size(); }
    bool empty() { return data->empty(); }

    void push_back(const std::string &);

    const std::string &front() const;
    std::string &front();

    const std::string &back() const;
    std::string &back();

    StrBlob &operator=(const StrBlob &);
    std::string &operator[](size_type n) { return (*data)[n]; }
    const std::string &operator[](size_type n) const { return (*data)[n]; }

private:
    std::shared_ptr<std::vector<std::string>> data;

    void check(size_type i, const std::string message) const;
};

bool operator==(const StrBlob &, const StrBlob &);
bool operator!=(const StrBlob &, const StrBlob &);
bool operator<(const StrBlob &, const StrBlob &);
bool operator>(const StrBlob &, const StrBlob &);
bool operator<=(const StrBlob &, const StrBlob &);
bool operator>=(const StrBlob &, const StrBlob &);

#endif