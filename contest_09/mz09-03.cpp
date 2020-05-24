#include <iostream>
#include <map>
#include <set>

bool isterminal(char c) {
    return isdigit(c) || (c >= 'a' && c <= 'z');
}

int main() {
    bool not_shortening = true, regular = true, left = true, right = true, automat = true;
    int right_s_amnt = 0;
    std::set<char> uppers;
    std::string s1, s2;
    int s_to_ = 0, n_to_ = 0;
    while (std::cin >> s1 >> s2) {
        if (s2 != "_") {
            if (s2.size() < s1.size()) {
                not_shortening = false;
            }
            for (auto &i : s2) {
                if (i == 'S') {
                    right_s_amnt++;
                }
                //#TODO
            }
            if (s2.size() > 2) {
                automat = false;
            }
            if (s2.size() >= 2) {
                int i = 1;
                int s = s2.size();
                if (isupper(s2[0])) {
                    while (i < s && isterminal(s2[i])) {
                        i++;
                    }
                    if (i == s) { // so its left
                        right = false;
                    } else {
                        left = right = regular = automat = false;
                    }
                } else if (isupper(s2[s - 1])) {
                    i = s - 2;
                    while (i >= 0 && isterminal(s2[i])) {
                        i--;
                    }
                    if (i == -1) { // so its right
                        left = false;
                    } else {
                        left = right = regular = automat = false;
                    }
                } else {
                    i = 0;
                    while (i < s && isterminal(s2[i])) {
                        i++;
                    }
                    if (i != s) {
                        left = right = regular = automat = false;
                    }
                }
            } else {
                if (isupper(s2[0])) {
                    if (s1 == "S") {
                        uppers.insert(s2[0]);
                    } else {
                        automat = false;
                    }
                }
            }
        } else {
            if (s1 == "S") {
                s_to_++;
            } else {
                n_to_++;
                not_shortening = false;
            }
        }
    }
    if (s_to_ != 0 && right_s_amnt != 0) {
        not_shortening = false;
    }
    if (n_to_ != 0) {
        automat = false;
    }
    if (s_to_ != 0 || uppers.size() != 0) {
        if (right_s_amnt != 0 || n_to_ != 0) {
            automat = false;
        }
    }
    if (left == right && !right) {
        automat = regular = false;
    }

    if (!not_shortening && !regular) {
        std::cout << 2 << std::endl;
        return 0;
    }
    if (not_shortening && !regular) {
        std::cout << 21 << std::endl;
        return 0;
    }
    if (left && regular && !automat) {
        std::cout << 31 << std::endl;
        return 0;
    }
    if (left && automat) {
        std::cout << 311 << std::endl;
        return 0;
    }
    if (right && regular && !automat) {
        std::cout << 32 << std::endl;
        return 0;
    }
    if (right && automat) {
        std::cout << 321 << std::endl;
        return 0;
    }
    return 0;
}