#include <vector>
#include <iostream>

bool isInVector(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int key) {
	while(begin != end) {
		//order of operator evaluation: 1.dereference 2.increment the iterator
		if(*begin++ == key)
			return true;
	}
	return false;
}

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5};
    if(isInVector(vec.cbegin(), vec.cend(), 3))
        std::cout << "The element exists" << std::endl;
    return 0;
}