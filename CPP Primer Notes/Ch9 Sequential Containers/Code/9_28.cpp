#include <iostream>
#include <string>
#include <forward_list>

void insertTwoString(std::forward_list<std::string> &flist, std::string key, std::string val) {
    auto cur = flist.begin(), pre = flist.before_begin();
	auto end = flist.end();
    while(cur != end) {
		//if key element found
        if(*cur == key) {
			//insert the val after the current string
            flist.insert_after(cur, val);
            return;
        }
		//update pre and cur to the next element
        pre = cur++;
    }
	//insert val at the end of the list
    flist.insert_after(pre, val);
}

int main(int argc, char **argv) {
	std::forward_list<std::string> flist;
    std::string str;
	//construct the list
    while(std::cin >> str)
        flist.insert_after(flist.before_begin(), str);
    std::cin.clear();
    std::string key, val;
    std::cin >> key;
    std::cin >> val;
    insertTwoString(flist, key, val);
	for(auto a : flist)
		std::cout << a;
	return 0;
}