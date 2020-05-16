#include <iostream>
#include <string>
#include <map>
#include <set>

int main() {
    std::multimap<char, std::string> p;
    std::set<char> v{'S'};
    std::string b;
    char a;
    while(std::cin >> a >> b) {
        p.insert({a, b});
    }
    while(true) {
        size_t sz = v.size();
        std::set<char> tmp;
        for (auto &i : v) {
            auto iter = p.find(i);
            while(iter != p.end() && iter->first == i) {
                auto res = iter->second;
                if (res != "_") {
                    for (auto &j : res) {
                        tmp.insert(j);
                    }
                }
                iter++;
            }
        }
        v.merge(tmp);
        if (sz == v.size()) {
            break;
        }
    }
    for(auto &i : p) {
        bool check = true;
        for (auto &j : i.second) {
            if (v.find(j) == v.end()) {
                check = false;
            }
        }
        if (i.second == "_") {
            check = true;
        }
        if (v.find(i.first) == v.end()) {
            check = false;
        }
        if (check) {
            std::cout << i.first << " " << i.second << std::endl;
        }
    }
    return 0;
}