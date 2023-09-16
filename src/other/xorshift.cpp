#include <bits/stdc++.h>
using namespace std;

// 周期 2^128-1
uint32_t xorshift(void) {
    static uint32_t x = 123456789;
    static uint32_t y = 362436069;
    static uint32_t z = 521288629;
    static uint32_t w = 88675123;
    uint32_t t;

    t = x ^ (x << 11);
    x = y;
    y = z;
    z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

struct Random {
    using uint = unsigned int;
    uint x = 123456789;
    uint y = 362436069;
    uint z = 521288629;
    uint w = 88675123;
    uint t;

    uint rand() {
        t = x ^ (x << 11);
        x = y;
        y = z;
        z = w;
        return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
    }
    // [0,1)
    double randFloat() {
        return static_cast<double>(rand() % 0x10000) / static_cast<double>(0x10000);
    }
    // [aMin,aMax)
    double randFloat(double aMin, double aMax) {
        return aMin + randFloat() * (aMax - aMin);
    }
    void spin(int n) {
        for (; n > 0; --n) (void)rand();
    }
};