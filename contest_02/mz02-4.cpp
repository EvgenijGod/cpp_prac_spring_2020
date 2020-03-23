#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <climits>
#include "cmc_complex.h"
#include "cmc_complex_stack.h"
#include "cmc_complex_eval.h"


int main(int argc, char*argv[]) {
    numbers::complex c((std::string(argv[1])));

    double r;
    int n;
    std::vector<std::string> args;
    std::stringstream str((std::string(argv[2])));
    str >> r;
    str.clear();
    str.str(std::string(argv[3]));
    str >> n;
    for (int i = 4; i < argc; i++) {
        args.emplace_back(argv[i]);
    }
    //std::cout << n << std::endl;
    numbers::complex ans(0, 0);
    if (n != 0) {
        double angle = M_PI / n, ang_left = 0, ang_right = (M_PI * 2) / n, step = (M_PI * 2) / n;
        for (int i = 0; i < n; i++) {
            numbers::complex a(c.re() + r * cos(ang_left), c.im() + r * sin(ang_left));
            numbers::complex b(c.re() + r * cos(ang_right), c.im() + r * sin(ang_right));
            numbers::complex num(c.re() + r * cos(angle), c.im() + r * sin(angle));
            ans += numbers::eval(args, num) * (b - a);
            angle += step;
            ang_left += step;
            ang_right += step;
        }
    }
    std::cout << ans.to_string() << std::endl;
    return 0;
}