template<typename T1, typename T2>
auto myfilter(const T1& cont, T2 func) {
    T1 ans;
    for (auto i : cont) {
        if(func(i)) {
            ans.insert(ans.end(), i);
        }
    }
    return ans;
}