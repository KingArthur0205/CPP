#include <iostream>
#include <string>
#include <forward_list>

int main(int argc, char **argv) {
	std::forward_list<int> flist = {0, 1, 2, 3, 4, 5, 6, 7, 8};

	auto prev = flist.before_begin();
	auto curr = flist.begin();
	auto end = flist.end();
	while(curr != end) {
		if(*curr % 2) {
			curr = flist.erase_after(prev);
		}
		else {
			prev = curr++;
		}
	}

	for(auto a : flist)
		std::cout << a << " ";
	return 0;
}