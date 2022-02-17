#include <string>
#include <iostream>

using namespace std;

class Employee {
public:
    Employee() : name(), id(++incrementer) {}
    Employee(const string& name) : name(name), id(++incrementer) {}
    // The Employee class needs to have its own copy constructor and copy-assignment operators
    // Because we want every employeee tto have a different id number.
    Employee(const Employee& e) : name(e.name), id(++incrementer) {}
    Employee& operator=(const Employee&);

    string getName() { return name; }
    unsigned int getId() { return id; }

private:
    string name;
    unsigned int id;
    static unsigned int incrementer;
};

Employee& Employee::operator=(const Employee& e) {
    name = e.name;
    id = ++incrementer;
    return *this;
}

unsigned int Employee::incrementer = 0;

int main(int argc, char* args[]) {
    Employee e1("Arthur");
    std::cout << e1.getName() << " " << e1.getId() << std::endl;
    Employee e2("Cici");
    std::cout << e2.getName() << " " << e2.getId() << std::endl;

    return 0;
}