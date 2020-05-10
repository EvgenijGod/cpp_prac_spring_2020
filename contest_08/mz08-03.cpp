#include <iostream>
#include <string>
#include <cctype>

std::pair<int, bool> check_left(std::string &s) {
    int s_count{};
    bool incorrect = true;
    for (auto &i : s) {
        if (isupper(i)) {
            incorrect = false;
        }
    }
    if (s == "S") {
        s_count = 1;
    }
    return {s_count, incorrect};
}

int main() {
    std::string s1, s2;
    int start_with_s{};
    bool makes_smaller = false, not_ks = false, incorrect = false;
    while (std::cin >> s1 >> s2) {
        auto res = check_left(s1);
        start_with_s += res.first;
        if (!incorrect) {
            incorrect = res.second;
        }
        if (s1.size() > 1 || !isupper(s1[0])) {
            not_ks = true;
        }
        if (s2[0] == '_' && s2.size() == 1) {
            makes_smaller = true;
        }
    }
    if (incorrect || start_with_s == 0) {
        std::cout << -1 << std::endl;
        return 0;
    }
    if (not_ks) {
        std::cout << 10 << std::endl;
    } else {
        if (makes_smaller) {
            std::cout << 2 << std::endl;
            return 0;
        }
        std::cout << 23 << std::endl;
    }
    return 0;
}