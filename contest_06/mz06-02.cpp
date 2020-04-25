#include <algorithm>
#include <cmath>

template <typename T>
class Coord {
public:
    T col, row;
    Coord(T _col = 0, T _row = 0) : col{_col}, row{_row} {};
    typedef T value_type;
};

template <typename T>
auto dist (Coord<T> map, Coord<T> a, Coord<T> b) {
    T x {abs(a.col - b.col)};
    T y {abs(a.row - b.row)};
    y = std::min(y, map.row - y);
    x = std::min(x, map.col - x);
    if (x > y) {
        return x;
    }
    return y;
}