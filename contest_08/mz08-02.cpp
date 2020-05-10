#include <iostream>
#include <string>

bool is_wrong_sym(char c) {
    return c != '1' && c != '0' && !isspace(c);
}

std::pair<bool, bool> func (char &c, int zeros, int ones) {
    while (isspace(c) == false) {
        int tmp = 0;
        while(c == '0') {
            ++tmp;
            if(!std::cin.get(c)) {
                //std::cout << 0 << std::endl;
                return {false, true};
            }
            if (is_wrong_sym(c)) {
                return {false, false};
            }
        }
        if (tmp != zeros) {
            //std::cout << 0 << std::endl;
            return {false, false};
        }
        //got all zeros;
        tmp = 0;
        while(c == '1') {
            ++tmp;
            if(!std::cin.get(c)) {
                return {tmp == ones, true};
            }
            if (is_wrong_sym(c)) {
                return {false, false};
            }
        }
        if(tmp != ones) {
            return {false, false};
        }
    }
    return {true, false};
}


int main() {
    char c;
    if(!std::cin.get(c)) {
        return 0;
    }
    while (true) {
        while(isspace(c)) {
            if(!std::cin.get(c)) {
                return 0;
            }
        }
        //got all spaces;

        int zero_cnt = 0, unos_cnt = 0;
        bool res1 = true;
        while(c == '0') {
            ++zero_cnt;
            if(!std::cin.get(c)) {
                std::cout << 0 << std::endl;
                return 0;
            }
            if (is_wrong_sym(c)) {
                res1 = false;
            }
        }
        if (!zero_cnt) {
            res1 = false;
        }
        //got all zeros;
        while(c == '1') {
            ++unos_cnt;
            if(!std::cin.get(c)) {
                std::cout << 1 << std::endl;
                return 0;
            }
            if (is_wrong_sym(c)) {
                res1 = false;
            }
        }
        if (!unos_cnt) {
            res1 = false;
        }
        //got all unos;
        if (res1 == false) {
            std::cout << 0 << std::endl;
            while(!isspace(c) || is_wrong_sym(c)) {
                if(!std::cin.get(c)) {
                    return 0;
                }
            }
        } else {
            auto res = func(c, zero_cnt, unos_cnt);
            if (res.first) {
                std::cout << 1 << std::endl;
            } else {
                std::cout << 0 << std::endl;
                while(!isspace(c) || is_wrong_sym(c)) {
                    if(!std::cin.get(c)) {
                        return 0;
                    }
                }
            }
            if (res.second) {
                return 0;
            }
        }

    }
    return 0;
};

