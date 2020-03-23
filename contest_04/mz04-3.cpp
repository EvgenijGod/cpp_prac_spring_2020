#include <vector>
#include <functional>

template<typename T1, typename F>
auto myapply(T1 it1, T1 it2, F f) {
    while (it1 != it2) {
        f(*it1);
        ++it1;
    }
}

template<typename T1, typename F>
auto myfilter2(T1 it1, T1 it2, F f) {
    std::vector<std::reference_wrapper<typename T1::value_type>> ans;
    while (it1 != it2) {
        if (f(*it1)) {
            ans.insert(ans.end(), *it1);
        }
        it1++;
    }
    return ans;
}

template<typename T1, typename F>
auto myfilter2(T1 *it1, T1 *it2, F f) {
    std::vector<std::reference_wrapper<T1>> ans;
    while (it1 != it2) {
        if (f(*it1)) {
            ans.insert(ans.end(), *it1);
        }
        it1++;
    }
    return ans;
}