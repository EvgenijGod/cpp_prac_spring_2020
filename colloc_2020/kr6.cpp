#include <iostream>
#include <vector>
#include <cstdint>


enum STATES
{
    S,
    A,
    B,
    SH,
    BC,
    H,
    WA
};
int main() {
    STATES state = S;
    char c;
    while (std::cin.get(c)) {
        if (isspace(c) == false) {
            switch (state) {
                case S: {
                    if (c == 'a') {
                        state = A;
                    } else if (c == 'b') {
                        state = B;
                    } else {
                        state = WA;
                    }
                    break;
                }
                case A: {
                    if (c == 'a') {
                        state = S;
                    } else if (c == 'b') {
                        state = H;
                    } else if (c == 'c'){
                        state = BC;
                    } else {
                        state = WA;
                    }
                    break;
                }
                case B: {
                    if (c == 'a') {
                        state = S;
                    } else {
                        state = WA;
                    }
                    break;
                }
                case BC: {
                    if (c == 'a') {
                        state = SH;
                    } else if (c == 'b') {
                        state = B;
                    } else {
                        state = WA;
                    }
                    break;
                }
                case SH: {
                    if (c == 'a') {
                        state = A;
                    } else if (c == 'b') {
                        state = B;
                    } else {
                        state = WA;
                    }
                    break;
                }
                case H: {
                    state = WA;
                    break;
                }
                case WA:{
                    break;}
            }
        }
    }
    if (state == H || state == SH) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
    return 0;
}