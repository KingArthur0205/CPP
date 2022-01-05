#include <iostream>
#include <string>
#include <list>
#include <vector>


int main(int argc, char* argv[]) {
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
    std::vector<int> vec1;
    std::list<int> list1;
    int ia_size = sizeof(ia)/sizeof(ia[0]);
    for(int i = 0; i < ia_size; ++i) {
        vec1.push_back(ia[i]);
        list1.push_back(ia[i]);
    }

    auto vecBegin = vec1.begin();
    while(vecBegin != vec1.end()) {
        if(*vecBegin % 2)
            ++vecBegin;
        else
            vecBegin = vec1.erase(vecBegin);
    }

    auto listBegin = list1.begin();
    while(listBegin != list1.end()) {
        if(*listBegin % 2)
            listBegin = list1.erase(listBegin);
        else
            ++listBegin;
    }

    for(auto a : vec1)
        std::cout << a << " ";
    std::cout << std::endl;
    for(auto b : list1)
        std:: cout << b << " ";
    return 0;
}