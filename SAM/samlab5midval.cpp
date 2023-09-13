#include <iostream>
#include <cmath>
#include <iomanip>

class MidSquareRandom {
private:
    unsigned long long seed;
    unsigned long long max_value;
    unsigned long long min_digits;
    unsigned long long max_digits;

public:
    MidSquareRandom(unsigned long long initial_seed, unsigned long long digits = 4) {
        seed = initial_seed;
        min_digits = static_cast<unsigned long long>(pow(10, digits - 1));
        max_digits = static_cast<unsigned long long>(pow(10, digits) - 1);
        max_value = static_cast<unsigned long long>(pow(10, 2 * digits));
    }

    double random() {
        seed = (seed * seed) % max_value;
        unsigned long long scaled_value = min_digits + (seed % (max_digits - min_digits + 1));
        return static_cast<double>(scaled_value) / max_digits;
    }
};

int main() {
    unsigned long long seed = 1234;
    unsigned long long num_iterations = 10;
    MidSquareRandom msr(seed);

    for (unsigned long long i = 0; i < num_iterations; ++i) {
        std::cout << std::fixed << std::setprecision(4) << msr.random() << std::endl;
    }

    return 0;
}

