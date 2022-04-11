#include <string>
#include <iostream>
#include <vector>
#include <list>

template <typename InIter, typename Val>

InIter find_item(InIter beg, InIter end, const Val &v) {
	for(; beg != end; ++beg) 
		if(*beg == v)
			return beg;
	return beg;
}

int main() {
	std::vector<int> vec{1, 2, 3, 4, 5};
	auto fvItr= find_item(vec.begin(), vec.end(), 5);
	if(fvItr != vec.end())
		std::cout << *fvItr << std::endl;
	else
		std::cout << "Element not found" << std::endl;
	
	return 0;
}