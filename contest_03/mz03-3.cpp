#include <iostream>
#include <vector>
#include <algorithm>
void process(const std::vector<int> &vec1, std::vector<int> &vec2) {
    if (vec1.empty()) {
        return;
    }
    std::vector<int> tmp = vec1;
    tmp.push_back(-1);
    tmp.push_back(vec2.size());
    std::sort(tmp.begin(), tmp.end());
    auto last = std::unique(tmp.begin(), tmp.end());
    auto jj = tmp.begin();
    while(*jj != -1) {
        jj++;
    }
    int size = vec2.size();
    auto j = vec2.begin();
    for (auto i = jj + 1; i != last; i++) {
        if (*i > size) {
            break;
        }
        auto left = vec2.begin() + *(i - 1) + 1;
        auto right = vec2.begin() + *i;
        while (left != right) {
            *j = *left;
            left++;
            j++;
        }
    }
    vec2.erase(j, vec2.end());
}

