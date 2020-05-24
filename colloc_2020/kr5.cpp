#include <iostream>
#include <vector>
#include <cstdint>
#include <thread>
uint64_t func(uint64_t value) ;

void thread (const std::vector<uint64_t> &vec, int begin, int end, uint64_t &ans) {
    ans = 0;
    while (begin != end) {
        ans += func(vec[begin]);
        begin++;
    }
}

uint64_t process(const std::vector<uint64_t> &vec, int nthr) {
    std::vector<uint64_t> ans;
    ans.resize(nthr);
    int step = vec.size() / nthr;
    int begin = 0, end = step;
    std::vector<std::thread> arr;
    for (int i = 0; i < nthr; i++) {
        if (i + 1 == nthr) {
            end = vec.size();
        }
        arr.emplace_back(thread, vec, begin, end, std::ref(ans[i]));
        begin = end;
        end += step;
    }
    for (auto &i : arr) {
        i.join();
    }
    uint64_t res{};
    for (auto &i : ans) {
        res += i;
    }
    return res;
}