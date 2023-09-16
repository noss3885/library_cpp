
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

// 素数判定
bool isprime(int n) {
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return n != 1;
}

// 約数の列挙
vector<int> divisor(int n) {
    vector<int> res;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i);
        }
    }
    return res;
}

// 素因数分解
map<int, int> prime_factor(int n) {
    map<int, int> res;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ++res[i];
            n /= i;
        }
    }
    if (n != 1) res[n] = 1;
    return res;
}

// エラトステネスの篩
vector<bool> IsPrime;
vector<int> primes;

void sieve(int max) {
    IsPrime.resize(max + 1, true);
    IsPrime[0] = IsPrime[1] = false;
    for (int i = 2; i * i <= max; ++i) {
        if (IsPrime[i]) {
            for (int j = i * i; j <= max; j += i) IsPrime[j] = false;
        }
    }
    for (int i = 0; i <= max; ++i)
        if (IsPrime[i]) primes.push_back(i);
}

// 高速素因数分解
vector<int> min_factor;

void f_sieve(int max) {
    IsPrime.resize(max + 1, true);
    min_factor.resize(max + 1, 0);
    IsPrime[0] = IsPrime[1] = false;
    min_factor[1] = 1;
    for (int i = 2; i <= max; ++i)
        if (IsPrime[i]) {
            primes.push_back(i);
            for (ll j = ll(i) * i; j <= max; j += i) {
                IsPrime[j] = false;
                min_factor[j] = i;
            }
        }
}

map<int, int> fast_prime_factor(int n) {
    map<int, int> res;
    while (n > 1) {
        int factor = min_factor[n];
        res[factor]++;
        n /= factor;
    }
    return res;
}