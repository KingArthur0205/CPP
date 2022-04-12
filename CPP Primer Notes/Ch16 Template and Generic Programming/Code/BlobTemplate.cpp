#include <vector>
#include <string>
#include <memory>
#include <iostream>

template <typename T> class Blob {
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    Blob();
    Blob(std::initializer_list<T> lst);

    T back() const;
    T operator[](const size_type i) const;
    T pop_back() const;

private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string &msg) const;
};

// Constructor
template <typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) {}

template <typename T>
Blob<T>::Blob(std::initializer_list<T> lst) : data(std::make_shared<std::vector<T>>(lst)) {}

// Check if the given index exceeds the bound of data
template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const {
    if(i >= data->size())
        throw std::out_of_range(msg);
}

// Return the last value stored in Blob
template <typename T>
T Blob<T>::back() const {
    check(0, "Back on empty Blob");
    return data->back();
}

// Return the element referred by the given index
template <typename T>
T Blob<T>::operator[](const size_type i) const {
    check(i, "Subscript out of range");
    return (*data)[i];
}

// Pop the last element of Blob
template <typename T>
T Blob<T>::pop_back() const {
    check(0, "Pop on empty Blob");
    return data->pop_back();
}

int main() {
    Blob<int> a = {1, 2, 3};
    std::cout << a[0] << std::endl;
    return 0;
}