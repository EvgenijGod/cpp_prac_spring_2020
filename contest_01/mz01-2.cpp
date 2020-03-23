#include <iostream>

class A {
    int a;
    bool c = true;
public:
    A(){
        std::cin >> a;
    }
    A(A& b) : c(b.c){
        b.c = false;
        std::cin >> a;
        a += b.a;
    }
    ~A(){
        if(c == true) {
            std::cout << a << std::endl;
        }
    }
};