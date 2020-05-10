#include <iostream>
#include <string>

class My_class {
public:
    long long res;

    explicit My_class(long long res) : res{res} {}

    ~My_class() = default;
};

void func(long long a, long long b, unsigned k) {
    if (k == 0) {
        throw My_class(a + b);
    }
    if (b == 1 && k > 0) {
        throw My_class(a);
    }
    try {
        func(a, b - 1, k);
    } catch (const My_class &tmp) {
        func(a, tmp.res, k - 1);
    }
}

int main() {
    long long a, b;
    unsigned k;
    while (std::cin >> a >> b >> k) {
        try {
            func(a, b, k);
        } catch (const My_class &tmp) {
            std::cout << tmp.res << std::endl;
        }
    }
    return 0;
}