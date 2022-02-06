#include <string>
#include <vector>
#include <memory>
#include <iostream>

using std::vector;
using std::string;

struct destination {
    unsigned id;
    explicit destination(unsigned des_id = 0) : id(des_id) {}
};

struct connection {
    destination *dest;
};

connection connect(destination *d) {
    connection new_conn;
    new_conn.dest = d;
    std::cout << "The new connection is connected to " << new_conn.dest->id << std::endl;
    return new_conn;
}

void disconnect(connection *p) {
    std::cout << "Stop connection to " << p->dest->id << std::endl;
}

void end_connection(connection *p) {
    disconnect(p);
}

void f(destination &dest) {
    connection c = connect(&dest);
    std::shared_ptr<connection> p(&c, end_connection);
    std::cout << "Using connection: " << p->dest->id << std::endl;
}

int main() {
    destination dest(5);
    f(dest);
    return 0;
}