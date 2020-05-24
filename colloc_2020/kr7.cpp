#include <iostream>
#include <vector>
#include <cstdint>
#include <thread>

class maker {
    char c;
    void gc() {
        bool read = true;
        while(std::cin.get(c)) {
            if (!isspace(c)) {
                read = false;
                break;
            }
        }
        if (read) {
            c = '#';
        }
        //std::cout << "got " << c << "\n";
    }

    void S() {
        if (c == 'a') {
            gc();
            A();
            if (c == 'b') {
                gc();
            } else {
                throw c;
            }
        } else if (c == 'c'){
            gc();
            B();
        } else {
            throw c;
        }
    };

    void A() {
        if (c == 'e') {
            gc();
        } else if (c == 'c') {
            gc();
            A();
            if (c == 'd') {
                gc();
            } else {
                throw c;
            }
        } else {
            throw  c;
        }
    }

    void B() {
        if (c == 'b') {
            gc();
            B();
        } else if (c == 'd') {
            gc();
        } else if (c != '#'){
            throw c;
        }
    }

public:
    void make() {
        try {
            gc();
            S();
            if (c != '#') {
                throw c;
            }
            std::cout << 1 << std::endl;
        } catch (...) {
            std::cout << 0 << std::endl;
        }

    }
};

int main() {
    maker A{};
    A.make();
}