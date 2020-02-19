#include <iostream>
#include <iomanip>
#include <cmath>
int main()
{
    int n = 0;
    long double sq_sum = 0, sum = 0, a;
    while(std::cin>>a) {
        sq_sum += a * a;
        sum += a;
        n++;
    }
    std::cout << std::setprecision(10);
    std::cout << sum / n << std::endl;
    std::cout << sqrt(sq_sum / n - (sum  / n)* (sum / n)) << std::endl;
    return 0;
}