#include "fermat.h"

#include <vector>
#include <cassert>
#include <random>
#include <cstdint>
#include <algorithm>
#include <iostream>
#include <limits>
#include <stdexcept>

// Calculates (base ^ exponent) % mod
//In mod_exp, you don’t have to convert exponent to binary (in lecture you receive a std::vector<bool> as input). Instead, the least significant bit can be calculated as exponent % 2. The next bit is (exponent / 2) % 2, and the next is (exponent / 4) % 2, etc
std::uint32_t mod_exp(std::uint32_t base, std::uint32_t exponent, std::uint32_t mod) {
    //throw std::runtime_error{"Not implemented"};
    std::string l = std::to_string(exponent);
    int len = l.length();
    std::uint64_t x = 1;
    auto r = base % mod;
    for (int i = 0; i < len; i++) {
        if (exponent % 2 == 1) {
            x = (x * r) % mod;
        }
        r = (r * r) % mod;
        exponent = exponent / 2;
    }
}

// Perform Fermat test on n.
// You should return true only if A^(n-1) % n == 1 for every A inside the tests vector
bool fermat_test(std::uint32_t n, const std::vector<std::uint32_t>& tests) {
    // throw std::runtime_error{"Not implemented"};
    for (auto i : tests) {
        if (mod_exp(i, n - 1, n) != 1) {
            return false;
        }
    }
}
