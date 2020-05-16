#include <iostream>
#include <string>

/*
 S = AOBI
 A = Aax | ax
 O = O0y | 0y
 ax = xa
 x0 = 0x
 xy = yx
 xB = Bb | b
 y0 = 0y
 yb = by
 yI = I1 | 1
 */

enum STATES
{
    A,
    O,
    B,
    I,
    WA
};
int main() {
    std::string s;
    while (std::cin >> s) {
        STATES state = A;
        int a = 0, zeros = 0, b = 0, ones = 0;
        for (auto &i : s) {
            if (state == WA) {
                break;
            }
            switch (state) {
                case A: {
                    if (i == 'a') {
                        a++;
                    } else if (i == '0') {
                        zeros++;
                        state = O;
                    } else {
                        state = WA;
                    }
                    break;
                }
                case O: {
                    if (i == '0') {
                        zeros++;
                    } else if (i == 'b') {
                        b++;
                        state = B;
                    } else {
                        state = WA;
                    }
                    break;
                }
                case B: {
                    if (i == 'b') {
                        b++;
                    } else if (i == '1') {
                        ones++;
                        state = I;
                    } else {
                        state = WA;
                    }
                    break;
                }
                case I: {
                    if (i == '1') {
                        ones++;
                    } else {
                        state = WA;
                    }
                    break;
                }
                case WA:
                    break;
            }
        }
        if (state != WA && ones == zeros && a == b && a > 0 && ones > 0) {
            std::cout << 1 << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
    }
    return 0;
}