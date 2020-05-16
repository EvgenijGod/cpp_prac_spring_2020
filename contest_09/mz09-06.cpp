#include <iostream>
#include <string>
#include <map>
#include <set>

int main() {
    std::map<std::string, std::map<char, std::string>> p;
    std::set<std::string> ends;
    std::string a, state;
    char c;
    while(true) {
        std::cin >> a;
        if (a == "END") {
            break;
        }
        std::cin >> c >> state;
        auto it = p.find(a);
        if (it == p.end()) {
            p.insert({a, std::map<char, std::string>{{c, state}}});
        } else {
            it->second.insert({c, state});
        }
    }
    std::cin >> a;
    do {
        ends.insert(a);
        std::cin >> a;
    } while (a != "END");
    std::cin >> state;
    std::string err_str = "";
    unsigned num{};
    bool correct_word = true;
    while (std::cin.get(c) && isspace(c)) {}
    do {
        if (isspace(c)) {
            break;
        }
        auto &it = p.find(state)->second;
        auto edge = it.find(c);
        if (edge == it.end()) {
            correct_word = false;
            break;
        } else {
            state = edge->second;
        }
        num++;
    } while (std::cin.get(c));
    if (ends.find(state) == ends.end()) {
        correct_word = false;
    }
    std::cout << correct_word << std::endl;
    std::cout << num << std::endl;
    std::cout << state << std::endl;
    return 0;
}