#include <iostream>
enum STATES
{
    S,
    A,
    B,
    C,
    D
};

int main() {
    std::string s;
    std::cin >> s;
    STATES state = S;
    long long pos = 0, max_pos = s.size() - 1;
    bool process = true;
    while(process) {
        switch (state) {
            case S: {
                switch (s[pos]) {
                    case '0': {
                        pos++;
                        if (pos > max_pos) {
                            process = false;
                        }
                        break;
                    }
                    case '1': {
                        s[pos] = '1';
                        pos++;
                        if (pos > max_pos) {
                            process = false;
                        }
                        state = A;
                        break;
                    }
                    case '#': {
                        pos++;
                        if (pos > max_pos) {
                            process = false;
                        }
                        break;
                    }
                }
                break;
            }
            case A: {
                switch (s[pos]) {
                    case '0': {
                        pos++;
                        if (pos > max_pos) {
                            process = false;
                        }
                        break;
                    }
                    case '1': {
                        pos++;
                        if (pos > max_pos) {
                            process = false;
                        }
                        state = S;
                        break;
                    }
                    case '#': {
                        state = B;
                        pos--;
                        if (pos < 0) {
                            process = false;
                        }
                        break;
                    }
                }
                break;
            }
            case B: {
                switch (s[pos]) {
                    case '0': {
                        pos--;
                        if (pos < 0) {
                            process = false;
                        }
                        break;
                    }
                    case '1': {
                        pos--;
                        if (pos < 0) {
                            process = false;
                        }
                        break;
                    }
                    case '#': {
                        state = C;
                        pos++;
                        if (pos > max_pos) {
                            process = false;
                        }
                        break;
                    }
                }
                break;
            }
            case C: {
                switch (s[pos]) {
                    case '0': {
                        pos++;
                        if (pos > max_pos) {
                            process = false;
                        }
                        break;
                    }
                    case '1': {
                        state = D;
                        s[pos] = '0';
                        break;
                    }
                }
                break;
            }
            case D: {
                process = false;
                break;
            }
        }
    }
    std::cout << s << std::endl;
    return 0;
}