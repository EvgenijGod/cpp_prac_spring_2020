#include <iostream>
#include <string>

enum STATES
{
    H,
    AB,
    A,
    AC,
    S,
    ABC,
    WA
};
int main() {
    std::string s;
    while (std::cin >> s) {
        STATES state = H;
        size_t last = s.size(), now = 0;
        for (auto &i : s) {
            now++;
            if (state == WA) {
                break;
            }
            switch (state) {
                case A:
                case H: {
                    if (i == '1') {
                        state = AB;
                    } else if (i == '0') {
                        state = A;
                    } else {
                        state = WA;
                    }
                    break;
                }
                case AB: {
                    if (i == '1') {
                        state = ABC;
                    } else if (i == '0') {
                        state = AC;
                    } else {
                        state = WA;
                    }
                    break;
                }
                case ABC: {
                    if (i == '1') {
                        if (now == last) {
                            state = S;
                        } else {
                            state = ABC;
                        }
                    } else if (i == '0') {
                        if (now == last) {
                            state = S;
                        } else {
                            state = AC;
                        }
                    } else {
                        state = WA;
                    }
                    break;
                }
                case AC: {
                    if (i == '1') {
                        if (now == last) {
                            state = S;
                        } else {
                            state = AB;
                        }
                    } else if (i == '0') {
                        if (now == last) {
                            state = S;
                        } else {
                            state = A;
                        }
                    } else {
                        state = WA;
                    }
                    break;
                }
                case S: {
                    state = WA;
                    break;
                }
                case WA: break;
            }
        }
        if (state == S) {
            std::cout << 1 << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
    }
    return 0;
}