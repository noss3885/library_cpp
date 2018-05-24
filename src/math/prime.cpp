
#include <vector>
#include <map>

using namespace std;

//素数判定
bool is_prime(int n) {
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return n != 1;
}

//約数の列挙
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

//素因数分解
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

//エラトステネスの篩
vector<bool> IsPrime;

void sieve(size_t max) {
    if (max + 1 > IsPrime.size()) {
        IsPrime.resize(max + 1, true);
    }
    IsPrime[0] = false;
    IsPrime[1] = false;
    for (size_t i = 2; i * i <= max; ++i)
        if (IsPrime[i])
            for (size_t j = 2; i * j <= max; ++j) IsPrime[i * j] = false;
}