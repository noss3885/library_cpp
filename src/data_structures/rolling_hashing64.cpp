/*
ローリングハッシュ(2^64)
連続する部分文字列の比較を高速に行える。
unsigned long long を使っているので
簡潔で高速だが衝突が起きやすい。
構築 O(N)
判定 O(1)
*/

#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<ull> powb, rhash;

void rolling_hash(string str, ull base = ull(1e9 + 7)) {
    int N = str.size();
    powb.resize(N + 1);
    rhash.resize(N + 1);
    powb[0] = 1;
    rhash[0] = 0;
    for (int i = 0; i < N; i++) {
        rhash[i + 1] = str[i] + rhash[i] * base;
        powb[i + 1] = powb[i] * base;
    }
}

//[l,r)
ull get_hash(int l, int r) { return rhash[r] - rhash[l] * powb[r - l]; }
