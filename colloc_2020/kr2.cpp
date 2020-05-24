#include <iostream>
#include <vector>
#include <cstdint>


namespace Sample {
    template <typename T, size_t a, size_t b>
    struct Matrix {
    private:
        T arr[a][b];
    public:
        T* operator[](size_t i) const{
            return arr[i];
        }
        T* operator[](int j) {
            return arr[j];
        }

    };
}