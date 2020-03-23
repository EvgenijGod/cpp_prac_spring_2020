#include <vector>
#include <cstdint>
void process(std::vector<int64_t> &vec1,  int64_t threshold) {
    int amnt = 0;
    for (auto i = vec1.rbegin(); i < vec1.rend(); ++i) {
        if (*i >= threshold) {
            ++amnt;
        }
    }
    vec1.resize(vec1.size() + amnt);
    auto j = vec1.rbegin() + amnt - 1;
    for (auto i = vec1.rbegin() + amnt; i < vec1.rend(); ++i) {
        if (*i >= threshold) {
            *j = *i;
            --j;
        }
    }
}