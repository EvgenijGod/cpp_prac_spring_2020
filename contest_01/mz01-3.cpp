#include <iostream>

class Sub {
    int sum = 0;
public:
    Sub(int a, int b) : sum{a - b} {}
    Sub(Sub a, int b) : sum(a.value() - b) {}
    Sub(int a, Sub b) : sum(-b.value() + a) {}
    int value() const{
        return sum;
    }
};