#include <vector>
#include <iostream>

std::vector<int>::const_iterator isInVector(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int key) {
	while(begin < end) {

		if(*begin == key)
			return begin;
		++begin;
	}
	return end;
}

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5};
    if(isInVector(vec.cbegin(), vec.cend(), 6) == vec.cend())
        std::cout << "The element does not exist" << std::endl;
    else
        std::cout << "The element exists" << std::endl;
    return 0;
}