#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>


int main() {
	std::vector<std::string> vec {"Arthur", "Pan", "Cici", "Guanzhong"};
	std::cout << count_if(vec.cbegin(), vec.cend(), [] (const std::string &str) { return str.size () >= 6; });
	return 0;
}