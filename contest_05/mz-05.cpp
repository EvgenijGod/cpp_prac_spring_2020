#include <cmath>
#include <memory>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>


class Figure {
public:
    virtual double get_square() const { return 0; };

    virtual std::string to_string() const { return ""; };

    virtual ~Figure() = default;
};

class Circle : public Figure {
    double r;
public:
    static Circle *make(const std::string &s) {
        std::stringstream str(s);
        double r;
        str >> r;
        return new Circle(r);
    }

    double get_square() const override {
        return M_PI * r * r;
    }

    std::string to_string() const override {
        return "C " + std::to_string(r);
    }

    explicit Circle(double rr) : r{rr} {};
};

class Rectangle : public Figure {
    double a, b;
public:
    static Rectangle *make(const std::string &s) {
        std::stringstream str(s);
        double a, b;
        str >> a >> b;
        return new Rectangle(a, b);
    }

    double get_square() const override {
        return a * b;
    }

    std::string to_string() const override {
        return "R " + std::to_string(a) + " " + std::to_string(b);
    }

    explicit Rectangle(double a, double b) : a{a}, b{b} {};
};

class Square : public Figure {
    double r;
public:
    static Square *make(const std::string &s) {
        std::stringstream str(s);
        double a;
        str >> a;
        return new Square(a);
    }

    double get_square() const override {
        return r * r;
    }

    std::string to_string() const override {
        return "S " + std::to_string(r);
    }

    explicit Square(double rr) : r{rr} {};
};


class Singleton {
public:
    static Singleton &factory_instance() {
        static Singleton tmp;
        return std::ref(tmp);
    }

    static Figure *singleton_make(const std::string &s) {
        std::string tmp1, tmp2 = {}, type;
        std::stringstream str(s);
        str >> type >> tmp1;
        if (type == "R") {
            str >> tmp2;
        }
        tmp1 += " " + tmp2;
        if (type == "R") {
            return Rectangle::make(tmp1);
        }
        if (type == "S") {
            return Square::make(tmp1);
        }
        return Circle::make(tmp1);
    }

private:
    Singleton() {};

    Singleton(const Singleton &) = default;

    Singleton &operator=(const Singleton &) = default;
};

int main() {
    Singleton &maker = Singleton::factory_instance();
    std::vector<std::unique_ptr<Figure>> v;
    std::string s;
    while (std::getline(std::cin, s)) {
        v.emplace_back(std::unique_ptr<Figure>(maker.singleton_make(s)));
    }

    std::stable_sort(v.begin(), v.end(), [](const std::unique_ptr<Figure> &t1, const std::unique_ptr<Figure> &t2) {
        return t1->get_square() < t2->get_square();
    });

    for (auto i = v.begin(); i != v.end(); ++i) {
        std::cout << (*i)->to_string() << std::endl;
    }
    return 0;
}