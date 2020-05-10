#include <iostream>
#include <string>

int func (const std::string &s) {
    int epoch = 0;
    for (auto &i : s) {
        if (i == '3' || i == '4') {
            if (epoch != 0) {
                return 0;
            }
        } else if (i == '1' || i == '2') {
            if (epoch == 0) {
                epoch = 1;
            }
        } else {
            return 0;
        }
    }
    return 1;
}

int main() {
    std::string s;
    while (std::cin >> s) {
        std::cout << func(s) << std::endl;
    }
    return 0;
};