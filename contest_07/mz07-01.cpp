#include <iostream>
#include <string>
class My_class {
public:
    std::string str;
    My_class(std::string str1) : str{str1} {}
    ~My_class (){
        std::cout << str << std::endl;
    }
};

void rec(int n) {
    std::string s;
    try {
        if (std::cin >> s) {
            My_class tmp(s);
            rec(n + 1);
        }
        throw 0;
    } catch (int number) {
        throw;
    }
}

int main()
{
    try {
        rec(0);
    } catch (...) {

    }
    return 0;
}