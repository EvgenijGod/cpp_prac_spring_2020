#include <iostream>
#include <vector>
void process(const std::vector<uint64_t> &vec1, std::vector<uint64_t> &ans, int step) {
    auto j = ans.rbegin();
    for (auto i = vec1.cbegin(); i != vec1.cend() && j != ans.rend(); i+=step, ++j) {
        *j += *i;
        if (std::distance(i , vec1.cend()) <= step) {
            break;
        }
    }
}
