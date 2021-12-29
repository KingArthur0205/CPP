#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::string;

class Screen {
public:
    using pos = string::size_type;
    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
    inline char get() const;
    inline char get(pos, pos) const;
    inline Screen &move(pos, pos);
    inline pos getCallCount() const;
    Screen &set(char c);
    Screen &display(std::ostream &);
    const Screen &display(std::ostream &) const;


private:
    pos cursor = 0;
    pos width = 0, height = 0;
    mutable pos call_count = 0;
    std::string contents;
    void do_Display(std::ostream &os) const {
        os << contents;
    }
};

char Screen::get() const {
    ++(this->call_count);
    return contents[cursor];
}

char Screen::get(pos r, pos c) const {
    ++(this->call_count);
    pos row = r * this->width;
    return contents[row + c];
}

Screen &Screen::move(pos r, pos c) {
    ++(this->call_count);
    pos row = r * width;
    this->cursor = row + c;
    return *this;
}

Screen::pos Screen::getCallCount() const {
    return this->call_count;
}

inline Screen &Screen::set(char c) {
    this->contents[cursor] = c;
    return *this;
}

inline Screen &Screen::display(std::ostream &os) {
    do_Display(os);
    return *this;
}

inline const Screen &Screen::display(std::ostream &os) const {
    do_Display(os);
    return *this;
}