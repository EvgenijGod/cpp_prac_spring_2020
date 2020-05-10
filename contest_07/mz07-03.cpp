#include <iostream>

class S {
    int res;
    bool read, contains;
public:
    S(): res{0}, read{false}, contains(false){
        if(std::cin >> res) {
            read = contains = true;
        }
    }
    S(S &&tmp) : res{tmp.res}, read{false}, contains{tmp.contains}  {
        int res1;
        if(std::cin >> res1) {
            res += res1;
            read = true;
        }
    }
    operator bool() const {
        return read;
    }
    ~S() {
        if (!read && contains) {
            std::cout << res << std::endl;
        }
    }
};