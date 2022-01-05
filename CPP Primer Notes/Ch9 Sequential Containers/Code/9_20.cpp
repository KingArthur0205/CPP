#include <iostream>
#include <string>
#include <list>
#include <deque>

void func(std::list<int> &inputList, std::deque<int> &evenDeque, std::deque<int> &oddDeque) {
    auto begin = inputList.cbegin();
    auto end = inputList.cend();
    while(begin != end) {
        int currentNumber = *begin;
        //odd number
        if(currentNumber % 2) {
            oddDeque.push_back(currentNumber);
        } 
        //even number
        else {
            evenDeque.push_back(currentNumber);
        }
        ++begin;
    }
}

void printDeque(const std::deque<int> &inputDeque) {
    for(auto elem : inputDeque)
        std::cout << elem << " " ;
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
    std::deque<int> evenDeque, oddDeque;
    std::list<int> inputList;
    int num;
    while(std::cin >> num)
        inputList.push_back(num);
    func(inputList, evenDeque, oddDeque);
    std::cout << "Odd deque: " << std::endl;
    printDeque(oddDeque);
    std::cout << "Even deque: " << std::endl;
    printDeque(evenDeque);
    return 0;
}