#include <iostream>
#include <cmath>

namespace  Game {
    template <typename T>
    class Coord {
    public:
        T col, row;
        Coord(T _col = 0, T _row = 0) : col{_col}, row{_row} {};
        typedef T value_type;
    };

    template <typename T>
    auto dist (Coord<T> map, Coord<T> a, Coord<T> b) {
        T x {abs(b.row - a.row)};
        T y {abs(a.col - b.col)};
        T tmp = 0;
        if (b.row != a.row && b.col < a.col && x % 2 == 1 && a.row % 2 == 1) {
            tmp = 2;
        }
        if (b.col > a.col && b.row != a.row && x % 2 == 1 && a.row % 2 == 0 ) {
            tmp = 2;
        }
        T ans = x + y;
        if (y - (x + tmp) / 2 > 0) {
            return ans - (x + tmp) / 2;
        }
        return x;
    }
}
