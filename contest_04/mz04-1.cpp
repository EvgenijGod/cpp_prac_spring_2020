template<typename T>
auto process(const T& vec) {
    constexpr int maxx = 3;
    int j = 0;
    typename T::value_type sum{};
    for (auto i = vec.crbegin(); j < maxx && i != vec.crend(); ++i) {
        ++j;
        sum += *i;
        ++i;
        if (i == vec.crend()) {
            return sum;
        }
    }
    return sum;
}