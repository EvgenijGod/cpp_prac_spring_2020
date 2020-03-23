#include <vector>
#include <algorithm>

template <typename D, typename T>
auto myremove(D begin, D end, T first, T last) {
    std::vector<int> tmp;
    while(begin != end) {
        tmp.push_back(*begin);
        begin++;
    }
    if (tmp.empty()) {
        return last;
    }
    tmp.push_back(-1);
    tmp.push_back(last - first);
    std::sort(tmp.begin(), tmp.end());
    auto last_my = std::unique(tmp.begin(), tmp.end());
    auto jj = tmp.begin();
    while(*jj != -1) {
        jj++;
    }
    int size = last - first;
    auto j = first;
    for (auto i = jj + 1; i != last_my; i++) {
        if (*i > size) {
            break;
        }
        auto left = first + *(i - 1) + 1;
        auto right = first + *i;
        while (left != right) {
            std::swap(*j , *left);
            left++;
            j++;
        }
    }
    return j;
}