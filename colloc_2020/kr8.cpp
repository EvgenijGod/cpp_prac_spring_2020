#include <iostream>
#include <string>
#include <cstdint>


std::string gen_power(uint32_t power) {
    if (power == 0) {
        return "1";
    } else {
        return std::string(power, 'x') + std::string(power - 1, '*');
    }
}