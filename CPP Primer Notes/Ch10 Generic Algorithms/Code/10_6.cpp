#include <iostream>
#include <vector>
#include <iterator>

void print(const std::vector<int> &vec) {
	for(auto &a : vec)
		std::cout << a << " " ;
	std::cout << std::endl;
}

int main() {
	std::vector<int> vec = {10, 10, 10, 10};
	print(vec);
	fill_n(vec.begin(), vec.size(), 0);
	print(vec);
	return 0;
}