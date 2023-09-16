#include <bits/stdc++.h>
using namespace std;

// N=1e8 150ms
// N=1e9 1500ms

// BEGIN

constexpr uint64_t MAX_N = 1e8 + 5;
constexpr uint32_t b64 = 6;

uint64_t flag[MAX_N];

void reset_flag(uint64_t i) {
    flag[i >> b64] &= ~(1ULL << (i & ((1ULL << b64) - 1)));
}

bool get_flag(uint64_t i) {
    return (flag[i >> b64] >> (i & ((1ULL << b64) - 1))) & 1;
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2)
        return true;
    else
        return n & 1 && get_flag(n / 2);
}

void sieve(const int64_t n) {
    const uint64_t siz = n / 2, sqrtN = ceil(sqrt(n) + 0.1) / 2;
    const uint64_t B = 1 << 20;
    fill(flag, flag + (siz >> b64) + 1, -1);
    for (uint64_t l = 1; l <= siz; l += B) {
        const uint64_t r = min(l + B, siz), sqrtR = ceil(sqrt(r * 2 + 1) + 0.1) / 2;
        for (uint64_t i = 1; i <= sqrtR; ++i) {
            if (get_flag(i)) {
                const uint64_t p = 2 * i + 1;
                uint64_t s;
                if (l < 2 * i * (i + 1))
                    s = 2 * i * (i + 1);
                else if ((2 * l + 1) % p == 0)
                    s = l;
                else {
                    s = (2 * l + 1) - (2 * l + 1) % p + p;
                    if (s % 2 == 0) s += p;
                    s /= 2;
                }
                for (uint64_t j = s; j <= r; j += p) {
                    reset_flag(j);
                }
            }
        }
    }
}

// END

// simple ver.
// N=1e8 150ms
// N=1e9 3500ms
/*
void sieve(const int64_t n){
    const uint64_t siz = n/2, sqrtN = ceil(sqrt(n)+0.1)/2;
    fill(flag, flag+(siz>>b64)+1, -1);
    for(uint64_t i=1; i<=sqrtN; ++i){
        if(get_flag(i)){
            const uint64_t p = 2*i+1;
            for(uint64_t j = 2*i*(i+1); j<=siz; j+=p){
                reset_flag(j);
            }
        }
    }
}
*/

// TEST
int main() {
    int N = 1e8;
    sieve(N);

    // 素数カウント
    int cnt = 1;
    for (int i = 3; i <= N; i += 2) {
        if (isPrime(i)) cnt++;
    }
    cout << cnt << endl;

    return 0;
}
