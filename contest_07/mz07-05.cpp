#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/date_parsing.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>

int main() {
    boost::gregorian::date first, second;
    boost::gregorian::days tmp;
    boost::date_time::months_of_year set[12] = {
            boost::gregorian::Jan,
            boost::gregorian::Feb,
            boost::gregorian::Mar,
            boost::gregorian::Apr,
            boost::gregorian::May,
            boost::gregorian::Jun,
            boost::gregorian::Jul,
            boost::gregorian::Aug,
            boost::gregorian::Sep,
            boost::gregorian::Oct,
            boost::gregorian::Nov,
            boost::gregorian::Dec
    };
    std::uint64_t res{};
    std::string s;
    std::cin >> s;
    std::vector<std::string> tokens;
    boost::split(tokens, s, boost::is_any_of("-"));
    second = boost::gregorian::date(
            std::stoull(tokens[0]),
            set[std::stoull(tokens[1]) - 1],
            std::stoull(tokens[2]));
    while(std::cin >> s) {
        std::vector<std::string> token;
        boost::split(token, s, boost::is_any_of("-"));
        first = boost::gregorian::date(
                std::stoull(token[0]),
                set[std::stoull(token[1]) - 1],
                std::stoull(token[2]));
        tmp = second - first;
        std::swap(first, second);
        res += std::llabs(tmp.days());
    }
    std::cout << res << std::endl;
    return 0;
}