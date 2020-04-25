#include <algorithm>
#include <vector>
#include <array>
#include <cmath>
#include <complex>

namespace Equations {
    template <typename T>
    auto quadratic (std::array<T, 3> v) { //c, b, a
        T a = v[2], b = v[1], c = v[0];
        std::vector<T> ans;
        constexpr T zero {}, two {2, 0}, four (4, 0);
        if (b == zero && a == zero) {
            return std::make_pair(!(c == zero), ans);
        }
        if (a == zero) {
            ans.emplace_back(-c/b);
        } else {
            T disc = std::sqrt(b * b - four * a * c);
            ans.emplace_back((-b - disc) / (two * a));
            ans.emplace_back((-b + disc) / (two * a));
        }
        return std::make_pair(true, ans);
    }
}