#include <iostream>

class Sum {
    long long sum = 0;
public:
    Sum(long long a, long long b) : sum{a + b} {}
    Sum(Sum a, long long b) : sum(a.get() + b) {}
    long long get() const{
        return sum;
    }
};