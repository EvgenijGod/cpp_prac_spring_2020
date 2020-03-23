#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdint>
#include <iomanip>

class functor{
    double sum = 0;
    size_t n;
public:
    functor(size_t n = 0) : sum(), n(n) {};
    void operator()(double tmp) {
        sum += tmp;
    }
    void get_ans() {
        std::cout << std::fixed << std::setprecision(10) << sum / n << std::endl;
    }
};
int main() {
    std::vector<double> numbers;
    double tmp;
    while (std::cin >> tmp) {
        numbers.emplace_back(tmp);
    }
    size_t c = numbers.size() / 10;
    auto begin = numbers.begin() + c;
    auto end = numbers.end() - c;
    std::sort(begin, end);
    c = (end - begin) / 10;
    begin += c;
    end -= c;
    functor f(end - begin);
    f = std::for_each(begin, end, f);
    f.get_ans();
    return 0;
}