#include <iostream>

class LCG {
private:
    unsigned long long state;
    const unsigned long long a;
    const unsigned long long c;
    const unsigned long long m;

public:
    LCG(unsigned long long seed, unsigned long long a, unsigned long long c, unsigned long long m)
        : state(seed), a(a), c(c), m(m) {}

    double random() {
        state = (a * state + c) % m;
        return static_cast<double>(state) / m;
    }
};

int main() {
    unsigned long long seed = 42;
    unsigned long long a = 1664525;
    unsigned long long c = 1013904223;
    unsigned long long m = (1ULL << 32); // 2^32
    LCG lcg(seed, a, c, m);

    for (int i = 0; i < 10; i++) {
        std::cout << lcg.random() << std::endl;
    }

    return 0;
}

