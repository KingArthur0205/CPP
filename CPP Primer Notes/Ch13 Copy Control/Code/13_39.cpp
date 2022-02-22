#include <string>
#include <vector>
#include <iostream>

using namespace std;

class StrVec {
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    string *begin() const { return elements; }
    string *end() const { return cap; }
    StrVec(const StrVec&);
    ~StrVec() { free(); }
    StrVec& operator=(const StrVec&);

    void push_back(const string&);

    void print();
private:
    allocator<string> alloc;
    string *elements;
    string *first_free;
    string *cap;

    pair<string*, string*> alloc_n_copy(const string*, const string*);
    void free();
    void chk_n_alloc();
    void reallocate();
};

StrVec& StrVec::operator=(const StrVec &s) {
    auto newData = alloc_n_copy(s.begin(), s.end());
    cout << s.end() - s.begin() << endl;
    free();
    elements = newData.first;
    first_free = cap = newData.second;
    return *this;
}

StrVec::StrVec(const StrVec &s) {
    pair<string*, string*> newData = alloc_n_copy(s.begin(), s.end());
    elements = newData.first;
    first_free = cap = newData.second;
}

pair<string*, string*> StrVec::alloc_n_copy(const string* begin, const string* end) {
    string* first = alloc.allocate(end - begin);
    return {first, uninitialized_copy(begin, end, first)};
}

void StrVec::print() {
    for(auto p = elements; p != first_free; ++p)
        cout << *p << endl;
}

void StrVec::free() {
    if(elements) {
        for(auto p = first_free; p != elements;) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::reallocate() {
    // Allocate 2x the original space
    // If the vector was originally not allocated, allocate one space
    size_t newCapacity = size() ? size() * 2 : 1;
    string* newData = alloc.allocate(newCapacity);

    string* dest = newData;
    string *elem = elements;

    for(size_t i = 0; i < size(); ++i) {
        alloc.construct(dest++, std::move(*elem++));
    }

    free();
    elements = newData;
    cap = elements + newCapacity;
    first_free = dest;
}

// If there is no room in the current vector, reallocate
void StrVec::chk_n_alloc() {
    if(size() == capacity())
        reallocate();
}

void StrVec::push_back(const string& inputStr) {
    // Check if we can insert another string into the current vector
    // If not, expand the size of the vector
    chk_n_alloc();
    alloc.construct(first_free++, inputStr);
}

int main(int argc, char* argv[]) {
    StrVec a;
    a.push_back("Arthur");
    a.push_back("Arthur");
    a.push_back("Arthur");
    a.push_back("Arthur");
    a.print();
    //cout << a.capacity() << endl;

    StrVec b = a;
    b.print();

    StrVec c(a);
    c.print();

    return 0;
}