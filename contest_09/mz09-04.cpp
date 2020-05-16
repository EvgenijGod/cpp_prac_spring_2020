#include <iostream>
#include <string>
/*
 * S = aXd
 * X = bYc | aXd
 * Y = bYc | eps
 */
void Y (int n, int m) {
    if (n != 0) {
        Y(n - 1, m + 1000);
    } else {
        std::cout << std::string(m % 1000, 'a') + std::string(m / 1000, 'b') + std::string(m / 1000, 'c')
                     + std::string(m % 1000, 'd') << std::endl;
    }
}

void X(int n, int m) {
    if (n != 0) {
        X(n - 1, m + 1);
        Y(n - 1, m + 1000);
    }
}

void S(int n, int m) {
    X(n - 1, m + 1);
}

int main() {
    int k;
    std::cin >> k;
    if (k >= 4 && k % 2 == 0) {
        S(k / 2, 0);
    }
    return 0;
}