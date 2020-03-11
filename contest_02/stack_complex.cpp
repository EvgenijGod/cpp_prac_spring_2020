#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <map>
#include <functional>

namespace numbers {
    class complex {
        double re_{}, im_{};
    public:
        double abs() const {
            return sqrt(im_ * im_ + re_ * re_);
        }

        double abs2() const {
            return im_ * im_ + re_ * re_;
        }

        complex(double a = 0, double b = 0) : re_(a), im_(b) {}

        explicit complex(std::string a) {
            std::stringstream str(a);
            char c;
            str >> c >> re_ >> c >> im_;
        }

        double re() const { return re_; }

        double im() const { return im_; }

        std::string to_string() const {
            char buffer[300] = "";
            snprintf(buffer, 299, "(%.10g,%.10g)", re_, im_);
            return std::string(buffer);
        }

        complex &operator+=(const complex &tmp) {
            im_ += tmp.im();
            re_ += tmp.re();
            return *this;
        }

        complex &operator-=(const complex &tmp) {
            im_ -= tmp.im();
            re_ -= tmp.re();
            return *this;
        }

        complex &operator*=(const complex &tmp) {
            double tmp_re = tmp.re() * re_ - im_ * tmp.im();
            double tmp_im = tmp.im() * re_ + im_ * tmp.re();
            re_ = tmp_re;
            im_ = tmp_im;
            return *this;
        }

        complex &operator/=(const complex &tmp) {
            double tmp_re = (tmp.re() * re_ + im_ * tmp.im()) / tmp.abs2();
            double tmp_im = (-tmp.im() * re_ + im_ * tmp.re()) / tmp.abs2();
            re_ = tmp_re;
            im_ = tmp_im;
            return *this;
        }

        const complex operator~() const {
            return complex(re_, -im_);
        }

        const complex operator-() const {
            return complex(-re_, -im_);
        }

        friend const complex operator+(const complex &tmp1, const complex &tmp) {
            complex ans(tmp1.re(), tmp1.im());
            ans += tmp;
            return ans;
        }

        friend const complex operator-(const complex &tmp1, const complex &tmp) {
            complex ans(tmp1.re(), tmp1.im());
            ans -= tmp;
            return ans;
        }

        friend const complex operator*(const complex &tmp1, const complex &tmp) {
            complex ans(tmp1.re(), tmp1.im());
            ans *= tmp;
            return ans;
        }

        friend const complex operator/(const complex &tmp1, const complex &tmp) {
            complex ans(tmp1.re(), tmp1.im());
            ans /= tmp;
            return ans;
        }
    };

    constexpr size_t STACK_SIZE = 16;

    class complex_stack {
        complex *_stack = nullptr;
        size_t _size = STACK_SIZE;
        size_t _cur_size = 0;
    public:
        complex_stack(size_t _size = STACK_SIZE) : _size(_size) {
            if (_size) {
                _stack = (complex *) (new char[_size * sizeof(complex)]);
            }
        }

        ~complex_stack() {
            for (size_t i = 0; i < _cur_size; i++) {
                _stack[i].~complex();
            }
            char *tmp = (char *) _stack;
            delete[] tmp;
        }

        size_t size() const {
            return _cur_size;
        }

        complex_stack(const complex_stack &tmp) : _size(tmp._size), _cur_size(tmp._cur_size) {
            char *pBuffer = new char[_size * sizeof(complex)];
            _stack = (complex *) pBuffer;
            for (size_t i = 0; i < _cur_size; i++) {
                new(_stack + i) complex(tmp._stack[i]);
            }
        }

        complex_stack &operator=(const complex_stack &tmp) {
            if (this == &tmp) {
                return *this;
            }
            for (size_t i = 0; i < _cur_size; i++) {
                _stack[i].~complex();
            }
            char *tmp_ = (char *) _stack;
            delete[] tmp_;
            _size = tmp._size;
            _cur_size = tmp._cur_size;
            char *pBuffer = new char[_size * sizeof(complex)];
            _stack = (complex *) pBuffer;
            for (size_t i = 0; i < _cur_size; i++) {
                new(_stack + i) complex(tmp._stack[i]);
            }
            return *this;
        }

        complex operator[](size_t i) const {
            return _stack[i];
        }

        complex operator+() const {
            return _stack[_cur_size - 1];
        }

        complex_stack operator~() const {
            complex_stack tmp(*this);
            tmp._cur_size--;
            tmp._stack[_cur_size].~complex();
            return tmp;
        }

        friend complex_stack operator<<(const complex_stack &tmp1, const complex &tmp2) {
            complex_stack ans(0);
            if (tmp1._cur_size + 1 == tmp1._size) {
                char *pBuffer = new char[tmp1._size * 2 * sizeof(complex)];
                ans._stack = (complex *) pBuffer;
                for (size_t i = 0; i < tmp1._size; i++) {
                    new(ans._stack + i) complex(tmp1._stack[i]);
                }
                new(ans._stack + tmp1._cur_size) complex(tmp2);
                ans._size = tmp1._size * 2;
                ans._cur_size = tmp1._cur_size + 1;
            } else {
                ans = tmp1;
                new(ans._stack + ans._cur_size) complex(tmp2);
                ans._cur_size++;
            }
            return ans;
        }
    };

    complex eval(const std::vector<std::string> &args, const complex &z) {
        complex_stack nums;
        std::map<char, std::function<void()>> operations;
        operations.insert({'+', [&]() {
            complex tmp1 = +nums;
            nums = ~nums;
            complex tmp2 = +nums;
            nums = ~nums;
            nums = nums << (tmp2 + tmp1);
        }});
        operations.insert({'-', [&]() {
            complex tmp1 = +nums;
            nums = ~nums;
            complex tmp2 = +nums;
            nums = ~nums;
            nums = nums << (tmp2 - tmp1);
        }});
        operations.insert({'*', [&]() {
            complex tmp1 = +nums;
            nums = ~nums;
            complex tmp2 = +nums;
            nums = ~nums;
            nums = nums << (tmp2 * tmp1);
        }});
        operations.insert({'/', [&]() {
            complex tmp1 = +nums;
            nums = ~nums;
            complex tmp2 = +nums;
            nums = ~nums;
            nums = nums << (tmp2 / tmp1);
        }});
        operations.insert({'!', [&]() {
            complex tmp1 = +nums;
            nums = nums << tmp1;
        }});
        operations.insert({';', [&]() {
            nums = ~nums;
        }});
        operations.insert({'~', [&]() {
            complex tmp1 = +nums;
            nums = ~nums;
            nums = nums << ~tmp1;
        }});
        operations.insert({'#', [&]() {
            complex tmp1 = +nums;
            nums = ~nums;
            nums = nums << -tmp1;
        }});
        nums = nums << z;
        for (auto i : args) {
            if (i == "z") {
                nums = nums << z;
            } else if (i[0] == '(') {
                complex tmp(i);
                nums = nums << tmp;
            } else {
                operations[i[0]]();
            }
        }
        return +nums;
    }
}

/*int main() {
    std::vector<std::string> ans;
    ans.emplace_back("(-1, 1)");
    ans.emplace_back("(2, 2)");
    ans.emplace_back("+");
    numbers::complex tmp(4, 4);
    std::cout << numbers::eval(ans, tmp).re();
    return 0;
}*/