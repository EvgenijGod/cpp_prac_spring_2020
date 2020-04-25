#include <iostream>
#include <algorithm>
#include <cmath>

int main(int argc, char **argv)
{
    long long m, n;
    std::cin >> m >> n;
    long long r1, c1, r2, c2;

    while(std::cin >> r1) {
        std::cin >> c1 >> r2 >> c2;
        c1 = llabs(c1 - c2);
        r1 = llabs(r1 - r2);
        c1 = std::min(c1, n - c1);
        r1 = std::min(r1, m - r1);
        std::cout << c1 + r1 << std::endl;
    }

    return 0;
}