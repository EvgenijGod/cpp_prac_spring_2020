#include <iostream>
#include <vector>
#include <cstdint>

void process(std::vector<uint64_t>&v, unsigned s) {
    if (v.empty()) {
        return;
    }
    std::vector<uint64_t> ans;
    uint64_t res = 0;
    for (size_t i = 0; i < v.size(); i++) {
        if (i != 0 && i % s == 0) {
            ans.push_back(res);
        }
        ans.push_back(v[i]);
        res += v[i];
    }
    if (v.size() % s == 0) {
        ans.push_back(res);
    }
    v = ans;
}